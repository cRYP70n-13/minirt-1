#ifndef CSFML_H
#define CSFML_H
#include <SFML/Graphics.h>
#include <SFML/System.h>
#include <SFML/Window.h>
#include <SFML/Audio.h>
#include <SFML/Network.h>
# include <stdio.h>

typedef unsigned int t_imgcmp;
typedef unsigned int t_trgb;

t_trgb create_pixel(int t, int r, int g, int b);
int get_t(int t_trgb);
int get_r(int t_trgb);
int get_g(int t_trgb);
int get_b(int t_trgb);


typedef struct _mlx mlx_window;

struct _mlx
{
    sfRenderWindow *window;
    sfTexture *texture;
    sfImage *image;
    sfSprite *sprite;
    sfEvent event;
};

mlx_window mlx_window_init (unsigned int width, unsigned int height, const char *title, sfColor color);
void mlx_update (mlx_window *m);
void mlx_delete (mlx_window *mlx);
#endif