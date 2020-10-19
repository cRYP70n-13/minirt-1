#include <stdio.h>
#include "rays/rays.h"
#include "vec3f/vec3f.h"
#include "mlx.h"
#include "canvas.h"

t_trgb ray_color(t_ray *r)
{
    t_s_vect3f unit_direction;
    float t;
    unit_direction = s_vec3f_norm(*(r->direction));
    t = 0.5 * (unit_direction.y + 1);
    return ((1.0 - t) * create_pixel(0, 255, 255, 255) + t * create_pixel(0, 0.5 * 255, 0.7 * 255, 1.0 * 255));
}

int increament_j (void)
{
    static int j;
    j++;
    return (j);
}

int main(void)
{
    //image
    float aspect_ratio = 16.0;
    float image_width = 400;
    float image_height = image_width / aspect_ratio;

    //camera (eye) / screen

    float viewport_height = 2.0;
    float viewport_width = aspect_ratio * viewport_height;
    float focal_length = 1.0;

    t_s_vect3f origin = s_vec3f(0, 0, 0, 1);
    t_s_vect3f horizontal = s_vec3f (viewport_width, 0, 0, 1);
    t_s_vect3f vertical = s_vec3f (0, viewport_height, 0, 0);
    t_s_vect3f lower_left_corner = s_vec3f_sub (origin, s_vec3f_div(horizontal, 2));
    lower_left_corner = s_vec3f_sub (lower_left_corner, s_vec3f_div(vertical, 2));
    lower_left_corner = s_vec3f_sub (lower_left_corner, s_vec3f(0, 0, focal_length, 1));

    // RENDER
    
    int i = image_height;
    int j = image_width;
    float u;
    float v;
    void *mlx_ptr = mlx_init ();
    void *mlx_window = mlx_new_window (mlx_ptr, 1000, 1000, "first camera");

    while (j > 0)
    {
        i = 0;
        while (i < image_width)
        {
            t_s_vect3f dir;
            u = (float) i / image_width;
            v = (float) j / image_height;
            dir = s_vec3f_add (lower_left_corner, s_vec3f_multi(horizontal, u));
            dir = s_vec3f_add (dir, s_vec3f_multi (vertical, v));
            dir = s_vec3f_sub (dir, origin);
            t_vect3f v1 = vec3f (0, 0, 0, 0);
            t_vect3f v2 = vec3f (0, 0, 0, 0);
            t_ray *r = ray(v1, v2);
            //t_ray *r = ray(&origin, &dir);
            //t_trgb pixel_color = ray_color (r);
            //mlx_pixel_put (mlx_ptr, mlx_window, i, increament_j(), pixel_color);
            //ray_destroy (r);
            i++;
        }
        j--;
    }
    mlx_destroy_window (mlx_ptr, mlx_window);
    return (0);
}