#include "mlx/mlx.h"
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>
#include "canvas/canvas.h"
#include "rays.h"
#include "math.h"

/*
int main(int argc, char **argv)
{
    unsigned int height = 400;
    unsigned int width = 400;

    mlx_window mw = mlx_window_init(width, height, "zbi", sf::Color::Black);

    int i = 0;
    int j;
    while (i < 1000)
    {
        j = 0;
        while (j < 1000)
        {
            mw.image.setPixel(j, i, sf::Color(255.999 * (double(i) / height), 255.99 * (double(j) / width), 0));
            j++;
        }
        i++;
    }

    while (mw.window->isOpen())
    {
        while (mw.window->pollEvent(mw.event))
        {
            if (mw.event.type == sf::Event::EventType::Closed)
                mw.window->close();
        }
        mlx_update(&mw);
        mw.window->clear();
        mw.window->draw(mw.sprite);
        mw.window->display();
    }
    return (0);
}
*/

float vec3f_mag(sf::Vector3f vec)
{
    float m;

    m = 0;
    m = sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2));

    return (m);
}

sf::Vector3f vec3f_norm(sf::Vector3f vec)
{
    sf::Vector3f norm;
    float mag;

    norm = sf::Vector3f(0, 0, 0);
    mag = vec3f_mag(vec);
    norm.x = vec.x / mag;
    norm.y = vec.y / mag;
    norm.z = vec.z / mag;
    return norm;
}

sf::Vector3f ray_color(ray &r)
{
    sf::Vector3f unit_direction = vec3f_norm(r.dir);
    float t = 0.5 * (unit_direction.y + 1.0);
    return (sf::Vector3f(1.0, 1.0, 1.0) * (1 - t)) + (sf::Vector3f(0.5, 0.7, 1.0) * t);
}

int increment_j()
{
    static int j;
    j++;
    return (j);
}

float dotproduct(sf::Vector3f v1, sf::Vector3f v2)
{
    return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
}

bool hit_sphere(sf::Vector3f &center, float radius, ray &r)
{
    sf::Vector3f oc = r.origin() - center;
    auto a = dotproduct(r.direction(), r.direction());
    auto b = 2.0 * dotproduct(oc, r.direction());
    auto c = dotproduct(oc, oc) - radius * radius;
    auto discriminant = b * b - 4 * a * c;
    return (discriminant > 0);
}

sf::Vector3f ray_color_s(ray &r)
{
    sf::Vector3f v(0, 0, -1);
    sf::Vector3f c(1.0, 0, 0);
    if (hit_sphere(v, 0.5, r))
        return (c);
    sf::Vector3f unit_direction = vec3f_norm(r.dir);
    float t = 0.5 * (unit_direction.y + 1.0);
    return (sf::Vector3f(1.0, 1.0, 1.0) * (1 - t)) + (sf::Vector3f(0.5, 0.7, 1.0) * t);
}

int main(int argc, char **argv)
{
    //unsigned int height = 400;
    //unsigned int width = 400;

    //setting image

    //image
    float aspect_ratio = 16.0 / 9.0;
    int image_width = 400;
    int image_height = (int)image_width / aspect_ratio;
    mlx_window mw = mlx_window_init(image_width, image_height, "zbi", sf::Color::Black);
    //camera (eye) / screen

    float viewport_height = 2.0;
    float viewport_width = aspect_ratio * viewport_height;
    float focal_length = 1.0;

    sf::Vector3f origin(0, 0, 0);
    sf::Vector3f horizontal(viewport_width, 0, 0);
    sf::Vector3f vertical(0, viewport_height, 0);
    sf::Vector3f lower_left_corner = origin - horizontal / 2.f - vertical / 2.f - sf::Vector3f(0, 0, focal_length);

    //render

    int j = image_height - 1;
    int i = image_width;
    int j_opp = 0;
    float u;
    float v;

    while (j >= 0)
    {
        i = 0;
        while (i < image_width)
        {
            sf::Vector3f dir;
            u = (float)i / (image_width - 1);
            v = (float)j / (image_height - 1);
            dir = lower_left_corner + (horizontal * u) + (vertical * v) - origin;
            ray r = ray(origin, dir);
            sf::Vector3f pixel_color = ray_color_s(r);
            //mlx_pixel_put(mlx_ptr, mlx_window, i, j_opp, pixel_color);
            //mlx_pixel_put(mlx_ptr, mlx_window, i, j_opp, create_pixel(0, 0, 0, 0));
            mw.image.setPixel(i, j_opp, sf::Color(pixel_color.x * 255, pixel_color.y * 255, pixel_color.z * 255));
            i++;
        }
        j_opp = increment_j();
        j--;
    }

    /*
    for (int j = image_height - 1; j >= 0; --j)
    {
        for (int i = 0; i < image_width; ++i)
        {
            auto u = float(i) / (image_width - 1);
            auto v = float(j) / (image_height - 1);
            sf::Vector3f dir;
            dir = lower_left_corner + (horizontal * u) + (vertical * v) - origin;
            ray r = ray(origin, dir);
            sf::Vector3f pixel_color = ray_color_s(r);
            mw.image.setPixel(i, j_opp, sf::Color(pixel_color.x * 255, pixel_color.y * 255, pixel_color.z * 255));
            //mw.image.setPixel(i, j_opp, sf::Color::Green);
        }
        j_opp = increment_j();
    }
*/
//    mlx_update(&mw);
  //  mw.window->clear();
    //mw.window->draw(mw.sprite);
    //mw.window->display();
    while (mw.window->isOpen())
    {
        while (mw.window->pollEvent(mw.event))
        {
            if (mw.event.type == sf::Event::EventType::Closed)
                mw.window->close();
            else if (mw.event.type == sf::Event::KeyPressed)
            {
                if (mw.event.key.code == sf::Keyboard::Up)
                {
                }
                else if (mw.event.key.code == sf::Keyboard::Down)
                {
                }
            }
        }
        mlx_update(&mw);

        mw.window->clear();
        mw.window->draw(mw.sprite);
        mw.window->display();
    }
    return (0);
}
