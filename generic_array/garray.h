#ifndef GARRAY_H
#define GARRAY_H
#include <stdio.h>

#define VECTOR_DEFAULT_ALLOC 64
typedef void (*t_destructor)(void *obj);
typedef struct s_array t_array;

struct s_array
{
    void *data;
    int len;
    int alloc;
    int cell_size;
    t_destructor obj_des;
};

t_array empty_array_create(t_destructor obj_des);
t_array empty_array_create_size(int size, t_destructor obj_des);
void array_destroy(t_array *a);

void *array_get(t_array a, int index);
void array_set(t_array a, int index, void *obj);
void array_add(t_array a, void *obj);
void    *ft_memcpy(void *dst, const void *src, size_t n);

#endif