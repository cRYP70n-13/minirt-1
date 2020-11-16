/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_sphere.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 15:36:53 by pguthaus          #+#    #+#             */
/*   Updated: 2020/05/11 15:36:56 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "minirt.h"

void					parse_sphere(char *line, t_carry *c)
{
	const t_line_spec	specs[4] = { VEC3F, FLOAT, COLOR, NONE };
	t_line_result		*results;
	t_obj				*obj;

	if (!(results = parse_line_specs(line, (t_line_spec *)specs, 2, c)))
		freexit(-42, "Allocation error", c);
	if (!(obj = malloc(sizeof(t_obj))))
		freexit(-42, "Allocation failed", c);
	obj->type = SPHERE;
	new_sphere(&obj->obj.sphere, results);
	add_obj(obj, c);
	free((void *)results);
}
