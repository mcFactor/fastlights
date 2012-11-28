/*
 * Sing is the Processing-like framework for CloudLight procedural animation
 * After the Processing language by Tom Igoe
 *
 * For the moment, the user procedural file is simply included
 * And everything is connected together at compile time
 *
 * The user procedural file should define:
 *
 * void setup(void*)
 * void loop(void*)
 *
 * And leave everything else to this framework. Hopefully.
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License.
 *
 * Cross-compile with cross-gcc -I/path/to/cross-kernel/include
 */

#include <stdint.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <getopt.h>
#include <fcntl.h>
#include <sys/ioctl.h>
#include <sys/types.h>
#include <linux/types.h>
#ifndef OLIMEX
#include <linux/spi/spidev.h>
#endif
#ifdef OLIMEX
#include "gpio-mmap.h"
#endif
#include <time.h>
#include <string.h>
#include "sing.h"
#include "singtime.h"
#include "lightnames.h"
#include "layoutloader.h"

static void pabort(const char *s)
{
    perror(s);
    abort();
}

#ifndef OLIMEX
static const char *device = "/dev/spidev0.0";
static uint32_t speed = 500000;
static uint8_t mode;
static uint16_t delay;
#endif

static uint8_t bits = 8;
uint8_t* txbuf;         // Global frame buffer
int string_size = 0;

// Each face array starts at the upper left corner,
// And completes at the lower right corner.  Hopefully.
static uint8_t top_face[ROWS_PER_FACE][COLS_PER_FACE] = {
    3,  4,  5,
    15, 16, 17,
    27, 28, 29
};

static uint8_t right_face[ROWS_PER_FACE][COLS_PER_FACE] = {
    0,  1,  2,
    12, 13, 14,
    24, 25, 26,
};

static uint8_t  bottom_face[ROWS_PER_FACE][COLS_PER_FACE] = {
    9, 10, 11,
    21, 22, 23,
    33, 34, 35
};

static uint8_t left_face[ROWS_PER_FACE][COLS_PER_FACE] = {
    6,  7,   8,
    18, 19, 20,
    30, 31, 32,
};



static uint8_t *faces[4] = {
    (uint8_t*) &top_face,
    (uint8_t*) &right_face,
    (uint8_t*) &bottom_face,
    (uint8_t*) &left_face
};

inline uint8_t get_bulb_number(int face, int row, int col)
{
    register uint8_t *thingy;
    // Maps a face, row and column to a bulb number, quickly.
    thingy = faces[face];
    return thingy[row*ROWS_PER_FACE + col];
}

static uint8_t left_inside[BULBS_INSIDE] = {
    51,50,43,42,
};

static uint8_t top_inside[BULBS_INSIDE] = {
    49,48,41,40,
};

static uint8_t right_inside[BULBS_INSIDE] = {
    47,46,39,38,
};

static uint8_t bottom_inside[BULBS_INSIDE] = {
    45,44,37,36,
};


static uint8_t *insides[4] = {
    (uint8_t*) &top_inside,
    (uint8_t*) &right_inside,
    (uint8_t*) &bottom_inside,
    (uint8_t*) &left_inside
};

inline uint8_t get_inside_bulb_number(int face, int bulb)
{
    register uint8_t *thingy;
    // Maps a face, and a bulb to a bulb number, quickly.
    thingy = insides[face];
    return thingy[bulb];
}


long sync_time = 0;

void synchronize(long since)
{
    struct timespec ts;
    int retval;
    long curr;
    int waiting = 1;

    // synchronize will exit at least since nanoseconds after the last time sync exited
    // will try to be as close as possible, given the vagaries of multitasking
    // The first time through, it will exit immediately as it has not been initialized
    // So call synchronize(1) during initialization to set things up appropriately
    //
    while (1) {
        retval = clock_gettime(CLOCK_REALTIME, &ts);
        curr = ts.tv_nsec;
        if (ts.tv_nsec < sync_time) {       // Handle wraps gracefully
            curr += 1000000000;
        }
        //////("curr %d sync_time %d diff %d\n", curr, sync_time, curr-sync_time);
        if ((curr - sync_time) >= since) {
            sync_time = ts.tv_nsec;
            return;
        } else {
            usleep(200);        // Sleep for 200 microseconds
        }
    }
}


