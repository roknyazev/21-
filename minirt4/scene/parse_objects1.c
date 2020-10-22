/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_objects1.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 20:48:36 by wrudy             #+#    #+#             */
/*   Updated: 2020/10/22 20:54:52 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

void 			parse_resolution(const char *line, t_scene *scene)
{
	int i;

	i = 2;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (!ft_isdigit(line[i]))
		exit(1);
	scene->resolution_x = ft_atoi(&line[i]);
	//if (scene->resolution_x < 150)
	//	exit(1);
	while (ft_isdigit(line[i]))
		i++;
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (!ft_isdigit(line[i]))
		exit(1);
	scene->resolution_y = ft_atoi(&line[i]);
	//if (scene->resolution_y < 100)
	//	exit(1);
	while (ft_isdigit(line[i]))
		i++;
	if (line[i] != '\0')
		exit(1);
}

t_amblight 			*parse_amblight(const char *line)
{
	int i;
	double *nmb;
	t_color *color;
	t_amblight *result;

	i = 2;
	nmb = malloc(sizeof(double));
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	i = i + ft_atof(&line[i], nmb);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	if (!ft_isdigit(line[i]))
		exit(1);
	color = new_color(0, 0, 0);
	i = i + parse_color(&line[i], color);
	if (line[i] != '\0')
		exit(1);
	result = new_amblight(color, *nmb);
	free(nmb);
	return (result);
}

t_camera *			parse_camera(const char *line)
{
	int i;
	double *nmb;
	t_vector *pos;
	t_vector *orient;
	t_camera *result;

	i = 2;
	nmb = malloc(sizeof(double));
	pos = new_vector(0, 0, 0);
	orient = new_vector(0, 0, 0);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	i = i + parse_pos(&line[i], pos);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	i = i + parse_orient(&line[i], orient);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	i = i + ft_atof(&line[i], nmb);
	if (*nmb > 180. || *nmb < 0)
		exit(1);
	if (line[i] != '\0')
		exit(1);
	result = new_camera(pos, orient, *nmb);
	free(nmb);
	return (result);
}

t_light		*parse_light(const char *line)
{
	int i;
	double *nmb;
	t_vector *pos;
	t_color *color;
	t_light *result;

	i = 2;
	nmb = malloc(sizeof(double));
	pos = new_vector(0, 0, 0);
	color = new_color(0, 0, 0);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	i = i + parse_pos(&line[i], pos);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	i = i + ft_atof(&line[i], nmb);
	if (*nmb > 1. || *nmb < 0.)
		exit(1);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	i = i + parse_color(&line[i], color);
	if (line[i] != '\0')
		exit(1);
	result = new_light(pos, color, *nmb);
	free(nmb);
	return (result);
}

t_sphere *		parse_sphere(const char *line)
{
	int i;
	double *nmb;
	t_vector *pos;
	t_color *color;
	t_sphere *result;

	i = 2;
	nmb = malloc(sizeof(double));
	pos = new_vector(0, 0, 0);
	color = new_color(0, 0, 0);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	i = i + parse_pos(&line[i], pos);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	i = i + ft_atof(&line[i], nmb);
	if (*nmb < 0.)
		exit(1);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	i = i + parse_color(&line[i], color);
	if (line[i] != '\0')
		exit(1);
	result = new_sphere(pos, color, *nmb);
	free(nmb);
	return (result);
}

t_plane *	parse_plane(const char *line)
{
	int i;
	t_vector *pos;
	t_vector *orient;
	t_color *color;

	i = 2;
	orient = new_vector(0, 0, 0);
	pos = new_vector(0, 0, 0);
	color = new_color(0, 0, 0);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	i = i + parse_pos(&line[i], pos);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	i = i + parse_orient(&line[i], orient);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	i = i + parse_color(&line[i], color);
	if (line[i] != '\0')
		exit(1);
	return (new_plane(pos, orient, color));
}

t_square *parse_square(const char *line)
{
	int i;
	t_vector *pos;
	t_vector *orient;
	t_color *color;
	double *nmb;
	t_square *result;

	i = 2;
	nmb = malloc(sizeof(double));
	orient = new_vector(0, 0, 0);
	pos = new_vector(0, 0, 0);
	color = new_color(0, 0, 0);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	i = i + parse_pos(&line[i], pos);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	i = i + parse_orient(&line[i], orient);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	i = i + ft_atof(&line[i], nmb);
	if (*nmb < 0.)
		exit(1);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	i = i + parse_color(&line[i], color);
	if (line[i] != '\0')
		exit(1);
	result = new_square(pos, orient, color, *nmb);
	free(nmb);
	return (result);
}

t_cylinder *parse_cylinder(const char *line)
{
	int i;
	t_vector *pos;
	t_vector *orient;
	t_color *color;
	double *nmb;
	t_cylinder *result;

	i = 2;
	nmb = malloc(sizeof(double));
	orient = new_vector(0, 0, 0);
	pos = new_vector(0, 0, 0);
	color = new_color(0, 0, 0);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	i = i + parse_pos(&line[i], pos);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	i = i + parse_orient(&line[i], orient);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	i = i + ft_atof(&line[i], nmb);
	if (*nmb < 0.)
		exit(1);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	i = i + parse_color(&line[i], color);
	if (line[i] != '\0')
		exit(1);
	result = new_cylinder(pos, orient, color, *nmb);
	free(nmb);
	return (result);
}

t_triangle *parse_triangle(const char *line)
{
	int i;
	t_vector *pos1;
	t_vector *pos2;
	t_vector *pos3;
	t_color *color;

	i = 2;
	pos1 = new_vector(0, 0, 0);
	pos2 = new_vector(0, 0, 0);
	pos3 = new_vector(0, 0, 0);
	color = new_color(0, 0, 0);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	i = i + parse_pos(&line[i], pos1);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	i = i + parse_pos(&line[i], pos2);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	i = i + parse_pos(&line[i], pos3);
	while (line[i] == ' ' || line[i] == '\t')
		i++;
	i = i + parse_color(&line[i], color);
	if (line[i] != '\0')
		exit(1);
	return (new_triangle(pos1, pos2, pos3, color));
}
