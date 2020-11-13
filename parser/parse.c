/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pguthaus <pguthaus@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/11/12 19:49:16 by pguthaus          #+#    #+#             */
/*   Updated: 2020/05/07 18:39:46 by pguthaus         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "parser.h"
#include <fcntl.h>
#include <sys/types.h>

static void			line_router(char *line, t_carry *c)
{
	if (line[0] == '#')
		return ;
	if (line[0] == 'R' && ft_isspace(line[1]))
		parse_resolution(line, c);
	else if (line[0] == 'A' && ft_isspace(line[1]))
		parse_ambiant_light(line, c);
	else if (line[0] == 'c' && ft_isspace(line[1]))
		parse_camera(line, c);
	else if (line[0] == 'l' && ft_isspace(line[1]))
		parse_light(line, c);
	else if (line[0] == 's' && line[1] == 'p')
		parse_sphere(line, c);
	else if (line[0] == 'p' && line[1] == 'l')
		parse_plane(line, c);
	else if (line[0] == 's' && line[1] == 'q')
		parse_square(line, c);
	else if (line[0] == 'c' && line[1] == 'y')
		parse_cylinder(line, c);
	else if (line[0] == 't' && line[1] == 'r')
		parse_triangle(line, c);
	else if (line[0] != '\0')
		freexit(44, "Error line not well formated", c);
}

static void			parse(int fd, t_carry *c)
{
	char			*line;
	int				ret;

	while ((ret = get_next_line(fd, &line)) != -1)
	{
		if (ret == 0 && line[0] == 0)
			break ;
		line_router(line, c);
		free(line);
	}
	if (line)
		free((void *)line);
	if (ret == -1)
		freexit(43, "Error while reading file.", c);
	if (c->w->res[0] == 0 || c->w->res[1] == 0)
		freexit(44, "Please provide resolution", c);
	if (!c->w->ambiant_light)
		freexit(44, "Please provide ambiant light", c);
	if (c->w->cameras_count == 0)
		freexit(44, "Please provide at least one camera", c);
}

void				load_world(const char *file, t_carry *c)
{
	int				fd;

	if ((fd = open(file, O_RDONLY)) == -1)
		freexit(1, "The file you 've entered doesnt exist", c);
	if (!(c->w->cameras = malloc(sizeof(t_camera *))))
		freexit(-42, "Allocation failed", c);
	if (!(c->w->lights = malloc(sizeof(t_light *))))
		freexit(-42, "Allocation failed", c);
	if (!(c->w->objs = malloc(sizeof(t_obj *))))
		freexit(-42, "Allocation failed", c);
	parse(fd, c);
}
