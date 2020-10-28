#ifndef HITTABLE_H
#define HITTABLE_H

#include "rays/rays.h"
#include "vec3f/vec3f.h"

#define bool char
#define TRUE 1
#define FALSE 0

typedef struct s_hit_record t_hit_record;
typedef bool (*t_hit) (void *shape, t_ray *r, float t_min, float t_max, t_hit_record *rec);

struct s_hit_record
{
    t_s_vect3f p; //point
    t_s_vect3f normal;
    float t;
    bool front_face;
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

void set_face_normal(t_ray *r, t_s_vect3f outward_normal, t_hit_record *hr);

#endif