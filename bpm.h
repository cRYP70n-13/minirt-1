#ifndef BPM_H
#define BPM_H

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdint.h>
#include "image/image.h"

typedef struct s_bmp t_bmp;

struct s_bmp
{
    int width;
    int height;
    int padding;
    uint32_t *pixels;
};
void write_bmp(char *filename, t_bmp rgb, int width, int height);


t_bmp create_pixels_array (int width, int height);


#endif