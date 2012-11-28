/*
 * Copyright (c) 2007-2011, Lloyd Hilaiel <lloyd@hilaiel.com>
 *
 * Permission to use, copy, modify, and/or distribute this software for any
 * purpose with or without fee is hereby granted, provided that the above
 * copyright notice and this permission notice appear in all copies.
 *
 * THE SOFTWARE IS PROVIDED "AS IS" AND THE AUTHOR DISCLAIMS ALL WARRANTIES
 * WITH REGARD TO THIS SOFTWARE INCLUDING ALL IMPLIED WARRANTIES OF
 * MERCHANTABILITY AND FITNESS. IN NO EVENT SHALL THE AUTHOR BE LIABLE FOR
 * ANY SPECIAL, DIRECT, INDIRECT, OR CONSEQUENTIAL DAMAGES OR ANY DAMAGES
 * WHATSOEVER RESULTING FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN
 * ACTION OF CONTRACT, NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF
 * OR IN CONNECTION WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.
 */

#include <yajl/yajl_parse.h>
#include <yajl/yajl_gen.h>

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "layoutloader.h"
#include "sing.h"
#include "lightnames.h"

#define STRINGBUFFSIZE 128
//Level in the json object.
static int level = 0;
//current key
static char currentMapKey[STRINGBUFFSIZE]="";
static int currentMapKeyNumber = -1;
//selected layout. I want this to match the current map key
//when pulling values into the array.
static char selectedLayoutName[STRINGBUFFSIZE]="";
static int  selectedLayoutNameFound=0;
static int  inSelectedLayout=0;


static int layout_null(void * ctx)
{
    //("null\n");
    return 1;
}

static int layout_boolean(void * ctx, int boolean)
{
    //("boolean %d \n", boolean);
    return 1;
}

static int layout_number(void * ctx, const char * sVal, size_t l)
{
    char s[l+1];
    s[l]='\0';
    strncpy(s,sVal,l);
    //("number: %s\n",s);
    return 1;
}


static int layout_int(void * ctx, const long long number)
{
    if(inSelectedLayout) {
        int *layoutTable=(int*)ctx;
        layoutTable[currentMapKeyNumber]=(int)number;
        //("int: %lld , mapkey: %d , ARRAY FIRST: %d\n ",number, currentMapKeyNumber, layoutTable[currentMapKeyNumber] );
    }
    return 1;
}

static int layout_string(void * ctx, const unsigned char * stringVal,
                         size_t stringLen)
{
    char s[stringLen+1];
    s[stringLen]='\0';
    strncpy(s,stringVal,stringLen);
    if(selectedLayoutNameFound) {
        //("selectedLayoutNameFound: %s",s);
        //copy over the selected layout name to the currently selected layout name variable.
        selectedLayoutName[stringLen]='\0';
        strncpy(selectedLayoutName,stringVal,stringLen);
        selectedLayoutNameFound=0;
    }
    //("string: %s\n", s);
    return 1;
}

static int layout_map_key(void * ctx, const unsigned char * stringVal,
                          size_t stringLen)
{
    char s[stringLen+1];
    s[stringLen]='\0';
    if(stringLen<STRINGBUFFSIZE) {
        currentMapKey[stringLen]='\0';
    } else {
        currentMapKey[STRINGBUFFSIZE-1]='\0';
    }

    strncpy(s,stringVal,stringLen);
    //set the currentMapKey
    strncpy(currentMapKey,stringVal,stringLen<STRINGBUFFSIZE?stringLen:STRINGBUFFSIZE-1);
    struct canonical_numbers *num;
    num = canonical_name_to_number (s, stringLen);

    if(num!=NULL) {
        //("map key: %s mapkeynumber %d \n",s, num->number);
        currentMapKeyNumber=(num->number);
    } else {
        currentMapKeyNumber=-1;
        //("missed %s \n",s);
        if(strncmp("DEFAULT_LAYOUT",s,14)==0) {
            selectedLayoutNameFound=1;
            //("DEFAULT LAYOUT KEY\n");
        }
        if(strcmp(selectedLayoutName,s)==0) {
            inSelectedLayout=1;
            //("Selected layout found\n");
        }
    }
    return 1;
}

static int layout_start_map(void * ctx)
{
    level += 1;
    //("start map\n");
    return 1;
}

static int layout_end_map(void * ctx)
{
    level -=1;
    //if I was in selected layout and I encounter the end, then I am out;
    inSelectedLayout=0;
    //("end map\n");
    return 1;
}

static int layout_start_array(void * ctx)
{
    //("start array\n");
    return 1;
}

static int layout_end_array(void * ctx)
{
    //("end array\n");
    return 1;
}

static yajl_callbacks callbacks = {
    layout_null,
    layout_boolean,
    layout_int,  //int
    NULL,  //double
    NULL,//layout_number,
    layout_string,
    layout_start_map,
    layout_map_key,
    layout_end_map,
    layout_start_array,
    layout_end_array
};

//todo: Test layouts with missing or misspelled keys.
//print error message if key with non registered name is encountered.
int read_layout(char* filename, int layoutTable[NUM_CANONICAL] )
{
    //("testing_read array size %d \n", layoutTable[0] );
    //we'll ignore filename for now.
    FILE* fd;
    //selectedLayoutName=layoutname;


//I've got an array
    //i've got its length in NUM_CANONICAL.
    //It's an int array.
    //fill it with -1
    //in read int
    //look up the name in canonical names.
    //really?
    //no hash.

    if(filename != NULL) {
        //("about to open %s to load %s \n", filename);
        fd = fopen(filename, "r");
        if (fd == NULL) {
            //("Could not open %s, exiting...\n", filename);
            exit(-7);
        } else {
            //("Could open but something else went wrong \n");
        }
    } else {
        fd = stdin;
    }

    //("testing_read 1 \n");

    yajl_handle hand;
    static unsigned char fileData[65536];
    /* generator config */
    yajl_status stat;
    size_t rd;
    int retval = 0;
    int a = 1;

    /* ok.  open file.  let's read and parse */
    hand = yajl_alloc(&callbacks, NULL, layoutTable);

    //("testing_read 2 \n");

    /* and let's allow comments by default */
    yajl_config(hand, yajl_allow_multiple_values, 1);


    //("testing_read 3 \n");

    size_t bytesConsumed;

    for (;;) {
        //("testing_read 4a \n");

        rd = fread((void *) fileData, 1, sizeof(fileData) - 1, fd);

        //("rd %ld\n",rd);

        if (rd == 0) {
            if (!feof(fd)) {
                //(stderr, "error on file read.\n");
                retval = 1;
            }
            break;
        }
        fileData[rd] = 0;

        stat = yajl_parse(hand, fileData, rd);
        //("testing_read 4b \n");

        bytesConsumed = yajl_get_bytes_consumed(hand);
        //("loop read: %ld consumed:   %ld \n", rd, bytesConsumed);

        if (stat != yajl_status_ok) {
            //("not ok in \n");

            break;
        }
        {
            //("okay\n");
        }
    }
    //("testing_read 5 \n");

    //("completed parse\n");
    stat = yajl_complete_parse(hand);

    if (stat != yajl_status_ok) {
        //("not ok out\n");
        unsigned char * str = yajl_get_error(hand, 1, fileData, rd);
        //(stderr, "%s", (const char *) str);
        yajl_free_error(hand, str);
        retval = 1;
    }
    yajl_free(hand);
    return retval;
}


// int main(int argc, char ** argv)
// {
//     return layout_read(NULL);
// }