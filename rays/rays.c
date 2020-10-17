#include "rays.h"

/**
*	@description => The ray constructor function
* 	@param => Ray's origin (P = A + tB) {A :: Orig}
*	@param => Ray's direction (P = A + tB) {b :: Direc}
*	@return => pointer to the constructed ray
**/
t_ray	*ray(t_vect3f *origin, t_vect3f *direction)
{
	t_ray *r;

	if (!(r = malloc(sizeof(struct s_ray))))
		return NULL;
	r->origin->x = origin->x;
	r->origin->y = origin->y;
	r->origin->z = origin->z;
	return (r);
}

/**
*	@function => The ray Destoryer function
*	@return => Nothing just freeing the damn memo
**/
void	ray_destroy(t_ray *ray)
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
**/
t_vect3f	*origin(t_ray *ray)
{
	return ray->origin;
}

/**
* @description => Return the direction of our ray
* @param => Pointer to ray struct
* @returns => ray direction
**/
t_vect3f	*direction(t_ray *ray)
{
	return ray->direction;
}

/**
* @description => return the position of our vector in the space
* @param => t :: Real Param to give the direct of our vector
* 			 origin :: A pointer to the origin of our ray
* 			 direction :: the direction of our ray
* @returns => it actually solve this equation :: orig + t * direc
**/
t_vect3f	*at(double t, t_vect3f *origin, t_vect3f *direction)
{
	t_vect3f *result;
	t_vect3f *tmp;

	tmp = vec3f_multi(direction, t);
	result = vec3f_add(origin, tmp);
	free(tmp);
	return (result);
}