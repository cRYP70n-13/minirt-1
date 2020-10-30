#include "hittable.h"

t_hittable *hittable(void *shape, int type_of_shape)
{
    t_hittable *h;

    h = malloc (sizeof(t_hittable));
    h->shape = shape;
    h->type_of_shape = type_of_shape;
    return (h);
}

void hittable_destroy (void *_hittable)
{
    t_hittable *hittable;

    hittable = (t_hittable*) _hittable;
    free(hittable);
}


void set_face_normal(t_ray *r, t_s_vect3f outward_normal, t_hit_record *hr)
{
    hr->front_face = s_vec3f_dotproduct(*r->direction, outward_normal) < 0;
    hr->normal = hr->front_face ? outward_normal : outward_normal;
}

void hit_record_copy (t_hit_record *src, t_hit_record *dst)
{
    dst->front_face = src->front_face;
    dst->normal = src->normal;
    dst->p = src->p;
    dst->t = src->t;
}