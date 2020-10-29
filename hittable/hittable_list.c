#include "hittable.h"
#include "hittable_list.h"

t_hittable *empty_hittable_list(int alloc)
{
    t_hittable_list *hitt_list;

    hitt_list = malloc(sizeof(struct s_hittable_list));
    hitt_list->data = malloc(alloc * sizeof(t_hittable_list *));
    hitt_list->len = 0;
    hitt_list->alloc = alloc;
    hitt_list->add = hittable_add;
    hitt_list->clear = hittable_destroy;
    hitt_list->clear_fully = hittable_destroy_with_freeing_hittables;
    hitt_list->hit = hittable_list_hit;
    return (hitt_list);
}

t_hittable *hittable_list(void)
{
    t_hittable_list *hitt_list;

    hitt_list = empty_hittable_list(HITTABLE_LIST_DEFAULT_ALLOC);
    return (hitt_list);
}

void hittable_add(void *_hittable_list, void *_hittable_ptr)
{
    t_hittable_list *hittable_list;
    t_hittable *hittable_ptr;

    hittable_list = (t_hittable_list*)_hittable_list;
    hittable_ptr = (t_hittable*)_hittable_ptr;
    if (hittable_list->len == hittable_list->alloc)
        return;
    hittable_list->data[hittable_list->len] = hittable_ptr;
    hittable_list->len++;
}

void hittable_destroy(void *_hittable_list)
{
    t_hittable_list *hittable_list;

    hittable_list = (t_hittable_list*) _hittable_list;
    free(hittable_list->data);
    free(hittable_list);
}

bool hittable_list_hit(void *self, t_ray *r, float tmin, float tmax, t_hit_record *rec)
{
    t_hittable_list *list;
    bool hit_anything;
    float closest_so_far;
    t_hit_record temp_rec;
    int i;

    i = 0;
    list = (t_hittable_list *)self;
    hit_anything = FALSE;
    closest_so_far = tmax;

    while (i < list->len)
    {
        if (list->data[i]->hit(list->data[i], r, tmin, tmax, rec)) 
        {
            hit_anything = TRUE;
            closest_so_far = temp_rec.t;
            hit_record_copy (rec, &temp_rec);
        }
        i++;
    }
    return (hit_anything);
}