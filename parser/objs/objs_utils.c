/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/12/17 06:48:38 by pguthaus          #+#    #+#             */
/*   Updated: 2020/01/06 19:41:17 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"
#include "minirt.h"

void				add_obj(t_obj *obj, t_carry *c)
{
	t_obj			*objs[c->w->objs_count];
	unsigned int	i;

	i = 0;
	while (i < c->w->objs_count && (objs[i] = c->w->objs[i]))
		i++;
	free(c->w->objs);
	if (!(c->w->objs = malloc(sizeof(t_obj *) * i + 1)))
		freexit(-42, "Allocation failed", c);
	i = 0;
	while (i < c->w->objs_count)
	{
		c->w->objs[i] = objs[i];
		i++;
	}
	c->w->objs[i] = obj;
	c->w->objs_count++;
}
