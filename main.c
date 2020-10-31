#include <stdio.h>
#include "rays/rays.h"
#include "vec3f/vec3f.h"
//#include "mlx.h"
//#include "image/image.h"
#include "hittable/hittable.h"
#include "hittable/hittable_list.h"
#include <float.h>
#include "SFML/Graphics.h"
#include "csfml.h"

typedef unsigned int t_imgcmp;
typedef unsigned int t_trgb;

t_trgb create_pixel(int t, int r, int g, int b);
int get_t(int t_trgb);
int get_r(int t_trgb);
int get_g(int t_trgb);
int get_b(int t_trgb);

t_trgb create_pixel(int t, int r, int g, int b)
{
    return (t << 24 | (r << 16) | (g << 8) | b);
}

/*
**  getting transparency, red, green, blue out of t_trgb 
*/
int get_t(int t_trgb)
{
    return (t_trgb >> 24);
}

int get_r(int t_trgb)
{
    return (t_trgb >> 16);
}

int get_g(int t_trgb)
{
    return (t_trgb >> 8 & 0xff);
}

int get_b(int t_trgb)
{
    return (t_trgb & 0xFF);
}

t_s_vect3f ray_color(t_ray *r, t_arrptr world)
{
    t_s_vect3f unit_direction;
    float t;
    t_s_vect3f result;
    t_s_vect3f sphere_center;
    t_hit_record rec;

    if (hittable_list_hit(world, r, 0, FLT_MAX, &rec))
        return s_vec3f_multi(s_vec3f_add(rec.normal, s_vec3f(1, 1, 1)), 0.5);
    unit_direction = s_vec3f_norm(*(r->direction));
    t = 0.5 * (unit_direction.y + 1);
    result = s_vec3f_add(s_vec3f_multi(s_vec3f(1, 1, 1), (1.0 - t)), s_vec3f_multi(s_vec3f(0.5, 0.7, 1.0), t));
    return (result);
}

int main(void)
{

       //image
    float aspect_ratio = 16.0 / 9.0;
    int image_width = 600;
    int image_height = (int)image_width / aspect_ratio;

    //World

    t_arrptr world;
    world = hittable_list();

    t_sphere sp1 = sphere(s_vec3f(0, 0, -1), 0.5);
    t_hittable *shape1 = hittable(&sp1, SPHERE);
    t_sphere sp2 = sphere(s_vec3f(0, -100.5, -1), 100);
    t_hittable *shape2 = hittable(&sp2, SPHERE);
    hittable_add(world, shape1);
    hittable_add(world, shape2);

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

    // RENDER

    int i;
    int j;

    j = image_height - 1;
    //i = image_width;
    int j_inc = 0;
    float u;
    float v;
    //  void *mlx_ptr = mlx_init();

    //void *mlx_window = mlx_new_window(mlx_ptr, image_width, image_height, "first camera");
    //t_image *img = mlx_create_img(mlx_ptr, image_width, image_height);
    mlx_window mlx = mlx_window_init(image_width, image_height, "boobs", sfColor_fromRGB(255, 255, 255));
    /*
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
            t_s_vect3f pixel_color = ray_color(r, world);

            //      img_set_pixel(img, i, j, create_pixel(0, pixel_color.x * 255, pixel_color.y * 255, pixel_color.z * 255));
            sfImage_setPixel(mlx.image, i, j, sfColor_fromRGB(pixel_color.x * 255, pixel_color.y * 255, pixel_color.z * 255));
            ray_destroy(r);
            i++;
        }
        j_inc++;
        j--;
    }

    */
    //mlx_put_image_to_window(mlx_ptr, mlx_window, img->mlx_img, 0, 0);
    //mlx_loop(mlx_ptr);
    //mlx_destroy_window(mlx_ptr, mlx_window);
    //mlx_img_destroy(img);

    while (sfRenderWindow_isOpen(mlx.window))
    {
        while (sfRenderWindow_pollEvent(mlx.window, &mlx.event))
        {
            if (mlx.event.type == sfEvtClosed)
                sfRenderWindow_close(mlx.window);
        }
        j = 0;
        j = image_height - 1;
        //i = image_width;
        int j_inc = 0;
        float u;
        float v;
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
                t_s_vect3f pixel_color = ray_color(r, world);
                //      img_set_pixel(img, i, j, create_pixel(0, pixel_color.x * 255, pixel_color.y * 255, pixel_color.z * 255));
                sfImage_setPixel(mlx.image, i, j_inc, sfColor_fromRGB(pixel_color.x * 255, pixel_color.y * 255, pixel_color.z * 255));
                ray_destroy(r);
                i++;
            }
            j_inc++;
            j--;
        }
        mlx_update (&mlx);

        sfRenderWindow_clear (mlx.window, sfColor_fromRGBA(0, 0, 0, 255));
        sfRenderWindow_drawSprite (mlx.window, mlx.sprite, NULL);
        sfRenderWindow_display (mlx.window);
    }

    mlx_delete(&mlx);
    return (0);
}