static void send_frame(int fileDescriptor, uint8_t txbuf[], int buffsize)
{
#ifdef OLIMEX
    ////("olimex sendframe \n");
    // GPIO 65 = LED
    // GPIO 20 = SSP2_MOSI = LED DATA = OL Micro CON2 pin 10 = OL Maxi UEXT pin 8
    // GPIO 24 = SSP2_SCK = LED CLOCK = OL Micro CON2 pin 11 = OL Maxi UEXT pin 9
    GPIO_WRITE_PIN(65,1);
    uint8_t i, j, v, b;
    for (i=0; i<buffsize; i++) {
        v = txbuf[i];
        b = 0x80;
        for (j=0; j<bits; j++) {
            GPIO_WRITE_PIN(20,v&b);
            b >>= 1;
            GPIO_WRITE_PIN(24,1);
            GPIO_WRITE_PIN(24,0);
        }
    }
    GPIO_WRITE_PIN(65,0);
#else
    int ret;
    int j  = 0;
    int offset;
    uint8_t rx[385] = { 0, };
    struct spi_ioc_transfer tr = {
        .tx_buf = (unsigned long)txbuf,
        .rx_buf = (unsigned long)rx,
        .len = buffsize,
        .delay_usecs = delay,
        .speed_hz = speed,
        .bits_per_word = bits,
    };

    //////("buffsize %d\n", buffsize);
    ret = ioctl(fileDescriptor, SPI_IOC_MESSAGE(1), &tr);
    if (ret < 1)
        pabort("can't send spi message");
#endif
}


//move to lightnames.c?
int set_to_canonical(int outer, int face, int row, int col)
{
// Need to check for out-of-bounds here, but meh.
//        outer? face row col
    int outermap[NUM_FACES][ROWS_PER_FACE][COLS_PER_FACE] = {

        /* 1       3   0   0 */           CANONICAL_OUTER_RIGHT_POSTERIOR_TOP
        /* 1       3   0   1 */           ,CANONICAL_OUTER_RIGHT_POSTERIOR_CENTER
        /* 1       3   0   2 */           ,CANONICAL_OUTER_RIGHT_POSTERIOR_BOTTOM
        /* 1       3   1   0 */           ,CANONICAL_OUTER_RIGHT_CENTER_TOP
        /* 1       3   1   1 */           ,CANONICAL_OUTER_RIGHT_CENTER_CENTER
        /* 1       3   1   2 */           ,CANONICAL_OUTER_RIGHT_CENTER_BOTTOM
        /* 1       3   2   0 */           ,CANONICAL_OUTER_RIGHT_FRONT_TOP
        /* 1       3   2   1 */           ,CANONICAL_OUTER_RIGHT_FRONT_CENTER
        /* 1       3   2   2 */           ,CANONICAL_OUTER_RIGHT_FRONT_BOTTOM

        /* 1       2   0   0 */           ,CANONICAL_OUTER_BOTTOM_POSTERIOR_RIGHT
        /* 1       2   0   1 */           ,CANONICAL_OUTER_BOTTOM_POSTERIOR_CENTER
        /* 1       2   0   2 */           ,CANONICAL_OUTER_BOTTOM_POSTERIOR_LEFT
        /* 1       2   1   0 */           ,CANONICAL_OUTER_BOTTOM_CENTER_RIGHT
        /* 1       2   1   1 */           ,CANONICAL_OUTER_BOTTOM_CENTER_CENTER
        /* 1       2   1   2 */           ,CANONICAL_OUTER_BOTTOM_CENTER_LEFT
        /* 1       2   2   0 */           ,CANONICAL_OUTER_BOTTOM_FRONT_RIGHT
        /* 1       2   2   1 */           ,CANONICAL_OUTER_BOTTOM_FRONT_CENTER
        /* 1       2   2   2 */           ,CANONICAL_OUTER_BOTTOM_FRONT_LEFT
        
        /* 1       1   0   0 */           ,CANONICAL_OUTER_LEFT_POSTERIOR_BOTTOM
        /* 1       1   0   1 */           ,CANONICAL_OUTER_LEFT_POSTERIOR_CENTER
        /* 1       1   0   2 */           ,CANONICAL_OUTER_LEFT_POSTERIOR_TOP
        /* 1       1   1   0 */           ,CANONICAL_OUTER_LEFT_CENTER_BOTTOM
        /* 1       1   1   1 */           ,CANONICAL_OUTER_LEFT_CENTER_CENTER
        /* 1       1   1   2 */           ,CANONICAL_OUTER_LEFT_CENTER_TOP
        /* 1       1   2   0 */           ,CANONICAL_OUTER_LEFT_FRONT_BOTTOM
        /* 1       1   2   1 */           ,CANONICAL_OUTER_LEFT_FRONT_CENTER
        /* 1       1   2   2 */           ,CANONICAL_OUTER_LEFT_FRONT_TOP

        /* 1       0   0   0 */           ,CANONICAL_OUTER_TOP_POSTERIOR_LEFT
        /* 1       0   0   1 */           ,CANONICAL_OUTER_TOP_POSTERIOR_CENTER
        /* 1       0   0   2 */           ,CANONICAL_OUTER_TOP_POSTERIOR_RIGHT
        /* 1       0   1   0 */           ,CANONICAL_OUTER_TOP_CENTER_LEFT
        /* 1       0   1   1 */           ,CANONICAL_OUTER_TOP_CENTER_CENTER
        /* 1       0   1   2 */           ,CANONICAL_OUTER_TOP_CENTER_RIGHT
        /* 1       0   2   0 */           ,CANONICAL_OUTER_TOP_FRONT_LEFT
        /* 1       0   2   1 */           ,CANONICAL_OUTER_TOP_FRONT_CENTER
        /* 1       0   2   2 */           ,CANONICAL_OUTER_TOP_FRONT_RIGHT

    };
    int innermap[NUM_FACES][BULBS_INSIDE] = {

        /* 0       0   3 */               CANONICAL_INNER_RIGHT_POSTERIOR_TOP 
        /* 0       0   1 */               ,CANONICAL_INNER_RIGHT_FRONT_TOP
        /* 0       0   2 */               ,CANONICAL_INNER_RIGHT_POSTERIOR_BOTTOM
        /* 0       0   0 */               ,CANONICAL_INNER_RIGHT_FRONT_BOTTOM

        /* 0       0   3 */               ,CANONICAL_INNER_BOTTOM_POSTERIOR_RIGHT
        /* 0       0   1 */               ,CANONICAL_INNER_BOTTOM_FRONT_RIGHT
        /* 0       0   2 */               ,CANONICAL_INNER_BOTTOM_POSTERIOR_LEFT
        /* 0       0   0 */               ,CANONICAL_INNER_BOTTOM_FRONT_LEFT
  
        /* 0       0   3 */               ,CANONICAL_INNER_LEFT_POSTERIOR_BOTTOM
        /* 0       0   1 */               ,CANONICAL_INNER_LEFT_FRONT_BOTTOM
        /* 0       0   2 */               ,CANONICAL_INNER_LEFT_POSTERIOR_TOP
        /* 0       0   0 */               ,CANONICAL_INNER_LEFT_FRONT_TOP

        /* 0       0   3 */               ,CANONICAL_INNER_TOP_POSTERIOR_LEFT
        /* 0       0   1 */               ,CANONICAL_INNER_TOP_FRONT_LEFT
        /* 0       0   2 */               ,CANONICAL_INNER_TOP_POSTERIOR_RIGHT
        /* 0       0   0 */               ,CANONICAL_INNER_TOP_FRONT_RIGHT

    };
    if(outer) {
        return outermap[face][row][col];
    } else {
        return innermap[face][row];
    }
}
//indexes are canonical indexes. values are SPI addresses.
static int spi_layout[NUM_CANONICAL]= {[0 ...NUM_CANONICAL-1]=-1};

