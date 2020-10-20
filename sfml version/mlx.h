#ifndef MLX_H
#define MLX_H
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

typedef struct _mlx mlx_window;

struct _mlx
{
    sf::RenderWindow *window;
    sf::Event event;
    sf::Texture texture;
    sf::Image image;
    sf::Sprite sprite;
};

mlx_window mlx_window_init (unsigned int width, unsigned int height, sf::Color color);
void mlx_window_update ()

#endif