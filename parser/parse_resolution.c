/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_resolution.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 15:38:14 by pguthaus          #+#    #+#             */
/*   Updated: 2020/05/11 17:41:06 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void					parse_resolution(char *line, t_carry *c)
{
	const t_line_spec	specs[3] = { INT, INT, NONE };
	t_line_result		*results;

	if (!(results = parse_line_specs(line, (t_line_spec *)specs, 1, c)))
		freexit(-42, "Allocation error", c);
	c->w->res[0] = ft_min(results[0].i, 1920);
	c->w->res[1] = ft_min(results[1].i, 1080);
	free((void *)results);
}
