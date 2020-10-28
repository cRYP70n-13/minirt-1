#include "hittable.h"
#include "math.h"

typedef struct s_sphere t_sphere;

struct s_sphere
{
    t_s_vect3f center;
    float radius;
    t_hit_record hr;
	t_hit hit;
};

t_quadatric_equat_sol solve_quadatric(t_ray *r, t_sphere *s);

bool sphere_hit (void *shape, t_ray *r, float t_min, float t_max, t_hit_record *rec);