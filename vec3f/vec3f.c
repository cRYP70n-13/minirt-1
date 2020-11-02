#include "vec3f.h"
#include "stdio.h"
#include <stdlib.h>

t_vect3f vec3f(float x, float y, float z, char is_point_or_vector)
{
	t_vect3f v;

	if (!(v = malloc (sizeof(struct s_vect3f))))
		return NULL;
	v->x = x;
	v->y = y;
	v->z = z;
	v->is_point_or_vector = is_point_or_vector;
	v->al_in_heap_or_stack = HEAP;
	return (v);
}

void vec3f_destroy(t_vect3f vec)
{
	free (vec);
}

t_vect3f vec3f_add(t_vect3f t1, t_vect3f t2)
{
	t_vect3f sum;

	sum = vec3f(0, 0, 0, 0);
	sum->x = t1->x + t2->x;
	sum->y = t1->y + t2->y;
	sum->z = t1->z + t2->z;
	sum->is_point_or_vector = t1->is_point_or_vector + t2->is_point_or_vector;
	return (sum);
}

t_vect3f vec3f_sub(t_vect3f v1, t_vect3f v2)
{
	t_vect3f diff;

	diff = vec3f (0, 0, 0, 0);
	diff->x = v1->x - v2->x;
	diff->y = v1->y - v2->y;
	diff->z = v1->z - v2->z;
	diff->is_point_or_vector = v1->is_point_or_vector - v2->is_point_or_vector;
	return (diff);
}

t_vect3f vec3f_neg(t_vect3f v)
{
	t_vect3f neg;

	neg = vec3f (0,0, 0, v->is_point_or_vector);
	neg->x = v->x * -1;
	neg->y = v->y * -1;
	neg->z = v->z * -1;
	return (neg);
}

t_vect3f vec3f_multi(t_vect3f t, float s)
{
	t_vect3f r;

	r = vec3f (0, 0, 0, t->is_point_or_vector);
	r->x = t->x * s;
	r->y = t->y * s;
	r->z = t->z * s;
	return (r);
}

t_vect3f vec3f_div(t_vect3f t, float d)
{
	t_vect3f r;

	r = vec3f (0, 0, 0, t->is_point_or_vector);
	r->x = t->x / d;
	r->y = t->y / d;
	r->z = t->z / d;
	return (r);
}

float vec3f_mag(t_vect3f vec)
{
	double m;

	m = 0;
	m = sqrt(pow(vec->x, 2) + pow(vec->y, 2) + pow(vec->z, 2));

	return (m);
}

t_vect3f vec3f_norm(t_vect3f vec)
{
	t_vect3f norm;
	double mag;

	norm = vec3f (0, 0, 0, vec->is_point_or_vector);
	mag = vec3f_mag(vec);
	norm->x = vec->x / mag;
	norm->y = vec->y / mag;
	norm->z = vec->z / mag;
	return norm;
}

float vec3f_dotproduct(t_vect3f v1, t_vect3f v2)
{
	return ((v1->x * v2->x) + (v1->y * v2->y) + (v1->z * v2->z));
}

t_vect3f vec3f_crossproduct(t_vect3f v1, t_vect3f v2)
{
	t_vect3f cpv;

	cpv = vec3f (0, 0, 0, 0);
	cpv->x = (v1->x * v2->z) - (v1->z * v2->y);
	cpv->y = (v1->z * v2->x) - (v1->x * v2->z);
	cpv->z = (v1->x * v2->y) - (v1->y * v2->x);
	return (cpv);
}

void vec3f_copy (t_vect3f src, t_vect3f dst)
{
	dst->x = src->x;
	dst->y = src->y;
	dst->z = src->z;
	dst->al_in_heap_or_stack = src->al_in_heap_or_stack;
	dst->is_point_or_vector = src->is_point_or_vector;
}

// t_vect3f		*cpy_vector(t_vect3f *vector)
// {
// 	return (vec3f(vector->x, vector->y, vector->z));
//     // I still need khalil to know WTF is going on with the extra param in creating our vectors
// }
