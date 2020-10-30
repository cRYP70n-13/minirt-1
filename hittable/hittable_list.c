#include "hittable.h"
#include "hittable_list.h"
#include "../generic_arrptr/garrptr.h"

t_arrptr empty_hittable_list(int alloc)
{
    t_arrptr hitt_list;

    hitt_list = empty_arrptr_create_size(alloc, hittable_destroy);
    return (hitt_list);
}

t_arrptr hittable_list(void)
{
    t_arrptr hitt_list;

    hitt_list = empty_hittable_list(HITTABLE_LIST_DEFAULT_ALLOC);
    return (hitt_list);
}

void hittable_add(t_arrptr _hittable_list, t_hittable *_hittable)
{
    arrptr_add(_hittable_list, _hittable);
}

t_hittable *hittable_get(t_arrptr hittable_list, int index)
{
    void *_hittable;
    t_hittable *hittable;

    _hittable = arrptr_get(hittable_list, index);
    hittable = (t_hittable *)_hittable;
    return (hittable);
}

bool hittable_list_hit(void *_list, t_ray *r, float tmin, float tmax, t_hit_record *rec)
{
    t_arrptr list;
    bool hit_anything;
    float closest_so_far;
    t_hit_record temp_rec;
    int i;
    t_hittable *shape;

    i = 0;
    list = (t_arrptr)_list;
    hit_anything = FALSE;
    closest_so_far = tmax;

    while (i < list->len)
    {
        shape = hittable_get(list, i);
        //if (list->data[i]->hit(list->data[i], r, tmin, tmax, rec))
        if (shape->hit(shape->shape, r, tmin, tmax, rec))
        {
            hit_anything = TRUE;
            closest_so_far = temp_rec.t;
            hit_record_copy(rec, &temp_rec);
        }
        i++;
    }
    return (hit_anything);
}