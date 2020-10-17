#ifndef RAY_H
# define RAY_h

# include "../vec3f.h"

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
struct s_ray {
	double t;
	double P;
	double A;
	double B;
};

#endif