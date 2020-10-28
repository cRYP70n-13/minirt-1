#include "sphere.h"

t_sphere sphere (t_s_vect3f cen, float r)
{
	t_sphere s;

	s_vec3f_copy(&cen, &s.center);
	s.radius = r;
}



t_quadatric_equat_sol solve_quadatric(t_ray *r, t_sphere *s)
{
	t_quadatric_equat_sol sol;
	t_s_vect3f oc;
	float tmp;

	oc = s_vec3f_sub (*(r->origin), s->center);
	sol.a = pow (s_vec3f_mag(*(r->direction)), 2);
	sol.half_b = s_vec3f_dotproduct (oc, *(r->direction));
	sol.c = pow (s_vec3f_mag(oc), 2) - pow(s->radius, 2);
	sol.discriminant = sol.half_b * sol.half_b - sol.a * sol.c;	
	if (sol.discriminant > 0)
	{
		sol.n_roots = 2;
		sol.root1 = (-sol.half_b - sqrt(sol.discriminant)) / sol.a;
		sol.root2 = (-sol.half_b + sqrt (sol.discriminant) / sol.a);
	}
	return (sol);
}

bool sphere_hit (t_sphere sph, t_ray *r, float t_min, float t_max, t_hit_record *rec)
{
	t_quadatric_equat_sol sol;
	t_s_vect3f outward_normal;
	
	sol = solve_quadatric (r, &sph);
	if (sol.discriminant > 0)
	{
		if (sol.root1 < t_max && sol.root1 > t_min)
		{
			rec->t = sol.root1;
			rec->p = *at(rec->t, r->origin, r->direction);
			outward_normal = s_vec3f_div(s_vec3f_sub (rec->p , sph.center), sph.radius);
			set_face_normal (r, outward_normal, rec);
			return (TRUE);
		}

		if (sol.root2 < t_max && sol.root2 > t_min)
		{
			rec->t = sol.root2;
			rec->p = *at(rec->t, r->origin, r->direction);
			outward_normal = s_vec3f_div(s_vec3f_sub (rec->p , sph.center), sph.radius);
			set_face_normal (r, outward_normal, rec);
			return (TRUE);
		}
	}

	return (FALSE);

}