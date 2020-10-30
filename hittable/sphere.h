#ifndef SPHERE_H
#define SPHERE_H

#include "hittable.h"
#include "math.h"

# define bool char
# define TRUE 1
# define FALSE 0

typedef struct s_sphere t_sphere;

struct s_sphere
{
    t_s_vect3f center;
    float radius;
    t_hit_record hr;
	t_hit hit;
};

t_sphere sphere (t_s_vect3f cen, float r);

t_quadatric_equat_sol solve_quadatric(t_ray *r, t_sphere *s);

bool sphere_hit (void *shape, t_ray *r, float t_min, float t_max, t_hit_record *rec);
#endif