#ifndef HITTABLE_LIST
# define HITTABLE_LIST
# include "sphere.h"
#include "hittable.h"
#include "hittable_list.h"
#include "../generic_arrptr/garrptr.h"
#define HITTABLE_LIST_DEFAULT_ALLOC 64

//typedef void (*t_add) (t_hittable_list *hittable_list, t_hittable *hittable_ptr);
//typedef void (*t_clear) (t_hittable_list *hittable_list);
//typedef void (*t_clear_fully) (t_hittable_list *hittable_list);
//typedef bool (*t_hit_list) (void *self, t_ray *r, float tmin, float tmax, t_hit_record *rec);


typedef struct s_hittable_list t_hittable_list;

struct s_hittable_list 
{
    t_hittable **data;
    int len;
    int alloc;
	//t_add add;
	//t_clear clear;
	//t_clear_fully clear_fully;
	//t_hit hit;
};




t_hittable_list *empty_hittable_list (int alloc);
t_hittable_list *hittable_list(void);

//void hittable_add(void *_hittable_list, void *_hittable_ptr);
//void hittable_destroy(void *_hittable_list);
//bool hittable_list_hit(void *self, t_ray *r, float tmin, float tmax, t_hit_record *rec);
//void hittable_destroy_with_freeing_hittables (void *_hittable_list);
bool hittable_list_hit(void *list, t_ray *r, float tmin, float tmax, t_hit_record *rec);
#endif
