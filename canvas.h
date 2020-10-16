#ifndef CANVAS_H
#define CANVAS_H

#include <stdio.h>
#include <stdlib.h>


typedef unsigned int t_imgcmp;
typedef unsigned int t_trgb;

typedef struct s_canvas t_canvas;

struct s_canvas {
  int w;
  int h;
  t_trgb bg;
  t_trgb *data;
  t_trgb **pixel;
};

int create_trgb(int t, int r, int g, int b);

int get_t(int t_trgb);
int get_r(int t_trgb);
int get_g(int t_trgb);
int get_b(int t_trgb);


t_trgb image_make_color(t_imgcmp t, t_imgcmp r, t_imgcmp g, t_imgcmp b);
t_canvas *canvas_create (int w, int h, t_trgb bg);
void canvas_fill (t_canvas *A, t_trgb bg);
void canvas_destroy (t_canvas *A);
t_trgb canvas_get (t_canvas *A, int x, int y);
void write_pixel (t_canvas *A, int x, int y, t_trgb value);
void write_pixel_center (t_canvas *A, int x, int y, t_trgb value);
#endif