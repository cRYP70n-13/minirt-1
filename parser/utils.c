/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/11 15:38:22 by pguthaus          #+#    #+#             */
/*   Updated: 2020/05/11 15:57:41 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parser.h"

static int					parse_int(char *line, unsigned int *pos, t_carry *c)
{
	int						res;

	res = 0;
	if (ft_isdigit(line[*pos]) || line[*pos] == '-')
		res = ft_atoi(&line[*pos]);
	while (ft_isdigit(line[*pos]) || line[*pos] == '-')
		(*pos)++;
	if (line[*pos] && !(ft_isspace(line[*pos])))
		parse_error(line, *pos, "Int error", c);
	return (res);
}

static float				parse_float(char *line, unsigned int *pos,
	t_carry *c)
{
	float					res;

	res = 0;
	if (ft_isdigit(line[*pos]) || line[*pos] == '-' || line[*pos] == '.')
		res = ft_atof(&line[*pos]);
	while (ft_isdigit(line[*pos]) || line[*pos] == '-' || line[*pos] == '.')
		(*pos)++;
	if (line[*pos] && !(ft_isspace(line[*pos])))
		parse_error(line, *pos, "Float error", c);
	return (res);
}

static t_color				parse_color(char *line, unsigned int *pos,
	t_carry *c)
{
	uint8_t					tmp[3];
	uint8_t					i;

	i = 0;
	while (i < 3)
	{
		if (!ft_isdigit(line[*pos]))
			parse_error(line, *pos, "Color error", c);
		tmp[i] = ft_atoi(&line[*pos]);
		while (ft_isdigit(line[*pos]))
			(*pos)++;
		if (line[*pos] != ',' && i != 2)
			parse_error(line, *pos, "Color error", c);
		(*pos)++;
		i++;
	}
	return (ft_color_rgb(tmp[0], tmp[1], tmp[2]));
}

static t_vec3f				parse_vec3f(char *line, unsigned int *pos,
	t_bool normalized, t_carry *c)
{
	float					tmp[3];
	uint8_t					i;

	i = 0;
	while (i < 3)
	{
		if (!ft_isdigit(line[*pos]) && line[*pos] != '-' && line[*pos] != '.')
			parse_error(line, *pos,
				"Vec error, should be formatted like this: 0.5,-3.4,5.4", c);
		tmp[i] = ft_atof(&line[*pos]);
		if (normalized && (tmp[i] < -1.0f || tmp[i] > 1.0f))
			parse_error(line, *pos, "Vec shoul be normalized", c);
		while (ft_isdigit(line[*pos]) || line[*pos] == '-' || line[*pos] == '.')
			(*pos)++;
		if (line[*pos] != ',' && i != 2)
			parse_error(line, *pos,
				"Vec error, don't put a space before a coma", c);
		(*pos)++;
		i++;
	}
	return (v3f_init(tmp[0], tmp[1], tmp[2]));
}

t_line_result				*parse_line_specs(char *line, t_line_spec *specs,
	unsigned int pos, t_carry *c)
{
	t_line_result			*results;
	uint8_t					i;

	if (!(results = malloc(SPEC_MAX * sizeof(t_line_result))))
		return (NULL);
	i = 0;
	while (specs[i] && i < SPEC_MAX)
	{
		while (line[pos] && ft_isspace(line[pos]))
			pos++;
		if (specs[i] == INT)
			results[i].i = parse_int(line, &pos, c);
		else if (specs[i] == FLOAT)
			results[i].f = parse_float(line, &pos, c);
		else if (specs[i] == COLOR)
			results[i].color = parse_color(line, &pos, c);
		else if (specs[i] == VEC3F)
			results[i].vec3f = parse_vec3f(line, &pos, false, c);
		else if (specs[i] == NVEC3F)
			results[i].vec3f = parse_vec3f(line, &pos, true, c);
		i++;
	}
	return (results);
}
