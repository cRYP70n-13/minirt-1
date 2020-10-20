#include <stdio.h>
#include "rays/rays.h"
#include "vec3f/vec3f.h"
#include "mlx.h"
#include "canvas.h"

t_trgb create_pixel_medium(float tf, float rf, float gf, float bf)
{
    int t = 255 * tf;
    int r = 255 * rf;
    int g = 255 * gf;
    int b = 255 * bf;
    return (t << 24 | (r << 16) | (g << 8) | b);
}

t_trgb ray_color(t_ray *r)
{
    t_s_vect3f unit_direction;
    float t;
    unit_direction = s_vec3f_norm(*(r->direction));
    t = 0.5 * (unit_direction.y + 1);
    return ((1.0 - t) * create_pixel_medium(0, 1, 1, 1) + t * create_pixel_medium(0, 0.5, 0.7, 1.0));
}


t_trgb ray_color_fr(t_ray *r)
{
    t_s_vect3f unit_direction;
    float t;
    unit_direction = s_vec3f_norm(*(r->direction));
    t = (unit_direction.y);
    // printf("%f\n", t);

    t_s_vect3f a;
    t_s_vect3f b;
    a = s_vect3f (255, 255, 255, 0);
    return ((1.0 - t) * create_pixel(0, 255, 255, 255) + t * create_pixel(0, 255, 0, 0));
}


int increament_j(void)
{
    static int j;
    int r;
    j++;
    r = j;
    return (j);
}



int main(void)
{

    //image
    float aspect_ratio = 16.0 / 9.0;
    int image_width = 250;
    int image_height = (int)image_width / aspect_ratio;

    //camera (eye) / screen

    float viewport_height = 2.0;
    float viewport_width = aspect_ratio * viewport_height;
    float focal_length = 1.0;

    t_s_vect3f origin = s_vec3f(0, 0, 0, 1);
    t_s_vect3f horizontal = s_vec3f(viewport_width, 0, 0, 1);
    t_s_vect3f vertical = s_vec3f(0, viewport_height, 0, 0);
    t_s_vect3f lower_left_corner = s_vec3f_sub(origin, s_vec3f_div(horizontal, 2));
    lower_left_corner = s_vec3f_sub(lower_left_corner, s_vec3f_div(vertical, 2));
    lower_left_corner = s_vec3f_sub(lower_left_corner, s_vec3f(0, 0, focal_length, 1));

    // RENDER

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

    /*
    for (int j = image_height - 1; j >= 0; --j)
    {
        for (int i = 0; i < image_width; ++i)
        {
            t_s_vect3f dir;
            u = (float)i / (image_width - 1);
            v = (float)j / (image_height  - 1);
            dir = s_vec3f_add(lower_left_corner, s_vec3f_multi(horizontal, u));
            dir = s_vec3f_add(dir, s_vec3f_multi(vertical, v));
            dir = s_vec3f_sub(dir, origin);
            t_ray *r = ray(&origin, &dir);
            t_trgb pixel_color = ray_color(r);
            mlx_pixel_put(mlx_ptr, mlx_window, i, j_opp, create_pixel (0, 0, 0, 255));
            printf ("\n %d %d \n", j, i);
            ray_destroy (r);
        }
    }
    */
    //mlx_loop(mlx_ptr);
    mlx_destroy_window(mlx_ptr, mlx_window);

    return (0);
}