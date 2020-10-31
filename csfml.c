#include "csfml.h"

mlx_window mlx_window_init (unsigned int width, unsigned int height, const char *title, sfColor color)
{
    mlx_window m;
    sfVideoMode vidmode = {width, height, 8};
    m.window = sfRenderWindow_create (vidmode, title, sfDefaultStyle, NULL);
    m.image = sfImage_create (width, height);
    m.texture = sfTexture_createFromImage (m.image, NULL);
    m.sprite = sfSprite_create ();
    sfSprite_setTexture (m.sprite, m.texture, sfFalse);
    return (m);
}

void mlx_update (mlx_window *m)
{
    sfTexture_updateFromImage (m->texture,  m->image, 0, 0);
    sfSprite_setTexture (m->sprite, m->texture, sfFalse);
}

void mlx_delete (mlx_window *mlx)
{
    sfSprite_destroy (mlx->sprite);
    sfTexture_destroy(mlx->texture);
    sfImage_destroy (mlx->image);
    sfRenderWindow_destroy (mlx->window);
}