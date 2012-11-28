#ifndef SING_H_
#define SING_H_

#include <stdint.h>
#define ARRAY_SIZE(a) (sizeof(a) / sizeof((a)[0]))
#define NUM_FACES 4
#define ROWS_PER_FACE 3
#define COLS_PER_FACE 3
#define BULBS_INSIDE 4
#define NUM_BULBS 52
#define NUM_CANONICAL 78


void set_pixel(int face, int row, int col, uint8_t r, uint8_t g, uint8_t b);
void set_inner_pixel(int face, int bulb, uint8_t r, uint8_t g, uint8_t b);
void clear_pixels(uint8_t r, uint8_t g, uint8_t b);
long sing_realtime(void);
long sing_monotime(void);
void setup(int argc, char *argv[]);
int loop(long time);




// here goes all the code

#endif /*SING_H_*/