#include "mlx.h"

mlx_window mlx_window_init (unsigned int width, unsigned int height, sf::String title, sf::Color color)
{
    mlx_window m;
    

    m.window = new sf::RenderWindow (sf::VideoMode(width, height), title);
    m.image.create (width, height, sf::Color(255, 0, 0));
    m.texture.loadFromImage(m.image);
    m.sprite.setTexture(m.texture);
    m.window->setFramerateLimit(60);
    return (m);
}

void mlx_update (mlx_window *m)
{
    m->texture.loadFromImage(m->image);
    m->sprite.setTexture(m->texture);
}

void mlx_delete (mlx_window *mlx)
{
    delete mlx->window;
}