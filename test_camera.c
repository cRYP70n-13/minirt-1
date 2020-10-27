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


t_s_vect3f ray_color(t_ray *r)
{
    t_s_vect3f unit_direction;
    float t;
    t_s_vect3f result;
    t_s_vect3f sphere_center;

    unit_direction = s_vec3f_norm(*(r->direction));
    t = 0.5 * (unit_direction.y + 1);
    result = s_vec3f_add(s_vec3f_multi(s_vec3f(1, 1, 1, VECTOR), (1.0 - t)), s_vec3f_multi(s_vec3f(0.5, 0.7, 1.0, VECTOR), t));
    return (result);
}

int main(void)
{

    //image
    float aspect_ratio = 16.0 / 9.0;
    int image_width = 1000;
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

    int i;
    int j;

    j = image_height - 1;
    //i = image_width;
    int j_inc = 0;
    float u;
    float v;
    void *mlx_ptr = mlx_init();
    void *mlx_img = mlx_new_image (mlx_ptr, image_width, image_height);
    void *mlx_window = mlx_new_window(mlx_ptr, image_width, image_height, "first camera");
    while (j >= 0)
    {
        i = 0;
        while (i < image_width)
        {
            t_s_vect3f dir;
            u = (float)i / (image_width - 1);
            v = (float)j / (image_height - 1);
            dir = s_vec3f_add(lower_left_corner, s_vec3f_multi(horizontal, u));
            dir = s_vec3f_add(dir, s_vec3f_multi(vertical, v));
            dir = s_vec3f_sub(dir, origin);
            t_ray *r = ray(&origin, &dir);
            t_s_vect3f pixel_color = ray_color(r);
            mlx_pixel_put(mlx_ptr, mlx_window, i, j_inc, create_pixel(0, pixel_color.x * 255, pixel_color.y * 255, pixel_color.z * 255));
            ray_destroy(r);
            i++;
        }
        j_inc++;
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
            ray_destroy (r);
        }
    }
    */
    mlx_loop(mlx_ptr);
    mlx_destroy_window(mlx_ptr, mlx_window);
    mlx_destroy_image (mlx_ptr, mlx_img);

    return (0);
}
