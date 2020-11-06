#include <stdio.h>
#include "rays/rays.h"
#include "vec3f/vec3f.h"
//#include "mlx.h"
//#include "image/image.h"
#include "hittable/hittable.h"
#include "hittable/hittable_list.h"
#include <float.h>
#include "limits.h"
#include "SFML/Graphics.h"
#include "csfml.h"
#include "camera.h"

t_s_vect3f ray_color(t_ray r, t_arrptr world, int depth)
{
    t_s_vect3f unit_direction;
    float t;
    t_s_vect3f result;
    t_s_vect3f sphere_center;
    t_hit_record rec;

    if (depth <= 0)
        return (s_vec3f (0, 0, 0));

    if (hittable_list_hit(world, &r, 0, FLT_MAX, &rec))
    {
        t_s_vect3f target = s_vec3f_add(rec.p, rec.normal);
        target = s_vec3f_add(target, random_in_unit_sphere());
        t_s_vect3f tmp = s_vec3f_sub(target, rec.p);
        return s_vec3f_multi(ray_color(s_ray(&rec.p, &tmp), world, depth-1), 0.5);
        //return s_vec3f_multi(s_vec3f_add(rec.normal, s_vec3f(1, 1, 1)), 0.5);
    }
    //return s_vec3f_multi(s_vec3f_add(rec.normal, s_vec3f(1, 1, 1)), 0.5);
    unit_direction = s_vec3f_norm(*(r.direction));
    t = 0.5 * (unit_direction.y + 1);
    result = s_vec3f_add(s_vec3f_multi(s_vec3f(1, 1, 1), (1.0 - t)), s_vec3f_multi(s_vec3f(0.5, 0.7, 1.0), t));
    //result = s_vec3f(0, 0, 0);
    return (result);
}

int main(void)
{

    //image
    float aspect_ratio = 16.0 / 9.0;
    int image_width = 800;
    int image_height = (int)image_width / aspect_ratio;
    int samples_per_pixel = 100;
    float ratio = 1.0 / samples_per_pixel;

    //random number
    unsigned int rand = lfsr113_Bits();

    //World

    t_arrptr world;
    world = hittable_list();

    t_sphere sp1 = sphere(s_vec3f(0, 0, -1), 0.5);
    t_hittable *shape1 = hittable(&sp1, SPHERE);
    t_sphere sp2 = sphere(s_vec3f(0, -100.5, -1), 100);
    t_hittable *shape2 = hittable(&sp2, SPHERE);
    hittable_add(world, shape1);
    hittable_add(world, shape2);

    // RENDER
    t_camera cam = camera ();
    int i;
    int j;

    mlx_window mlx = mlx_window_init(image_width, image_height, "window", sfColor_fromRGB(255, 255, 255));

    j = 0;
    j = image_height - 1;
    //i = image_width;
    int j_inc = 0;
    float u;
    float v;
    t_ray r;

    while (j >= 0)
    {
        i = 0;
        while (i < image_width)
        {

            t_s_vect3f dir;
            t_s_vect3f pixel_color = s_vec3f(0, 0, 0);
            // for (int k = 0; k < samples_per_pixel; k++)
            // {
                // u = ((float)i + ((float)lfsr113_Bits() / UINT_MAX)) / (image_width - 1);
                // v = ((float)j + ((float)lfsr113_Bits() / UINT_MAX)) / (image_height - 1);
                u = ((float)i / (image_width - 1));
                v = ((float)j / (image_height - 1));
                r = get_ray (cam, u, v);
                pixel_color = s_vec3f_add(pixel_color, ray_color(&r, world));
                //pixel_color = ray_color (r, world);
            // }
            // pixel_color.x /= 100;
            // pixel_color.y /= 100;
            // pixel_color.z /= 100;
            sfImage_setPixel(mlx.image, i, j_inc, sfColor_fromRGB(pixel_color.x * 255, pixel_color.y * 255, pixel_color.z * 255));
            i++;
        }
        j_inc++;
        j--;
    }

    mlx_update(&mlx);
    sfRenderWindow_clear(mlx.window, sfColor_fromRGBA(0, 0, 0, 255));
    sfRenderWindow_drawSprite(mlx.window, mlx.sprite, NULL);
    sfRenderWindow_display(mlx.window);

    while (sfRenderWindow_isOpen(mlx.window))
    {
        while (sfRenderWindow_pollEvent(mlx.window, &mlx.event))
        {
            if (mlx.event.type == sfEvtClosed)
                sfRenderWindow_close(mlx.window);
        }
        //mlx_update(&mlx);

        //sfRenderWindow_clear(mlx.window, sfColor_fromRGBA(0, 0, 0, 255));
        //sfRenderWindow_drawSprite(mlx.window, mlx.sprite, NULL);
        //sfRenderWindow_display(mlx.window);
    }

    mlx_delete(&mlx);
    return (0);
}