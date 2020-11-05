#ifndef SPHERE_H
# define SPHERE_H

# include "../vec3f/vec3f.h"
# include "../errors/errors.h"
/**
 * The class definition of the SPHERE
 * We can represent a sphere by a center and a radius
 * the center is a 3 points in the space and the radius
 * is a float variable
**/
typedef struct s_sphere {
    t_vect3f    *center;
    // I think we gonna need to color it next time
    t_vect3f    *color;
    float       radius;
}               t_sphere;

t_sphere    *new_sphere(float radius, t_vect3f *color, t_vect3f *center);
void        destroy_sphere(t_sphere *sphere);
t_sphere    *cpy_sphere(t_sphere *sphere);

#endif
