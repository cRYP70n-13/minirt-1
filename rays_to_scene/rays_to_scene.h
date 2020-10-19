#ifndef RAYS_TO_SCENE_H
# define RAYS_TO_SCENE_H

# include "../vec3f/vec3f.h"

typedef struct s_sphere {
    t_vect3f *center;
    float radius;
}   t_sphere;

// The header of our functions
bool ray_intersect(const t_vect3f *origin, const float radius); // Return true if the ray intersect with our sphere else false

// NOTE:: the sphere equation in the vector form = (P - C) . (P - C) = r^2

#endif