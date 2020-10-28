#ifndef IMAGE_H
#define IMAGE_H

#include "mlx.h"

#include <stdio.h>
#include <stdlib.h>
typedef unsigned int t_imgcmp;
typedef unsigned int t_trgb;

t_trgb create_pixel(int t, int r, int g, int b);
int get_t(int t_trgb);
int get_r(int t_trgb);
int get_g(int t_trgb);
int get_b(int t_trgb);

typedef struct s_image t_image;

struct s_image
{
    int height;
    int width;
    void *mlx_ptr;
    void *mlx_img;
    char *data;
    int bits_per_pixel;
    int size_line;
    int endian;
};
/*
** using an mlx image as a canvas`
*/

t_image *mlx_create_img(void *mlx_ptr, int width, int height);
void img_set_pixel(t_image *img, int x, int y, t_trgb value);
void mlx_img_destroy(t_image *img);

#endif