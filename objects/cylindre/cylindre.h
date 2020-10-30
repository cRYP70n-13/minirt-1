#ifndef CYLINDRE_H
# define CYLINDRE_H

# include "../vec3f/vec3f.h"
# include "../errors/errors.h"

typedef struct s_cylindre {
	t_vect3f    *center;
	float height;
	float radius;
	t_vect3f	*color;

	// Still needs a lot of shit to do here 😩
	t_vect3f    *color;
}               t_cylindre;

t_cylindre      *new_cylindre(t_vect3f *center, float radius, float height, t_vect3f *color);
void            destroy_cylindre(t_cylindre *cylindre);

#endif
