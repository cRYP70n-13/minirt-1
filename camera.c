#include "camera.h"

t_camera camera()
{
	t_camera cam;
	float aspect_ratio;
	float viewport_height;
	float viewport_width;
	float focal_length;

	aspect_ratio = 16.0 / 9.0;
	viewport_height = 2.0;
	viewport_width = aspect_ratio * viewport_height;
	focal_length = 1.0;
	cam.origin = s_vec3f(0, 0, 0);
	cam.horizontal = s_vec3f(viewport_width, 0, 0);
	cam.vertical = s_vec3f(0, viewport_height, 0);
	cam.lower_left_corner = s_vec3f_sub(cam.origin, s_vec3f_div(cam.horizontal, 2));
	cam.lower_left_corner = s_vec3f_sub(cam.lower_left_corner, s_vec3f_div(cam.vertical, 2));
	cam.lower_left_corner = s_vec3f_sub(cam.lower_left_corner, s_vec3f(0, 0, focal_length));
	return (cam);
}

t_ray get_ray(t_camera cam, double u, double v)
{
	t_s_vect3f dir;

	dir = s_vec3f_add(cam.lower_left_corner, s_vec3f_multi(cam.horizontal, u));
	dir = s_vec3f_add(dir, s_vec3f_multi(cam.vertical, v));
	dir = s_vec3f_sub(dir, cam.origin);
	return s_ray(&cam.origin, &dir);
}