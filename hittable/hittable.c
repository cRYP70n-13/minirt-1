#include "hittable.h"

void set_face_normal(t_ray *r, t_s_vect3f outward_normal, t_hit_record *hr)
{
    hr->front_face = s_vec3f_dotproduct(*r->direction, outward_normal) < 0;
    hr->normal = hr->front_face ? outward_normal : outward_normal;
}

