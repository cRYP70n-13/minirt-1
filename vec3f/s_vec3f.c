#include "vec3f.h"

t_s_vect3f s_vec3f(float x, float y, float z)
{
    t_s_vect3f v;
    
    v.x = x;
    v.y = y;
    v.z = z;
    return (v);
}


t_s_vect3f s_vec3f_add(t_s_vect3f t1, t_s_vect3f t2)
{
    t_s_vect3f sum;

    sum = s_vec3f(0, 0, 0);
    sum.x = t1.x + t2.x;
    sum.y = t1.y + t2.y;
    sum.z = t1.z + t2.z;
    return (sum);
}

t_s_vect3f s_vec3f_sub(t_s_vect3f v1, t_s_vect3f v2)
{
    t_s_vect3f diff;

    diff = s_vec3f (0, 0, 0);
    diff.x = v1.x - v2.x;
    diff.y = v1.y - v2.y;
    diff.z = v1.z - v2.z;
    return (diff);
}

t_s_vect3f s_vec3f_neg(t_s_vect3f v)
{
    t_s_vect3f neg;

    neg = s_vec3f (0,0, 0);    
    neg.x = v.x * -1;
    neg.y = v.y * -1;
    neg.z = v.z * -1;
    return (neg);
}

t_s_vect3f s_vec3f_multi(t_s_vect3f t, float s)
{
    t_s_vect3f r;

    r = s_vec3f (0, 0, 0);
    r.x = t.x * s;
    r.y = t.y * s;
    r.z = t.z * s;
    return (r);
}

t_s_vect3f s_vec3f_div(t_s_vect3f t, float d)
{
    t_s_vect3f r;

    r = s_vec3f (0, 0, 0);
    r.x = t.x / d;
    r.y = t.y / d;
    r.z = t.z / d;
    return (r);
}

float s_vec3f_mag(t_s_vect3f vec)
{
    double m;

    m = 0;
    m = sqrt(pow(vec.x, 2) + pow(vec.y, 2) + pow(vec.z, 2));
    return (m);
}

t_s_vect3f s_vec3f_norm(t_s_vect3f vec)
{
    t_s_vect3f norm;
    double mag;

    norm = s_vec3f (0, 0, 0);
    mag = s_vec3f_mag(vec);
    norm.x = vec.x / mag;
    norm.y = vec.y / mag;
    norm.z = vec.z / mag;
    return norm;
}

float s_vec3f_dotproduct(t_s_vect3f v1, t_s_vect3f v2)
{
    return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
}

t_s_vect3f s_vec3f_crossproduct(t_s_vect3f v1, t_s_vect3f v2)
{
    t_s_vect3f cpv;

    cpv = s_vec3f (0, 0, 0);
    cpv.x = (v1.x * v2.z) - (v1.z * v2.y);
    cpv.y = (v1.z * v2.x) - (v1.x * v2.z);
    cpv.z = (v1.x * v2.y) - (v1.y * v2.x);
    return (cpv);
}

void s_vec3f_copy (t_s_vect3f *src, t_s_vect3f *dst)
{
    dst->x = src->x;
    dst->y = src->y;
    dst->z = src->z;
}

t_s_vect3f s_vec3f_random ()
{
    return (s_vec3f(genrate_random_number(), genrate_random_number(), genrate_random_number()));
}

t_s_vect3f random_in_unit_sphere ()
{
    while (1)
    {
        t_s_vect3f p;

        p = s_vec3f_random();
        if (s_vec3f_mag(p) >= 1)
            continue;
        return (p);
    }
}