#include "rays.h"

/**
*	@description => The ray constructor function
* 	@param => Ray's origin (P = A + tB) {A :: Orig}
*	@param => Ray's direction (P = A + tB) {b :: Direc}
*	@return => pointer to the constructed ray
**/
t_ray *ray(t_vect3f origin, t_vect3f direction)
{
	t_ray *r;

	if (!(r = malloc(sizeof(struct s_ray))))
        return NULL;
	r->origin = vec3f(0, 0, 0, VECTOR);
	r->direction = vec3f(0, 0, 0, VECTOR);
	r->result_ray = vec3f(0, 0, 0, VECTOR);
	vec3f_copy(origin, r->origin);
	vec3f_copy(direction, r->direction);
	return (r);
}

/**
*	@function => The ray Destoryer function
*	@return => Nothing just freeing the damn memo
* */
void ray_destroy(t_ray *ray)
{
	free(ray->direction);
	free(ray->origin);
	free(ray->result_ray);
	free(ray);
}

/**
 * @description => Return the oerigin of our ray
 * @param => Pointer to ray struct
 * @returns => ray origin
 * **/
t_vect3f origin(t_ray *ray)
{
	return ray->origin;
}

/**
 * @description => Return the direction of our ray
 * @param => Pointer to ray struct
 * @returns => ray direction
 * **/
t_vect3f direction(t_ray *ray)
{
	return ray->direction;
}

t_vect3f at(double t, t_vect3f origin, t_vect3f direction)
{
	t_vect3f result;
	t_vect3f tmp;

	tmp = vec3f_multi(direction, t);
	result = vec3f_add(origin, tmp);
	free(tmp);
	return (result);
}
