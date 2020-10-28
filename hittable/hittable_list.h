#ifndef HITTABLE_LIST
# define HITTABLE_LIST
# include "sphere.h"



typedef struct s_hittable_list t_hittable_list;

struct s_hittable_list 
{
    t_hit *data;
    int len;
    int alloc;
};



#endif
