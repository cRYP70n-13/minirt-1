#ifndef RAYS_H
# define RAYS_H

# include "../utils/vec3f/vec3f.h"
# include "../utils/errors/errors.h"
# include <stdlib.h>
# include <stdio.h>

/*
*  The structure definition of the ray
* "CLASS"
* Basically the ray is a function that might be written like this:
* P(t) = A + tB
* p ==> 3D position along a line in 3D
* A ==> Is the ray origin
* B ==> Is the ray direction
* t ==> is the ray parameter (Real Number double)
* */

typedef struct s_ray t_ray;

 struct s_ray {
	double t;
	t_vect3f result_ray; // params (x, y, z) P = A + tB
	t_vect3f direction; // params (x, y, z)
	t_vect3f origin; // params (x, y, z)
};

t_ray *ray(t_vect3f origin, t_vect3f direction); // The ray constructor
void ray_destroy(t_ray *ray); // Free
t_vect3f origin(t_ray *ray); // => returns Origin
t_vect3f direction(t_ray *ray); // => returns the direction of the ray
t_vect3f at(double t, t_vect3f origin, t_vect3f direction); // returns orig + t * direction

#endif