#ifndef BPM_H
#define BPM_H

typedef struct s_bmp t_bmp;

struct s_bmp
{
    int width;
    int height;
    char *rgb;
};

#include <stdlib.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>



#endif