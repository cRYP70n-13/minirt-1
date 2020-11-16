/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_camera.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 15:38:00 by pguthaus          #+#    #+#             */
/*   Updated: 2020/05/11 15:38:01 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "minirt.h"

void					parse_camera(char *line, t_carry *c)
{
	const t_line_spec	specs[4] = { VEC3F, NVEC3F, INT, NONE };
	t_line_result		*results;
	t_camera			*cams[c->w->cameras_count];
	unsigned int		i;

	if (!(results = parse_line_specs(line, (t_line_spec *)specs, 1, c)))
		freexit(-42, "Allocation error", c);
	i = 0;
	while (i < c->w->cameras_count && (cams[i] = c->w->cameras[i]))
		i++;
	free(c->w->cameras);
	if (!(c->w->cameras = malloc(sizeof(t_camera *) * i)))
		freexit(-42, "Allocation failed", c);
	i = 0;
	while (i < c->w->cameras_count && (c->w->cameras[i] = cams[i]))
		i++;
	if (!(c->w->cameras[i] = malloc(sizeof(t_camera))))
		freexit(-42, "Allocation failed", c);
	c->w->cameras[i]->position = results[0].vec3f;
	c->w->cameras[i]->rotation = results[1].vec3f;
	c->w->cameras[i]->fov = results[2].i;
	set_camera_axes(c->w->cameras[i]);
	c->w->cameras_count++;
	free((void *)results);
}
