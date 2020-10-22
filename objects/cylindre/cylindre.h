#ifndef CYLINDRE_H
# define CYLINDRE_H

# include "../vec3f/vec3f.h"

typedef struct s_cylindre {
    t_vect3f    *center;
    float diametre;
    float height;
    // Still needs a lot of shit to do here 😩
    t_vect3f    *color;
}               t_cylindre;

t_cylindre      *new_cylindre(t_vect3f *center, float diametre, float height);
void            destroy_cylindre(t_cylindre *cylindre);

#endif
