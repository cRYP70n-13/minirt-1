#include <stdio.h>
#include "rays/rays.h"
#include "vec3f/vec3f.h"
#include "mlx.h"
#include "image/image.h"
#include "hittable/hittable.h"
#include "hittable/hittable_list.h"

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
    result = s_vec3f_add(s_vec3f_multi(s_vec3f(1, 1, 1), (1.0 - t)), s_vec3f_multi(s_vec3f(0.5, 0.7, 1.0), t));
    return (result);
}


int main(void)
{

    //image
    float aspect_ratio = 16.0 / 9.0;
    int image_width = 1000;
    int image_height = (int)image_width / aspect_ratio;

    //World

    t_hittable_list *world;
    world = hittable_list ();

    t_sphere sp1 = sphere(s_vec3f (0, 0, 0), 0.5);
    t_hittable shape1 = hittable (sphere_hit, &sp1, SPHERE);
    t_sphere sp2 = sphere(s_vec3f (0, 0, 0), 0.5);
    t_hittable shape2 = hittable (sphere_hit, &sp1, SPHERE);
    hittable_add (world, &shape1);
    //camera (eye) / screen

    float viewport_height = 2.0;
    float viewport_width = aspect_ratio * viewport_height;
    float focal_length = 1.0;

    t_s_vect3f origin = s_vec3f(0, 0, 0);
    t_s_vect3f horizontal = s_vec3f(viewport_width, 0, 0);
    t_s_vect3f vertical = s_vec3f(0, viewport_height, 0);
    t_s_vect3f lower_left_corner = s_vec3f_sub(origin, s_vec3f_div(horizontal, 2));
    lower_left_corner = s_vec3f_sub(lower_left_corner, s_vec3f_div(vertical, 2));
    lower_left_corner = s_vec3f_sub(lower_left_corner, s_vec3f(0, 0, focal_length));



/*
    // RENDER

    int i;
    int j;

    j = image_height - 1;
    //i = image_width;
    int j_inc = 0;
    float u;
    float v;
    void *mlx_ptr = mlx_init();
    
    void *mlx_window = mlx_new_window(mlx_ptr, image_width, image_height, "first camera");
    t_image *img =  mlx_create_img (mlx_ptr, image_width, image_height);
    //img_set_pixel (img, 0, 0, create_pixel(0, 255, 255, 255));
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
            //mlx_pixel_put(mlx_ptr, mlx_window, i, j_inc, create_pixel(0, pixel_color.x * 255, pixel_color.y * 255, pixel_color.z * 255));
            img_set_pixel (img, i, j, create_pixel(0, pixel_color.x * 255, pixel_color.y * 255, pixel_color.z * 255));
            ray_destroy(r);
            i++;
        }
        j_inc++;
        j--;
    }
    mlx_put_image_to_window (mlx_ptr, mlx_window, img->mlx_img, 0, 0);
    mlx_loop(mlx_ptr);
    mlx_destroy_window(mlx_ptr, mlx_window);
   mlx_img_destroy (img);
*/
    return (0);
}