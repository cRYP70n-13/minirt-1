#include "rays.h"

/**
*	@description => The ray constructor function
* 	@param => Ray's origin (P = A + tB) {A :: Orig}
*	@param => Ray's direction (P = A + tB) {b :: Direc}
*	@return => pointer to the constructed ray
**/
t_ray	*ray(t_vect3f *origin, t_vect3f *direction)
{
	// TODO: Implement the ray constructor
}

/**
*	@function => The ray Destoryer function
*	@return => Nothing just freeing the damn memo
* */
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
 * **/
t_vect3f	*origin(t_ray *ray)
{
	return ray->origin;
}

/**
 * @description => Return the direction of our ray
 * @param => Pointer to ray struct
 * @returns => ray direction
 * **/
t_vect3f	*direction(t_ray *ray)
{
	return ray->direction;
}

// Still have a damn error here
t_vect3f	*at(double t, t_vect3f *origin, t_vect3f *direction)
{
	// TODO: correct this shit
	return origin + (direction * t);
}