static int layoutloader (char* filename )
{
    int i;
    //("loading layout inside \n");
    //get default layout name.
    //("size %d : %d \n", spi_layout[0], ARRAY_SIZE(spi_layout));

    read_layout(filename, spi_layout);
    // for( i=0; i<NUM_CANONICAL; i++) {
    //     //("Layout that I read was: index: %d value: %d , valuename: %s \n"
    //      //      ,i, spi_layout[i], CANONICAL_NAMES[i] );
    // }
    //("loadinglayout done\n");
    return 0;

}

static int canonical_to_spi(int canonical, int orientation)
{
    //look up on a table.
    //ignoring orientation for now.
    return spi_layout[canonical];
}




void set_pixel(int face, int row, int col, uint8_t r, uint8_t g, uint8_t b)
{

    // Need to check for out-of-bounds here, but meh.
    //////("col %d row %d offset %d\n", col, row, (*climap + col)[row]);
    // Calculate the offset into the buffer

    int canonical = set_to_canonical(1,face,row,col);
    int offset = canonical_to_spi(canonical,0)*3;
    //("spi_address outer face: %d row: %d col %d offset: %d \n",face,row,col,offset);
    //offset = get_bulb_number(face, row, col) * 3;       // Get the correct offset from the map

    txbuf[offset] = g | 0x80;
    txbuf[offset+1] = r | 0x80;
    txbuf[offset+2] = b | 0x80;
    //////("%d %d %x %x %x\n", row, col, r, g, b);

}

void set_inner_pixel(int face, int bulb, uint8_t r, uint8_t g, uint8_t b)
{

    int canonical = set_to_canonical(0,face,bulb,0);
    int offset = canonical_to_spi(canonical,0) * 3;
    //("spi_address inner face: %d bulb: %d offset:%d \n",face,bulb,offset);

    // Calculate the offset into the buffer

//    offset = get_inside_bulb_number(face, bulb) * 3;        // Get the correct offset from the map
    txbuf[offset] = g | 0x80;
    txbuf[offset+1] = r | 0x80;
    txbuf[offset+2] = b | 0x80;

}

