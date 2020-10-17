#ifndef VECT3F_H
#define VECT3F_H

/*
** an implementiation of a 3 elements floats vector [x. y. z]
*/
typedef struct s_vect3f t_vect3f;

struct s_vect3f
{
	float x;
	float y;
	float z;
};

t_vect3f *vec3f(float x, float z, float w);

/*
** adding two 3 elements vectors
*/
t_vect3f *vec3f_add(t_vect3f t1, t_vect3f t2);

/*
** substracting two t_vect3s
*/
t_vect3f *vec3f_sub(t_vect3f t1, t_vect3f t2);

/*
** negating a t_vect3fle
*/
t_vect3f *vec3f_neg(t_vect3f t);

/*
** scalar multiplication
*/
t_vect3f *vec3f_multi(t_vect3f t, float s);

/*
** scalar division
*/
t_vect3f *vec3f_div(t_vect3f t, float d);

/*
** magnitude of a vector
*/
float *vec3f_mag(t_vect3f t);

/*
** normalize a vector
*/
t_vect3f *vec3f_norm(t_vect3f vec);

/*
** dot product of v1 and v2
*/
float *vec3f_dotproduct(t_vect3f v1, t_vect3f v2);

/*
** cross product of v1 and v2
*/
t_vect3f *vec3f_crossproduct(t_vect3f v1, t_vect3f v2);

#endif