#include "mlx.h"

mlx_window mlx_window_init (unsigned int width, unsigned int height, sf::String title, sf::Color color)
{
    mlx_window m;
    sf::Event event;
    sf::Image ig;
    sf::Texture texture;
    sf::Sprite sprite;

    m.window = new sf::RenderWindow(sf::VideoMode(640, 480), title);
    m.image.create (width, height, sf::Color(255, 0, 0));
    m.texture.loadFromImage(m.image);
    m.sprite.setTexture(m.texture);
}