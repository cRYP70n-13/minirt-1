#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>

/*
int main()
{
    sf::RenderWindow *window = nullptr;
    sf::VideoMode videomode;
    videomode.height = 600;
    videomode.width = 800;
    window = new sf::RenderWindow(videomode, "zbi", sf::Style::Titlebar | sf::Style::Close);
    while (window->isOpen())
    {

    }
}
*/
/*
int main(int argc, char **argv)
{
    unsigned int height = 400;
    unsigned int width = 400;
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(width, height), "zbi");
    sf::Event event;
    sf::Texture texture;
    sf::Image ig;
    ig.create(width, height, sf::Color(0, 0, 0));
    texture.loadFromImage(ig);
    sf::Sprite es;
    es.setTexture(texture);

    int i = 0;
    int j;
    while (i < 1000)
    {
        j = 0;
        while (j < 1000)
        {
            ig.setPixel (j, i, sf::Color(255.999 * (double(i) / height), 255.99 * (double(j) / width), 0));
            j++;
        }
        i++;
    }

    texture.loadFromImage (ig);
    es.setTexture(texture);


    while (window->isOpen())
    {
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::EventType::Closed)
                window->close();
        }
        window->clear();
        window->draw(es);
        window->display();
    }
}
*/

sf::Vector3f s_vec3f_div(sf::Vector3f t, float d)
{
    sf::Vector3f r (0, 0, 0);
    r.x = t.x / d;
    r.y = t.y / d;
    r.z = t.z / d;
    return (r);
}

int main(int argc, char **argv)
{
    unsigned int height = 400;
    unsigned int width = 400;
    sf::RenderWindow *window = new sf::RenderWindow(sf::VideoMode(width, height), "zbi");
    sf::Event event;
    sf::Texture texture;
    sf::Image ig;
    ig.create(width, height, sf::Color(0, 0, 0));
    texture.loadFromImage(ig);
    sf::Sprite es;
    es.setTexture(texture);

    //setting image

    //image
    float aspect_ratio = 16.0 / 9.0;
    int image_width = 250;
    int image_height = (int)image_width / aspect_ratio;

    //camera (eye) / screen

    float viewport_height = 2.0;
    float viewport_width = aspect_ratio * viewport_height;
    float focal_length = 1.0;
    sf::Vector3f origin(0, 0, 0);
    sf::Vector3f horizontal(viewport_width, 0, 0);
    sf::Vector3f vertical(0, viewport_height, 0);
    sf::Vector3f lower_left_corner = origin - s_vec3f_div(horizontal, 2) -  s_vec3f_div( vertical, 2) - sf::Vector3f(0, 0, focal_length);

    //render

   int i = image_height;
    int j = image_width;
    int j_opp = 0;
    float u;
    float v;
    void *mlx_ptr = mlx_init();
    void *mlx_window = mlx_new_window(mlx_ptr, image_width, image_height, "first camera");
    while (j > 0)
    {
        i = 0;
        while (i < image_width)
        {
            t_s_vect3f dir;
            u = (float)i / image_width;
            v = (float)j / image_height;
            dir = s_vec3f_add(lower_left_corner, s_vec3f_multi(horizontal, u));
            dir = s_vec3f_add(dir, s_vec3f_multi(vertical, v));
            dir = s_vec3f_sub(dir, origin);
            t_ray *r = ray(&origin, &dir);
            t_trgb pixel_color = ray_color_fr(r);
            //mlx_pixel_put(mlx_ptr, mlx_window, i, j_opp, pixel_color);
            //mlx_pixel_put(mlx_ptr, mlx_window, i, j_opp, create_pixel(0, 0, 0, 0));
            printf("\n%f\n", s_vec3f_norm (*r->direction).y);
            ray_destroy(r);
            i++;
        }
        j_opp = increament_j();
        j--;
    }

    texture.loadFromImage(ig);
    es.setTexture(texture);

    while (window->isOpen())
    {
        while (window->pollEvent(event))
        {
            if (event.type == sf::Event::EventType::Closed)
                window->close();
        }
        window->clear();
        window->draw(es);
        window->display();
    }
}
