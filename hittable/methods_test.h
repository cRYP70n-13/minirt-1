#ifndef METHODS_TEST_H
#define METHODS_TEST_H
#include "hittable.h"

# define bool char
# define TRUE 1
# define FALSE 0

typedef void (*t_add) (void *self, void *item);
typedef void (*t_clear) (void *self);
typedef void (*t_clear_fully) (void *self);
typedef bool (*t_hit) (void *self, t_ray *r, float tmin, float tmax, t_hit_record *rec);
#endif