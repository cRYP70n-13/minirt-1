#include "vec3f.h"
#include "stdio.h"
#include <math.h>

t_vect3f vec3f(float x, float y, float z)
{
    t_vect3f v;

    v.x = x;
    v.y = y;
    v.z = z;
    return (v);
}

void vec3f_destroy (t_vect3f *vec)
{
    free (vec);
}

t_vect3f vec3f_add(t_vect3f t1, t_vect3f t2)
{
    t_vect3f sum;

    sum.x = t1.x + t2.x;
    sum.y = t1.y + t2.y;
    sum.z = t1.z + t2.z;
    return (sum);
}

t_vect3f vec3f_sub(t_vect3f t1, t_vect3f t2)
{
    t_vect3f diff;

    diff.x = t1.x - t2.x;
    diff.y = t1.y - t2.y;
    diff.z = t1.z - t2.z;
    return (diff);
}

t_vect3f vec3f_neg(t_vect3f t)
{
    t_vect3f neg;

    neg.x = t.x * -1;
    neg.y = t.y * -1;
    neg.z = t.z * -1;
    return (neg);
}

t_vect3f vec3f_multi(t_vect3f t, float s)
{
    t_vect3f r;

    r.x = t.x * s;
    r.y = t.y * s;
    r.z = t.z * s;
    return (r);
}

t_vect3f vec3f_div(t_vect3f t, float d)
{
    t_vect3f r;

    r.x = t.x / d;
    r.y = t.y / d;
    r.z = t.z / d;
    return (r);
}

float vec3f_mag(t_vect3f t)
{
    double m;

    m = 0;
    m = sqrt(pow(t.x, 2) + pow(t.y, 2) + pow(t.z, 2));

    return (m);
}

t_vect3f vec3f_norm(t_vect3f vec)
{
    t_vect3f norm;
    double mag;

    mag = vec3f_mag(vec);
    norm.x = vec.x / mag;
    norm.y = vec.y / mag;
    norm.z = vec.z / mag;
    return norm;
}

float vec3f_dotproduct(t_vect3f v1, t_vect3f v2)
{
    return ((v1.x * v2.x) + (v1.y * v2.y) + (v1.z * v2.z));
}

t_vect3f vec3f_crossproduct(t_vect3f v1, t_vect3f v2)
{
    t_vect3f cpv;

    cpv.x = (v1.x * v2.z) - (v1.z * v2.y);
    cpv.y = (v1.z * v2.x) - (v1.x * v2.z);
    cpv.z = (v1.x * v2.y) - (v1.y * v2.x);
    return (cpv);
}