//walk_pixels


void clear_pixels(uint8_t r, uint8_t g, uint8_t b)
{
    int face, col, row;

    uint8_t max_range = 0x0f;

    for (face = 0; face < 4; face++) {
        for (col = 0; col < 3; col++) {
            for (row = 0; row < 3; row++) {
                set_pixel(face,row,col,r,g,b);
            }
        }
        for (row = 0; row < BULBS_INSIDE; row++) {
            set_inner_pixel(face,row,r,g,b);
        }
    }
}



//#include "mainloop.c"


int main(int argc, char *argv[])
{
    int ret = 0;
    int fileDescriptor, ss, sp, j;
    int retuid;
    int doing;
    layoutloader("layout.conf.json");
    int face, row, col;


    retuid = setuid(0);     // root me!
    if (retuid == -1) {
        exit(-10);
    }

    since_start();          // initialize the count of when we started execution

    // Read the size of our LED string
    // Use the correct map for the string size
    string_size = ss = NUM_BULBS;

    sp = ss * 3;            // Number of color units in string

    // Allocate space for the frame transmit buffer
    txbuf = malloc(sp + 1);
    txbuf[sp] = 0x00;       // Last byte always null for end of sequence signalling

#ifdef OLIMEX
    gpio_map();
    gpio_output(2,1); //bank 2 bit 1 = GPIO65 the LED on board
    gpio_output(0,20); //bank 0 bit 20 = GPIO20 = SSP2_MOSI
    gpio_output(0,24); //bank 0 bit 24 = GPIO24 = SSP2_SCLK
#else
    fileDescriptor = open(device, O_RDWR);
    if (fileDescriptor < 0)
        pabort("can't open device");

    /*
     * spi mode
     */
    ret = ioctl(fileDescriptor, SPI_IOC_WR_MODE, &mode);
    if (ret == -1)
        pabort("can't set spi mode");

    ret = ioctl(fileDescriptor, SPI_IOC_RD_MODE, &mode);
    if (ret == -1)
        pabort("can't get spi mode");

    /*
     * bits per word
     */
    ret = ioctl(fileDescriptor, SPI_IOC_WR_BITS_PER_WORD, &bits);
    if (ret == -1)
        pabort("can't set bits per word");

    ret = ioctl(fileDescriptor, SPI_IOC_RD_BITS_PER_WORD, &bits);
    if (ret == -1)
        pabort("can't get bits per word");

    /*
     * max speed hz
     */
    ret = ioctl(fileDescriptor, SPI_IOC_WR_MAX_SPEED_HZ, &speed);
    if (ret == -1)
        pabort("can't set max speed hz");

    ret = ioctl(fileDescriptor, SPI_IOC_RD_MAX_SPEED_HZ, &speed);
    if (ret == -1)
        pabort("can't get max speed hz");

    ////("spi mode: %d\n", mode);
    ////("bits per word: %d\n", bits);
    ////("max speed: %d Hz (%d KHz)\n", speed, speed/1000);
#endif

    // Ok, we're ready to start, so call the setup
    //setup(argc,argv);
    synchronize(1);                                         // And setup the sync function
    while (doing) {

		// Clear the whole string
		// Set a bulb
		// And move on
		for (face = 0; face < 4; face++) {
			for (row = 0; row < ROWS_PER_FACE; row++) {
				for (col = 0; col < COLS_PER_FACE; col++) {
					memset((void*) txbuf, (int) 0x80, (size_t) sp);  // Clear the string quickly
					set_pixel(face, col, row, 0xFF, 0xFF, 0xFF);
					send_frame(fileDescriptor, txbuf, (sp + 3));		// Try to transmit the frame
					usleep(100000);
				}
			}
	
		}
	
		// Chase the inner LEDs
		for (face = 0; face < 4; face++) {
			for (row = 0; row < BULBS_INSIDE; row++) {
				memset((void*) txbuf, (int) 0x80, (size_t) sp);  // Clear the string quickly
				set_inner_pixel(face, row, 0xFF, 0xFF, 0xFF);
				send_frame(fileDescriptor, txbuf, (sp + 3));		// Try to transmit the frame
				usleep(100000);
			}
		}	



        /*if (loop(since_start())) {
            //doing = 0;
        }*/
        //synchronize(20000000);                              // 50 fps or 20 msec/frame
        //send_frame(fileDescriptor, txbuf, (sp + 1));        // Try to transmit the frame
    }
    free(txbuf);                                            // Always clean up after yourself!
#ifdef OLIMEX
#else
    close(fileDescriptor);
#endif
    return 0;
}
