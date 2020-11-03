#ifndef CAMERA_H
#define CAMERA_H

# include "vec3f/vec3f.h"
# include "rays/rays.h"
# include "tools.h"

typedef struct s_camera t_camera;

struct s_camera
{
    t_s_vect3f origin;    
    t_s_vect3f lower_left_corner;
    t_s_vect3f horizontal;
    t_s_vect3f vertical;
};

t_camera camera ();

t_ray get_ray (t_camera cam, double u, double v);


#endif