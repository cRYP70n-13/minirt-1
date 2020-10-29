#ifndef HITTABLE_H
#define HITTABLE_H

# include "../rays/rays.h"
# include "../vec3f/vec3f.h"

# define bool char
# define TRUE 1
# define FALSE 0



typedef struct s_hit_record t_hit_record;
struct s_hit_record
{
    t_s_vect3f p; //point
    t_s_vect3f normal;
    float t;
    bool front_face;
};

typedef bool (*t_hit) (void *self, t_ray *r, float tmin, float tmax, t_hit_record *rec);

void hit_record_copy (t_hit_record *r1, t_hit_record *r2);

# define SPHERE 0
# define PLANE 1
# define SQUARE 2
# define CYLINDER 3
# define TRIANGLE 4

typedef struct s_hittable t_hittable;

struct s_hittable
{
    t_hit hit;
    void *shape;
    int type_of_shape;
};

typedef struct s_quadatric_equat_sol t_quadatric_equat_sol;

struct s_quadatric_equat_sol
{
    float a;
    float half_b;
    float c;
    float discriminant;
    int n_roots;
    float root1;
    float root2;
};

t_hittable hittable(t_hit hit, void *shape, int type_of_shape);
void set_face_normal(t_ray *r, t_s_vect3f outward_normal, t_hit_record *hr);

#endif