#include "cylindre.h"

/**
 * @@ Constructor
 * @brief -> Create a new cylindre in the heap with the following cordinates
 * @param -> center(t_vec3f) radius height color(t_vec3f)
 * @return -> A pointer to the created cylindre
*/
t_cylindre		*new_cylindre(t_vect3f *center, float radius, float height, t_vect3f *color)
{
	t_cylindre	*cylindre;

	if (!(cylindre = malloc(sizeof(t_cylindre))))
		error_handler(-1);
	cylindre->center = center;
	cylindre->height = height;
	cylindre->radius = radius;
	cylindre->color = color;

	return (cylindre);
}

/**
 * @@Destructor
 * @brief -> Deallocating all the allocated memory
 * @param -> Pointer to the cylinder
 * @return -> VOID
*/
void	destroy_cylindre(t_cylindre *cylindre)
{
	free(cylindre->center);
	free(cylindre->color);
	free(cylindre);
}