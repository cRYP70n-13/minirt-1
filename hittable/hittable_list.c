#include "hittable.h"
#include "hittable_list.h"

t_hittable *empty_hittable_list(int alloc)
{
    t_hittable_list *hitt_list;

    hitt_list = malloc(sizeof(struct s_hittable_list));
    hitt_list->data = malloc(alloc * sizeof(t_hittable_list*));
    hitt_list->len = 0;
    hitt_list->alloc = alloc;
    
    return (hitt_list);
}

t_hittable *hittable_list(void)
{
    t_hittable_list *hitt_list;

    hitt_list = empty_hittable_list (HITTABLE_LIST_DEFAULT_ALLOC);
    return (hitt_list);
}

void hittable_add (t_hittable_list *hittable_list, t_hittable *hittable_ptr)
{
    if (hittable_list->len == hittable_list->alloc)
        return ;
    hittable_list->data[hittable_list->len] = hittable_ptr;
    hittable_list->len++;
}

void hittable_destroy (t_hittable_list *hittable_list)
{
    free (hittable_list->data);
    free (hittable_list);
}