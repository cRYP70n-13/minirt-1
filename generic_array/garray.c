#include "garray.h"

t_array empty_array_create(t_destructor obj_des)
{
    // TODO: Wait for pizzaboi to explain me WTF is going on here
}

t_array empty_array_create_size(int size, t_destructor obj_des);
void array_destroy(t_array *a);
void *array_get(t_array a, int index);
void array_set(t_array a, int index, void *obj);
void array_add(t_array a, void *obj);
void    *ft_memcpy(void *dst, const void *src, size_t n);