#ifndef HITTABLE_LIST
# define HITTABLE_LIST
# include "sphere.h"
#include "hittable.h"
#include "hittable_list.h"

#define HITTABLE_LIST_DEFAULT_ALLOC 64

typedef struct s_hittable_list t_hittable_list;

struct s_hittable_list 
{
    t_hittable **data;
    int len;
    int alloc;
};

t_hittable *empty_hittable_list (int alloc);
t_hittable *hittable_list(void);

void hittable_add (t_hittable_list *hittable_list, t_hittable *hittable_ptr);
void hittable_destroy (t_hittable_list *hittable_list);
void hittable_destroy_with_freeing_hittables (t_hittable_list *hittable_list);

#endif
