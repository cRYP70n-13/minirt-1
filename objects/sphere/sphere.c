#include "sphere.h"

/**
 * @brief -> Create a new sphere in the heap with the following cordiantes
 * @param -> The radius(floa) of the sphere and center(vect3f)
 * @return -> A pointer to the sphere
**/
t_sphere    *new_sphere(float radius, t_vect3f *color, t_vect3f *center)
{
	t_sphere    *sphere;
	if (!(sphere = malloc(sizeof(t_sphere))))
		error_handler(-1);
	sphere->radius = radius;
	sphere->color = color;
	sphere->center = center;

	return (sphere);
}

/**
 * @brief -> Freeing the allocated sphere to avoid leaks
 * @param -> A pointer to the sphere
 * @return -> VOID
**/
void    destroy_sphere(t_sphere *sphere)
{
	free(sphere->center);
	free(sphere->color);
	free(sphere);
}

/**
 * @brief -> Creates a new sphere and copy the cordinates of the first
			 to the second one
 * @param -> A pointer to the original sphere
 * @return -> Pointer to the new created sphere
 **/
t_sphere    *cpy_sphere(t_sphere *sphere)
{
	t_sphere    *new_sphere;

	if (!(new_sphere = malloc(sizeof(t_sphere))))
		error_handler(-1);
	new_sphere->radius = sphere->radius;
	new_sphere->center = cpy_vector(sphere->center);
	new_sphere->color = cpy_vector(sphere->color);

	return (new_sphere);
}
