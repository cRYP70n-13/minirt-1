#include "sphere.h"

t_sphere    *new_sphere(float radius, t_vect3f *color, t_vect3f center)
{
    t_sphere    *sphere;
    if (!(sphere = malloc(sizeof(t_sphere))))
        return NULL;
    sphere->radius = radius;
    sphere->colro = color;
    sphere->center = center;

    return (sphere);
}

void    destroy_sphere(t_sphere *sphere)
{
    free(sphere->center);
    free(sphere->color);
    free(sphere);
}

t_sphere    *cpy_sphere(t_sphere *sphere)
{
    t_sphere    *new_sphere;

    if (!(new_sphere = malloc(sizeof(t_sphere))))
        return NULL;
    new_sphere->radius = sphere->radius;
    new_sphere->center = cpy_vector(sphere->center);
    new_sphere->color = cpy_vector(sphere->color);

    return (new_sphere);
}
