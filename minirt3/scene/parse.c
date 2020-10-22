/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 03:35:56 by wrudy             #+#    #+#             */
/*   Updated: 2020/10/22 19:33:44 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

static void line_counting(const char *line, t_scene *scene)
{
	if (line[0] == '\n' || line[0] == '\0')
		return;
	else if (line[0] == 'R' && (line[1] == ' ' || line[1] == '\t'))
		scene->resolution_lines_count++;
	else if (line[0] == 'A' && (line[1] == ' ' || line[1] == '\t'))
		scene->amblight_lines_count++;
	else if (line[0] == 'c' && (line[1] == ' ' || line[1] == '\t'))
		scene->camera_count++;
	else if (line[0] == 'l' && (line[1] == ' ' || line[1] == '\t'))
		scene->lights_count++;
	else if (line[0] == 'p' && line[1] == 'l')
		scene->plane_count++;
	else if (line[0] == 's' && line[1] == 'p')
		scene->sphere_count++;
	else if (line[0] == 's' && line[1] == 'q')
		scene->square_count++;
	else if (line[0] == 'c' && line[1] == 'y')
		scene->cylinder_count++;
	else if (line[0] == 't' && line[1] == 'r')
		scene->triangle_count++;
	else
		exit(1); //FIXME
}

static void obj_counting(char *path, t_scene *scene)
{
	int fd;
	char *line;

	fd = open(path, O_RDONLY);
	while (get_next_line(fd, &line))
	{
		line_counting(line, scene);
		free(line);
	}
	line_counting(line, scene);
	if (scene->resolution_lines_count != 1) //FIXME
		exit(1);
	if (scene->amblight_lines_count > 1) //FIXME
		exit(1);
	if (scene->camera_count < 1) //FIXME
		exit(1);
	free(line);
	close(fd);
}

static void line_parse(const char *line, t_scene *scene, t_obj_indexes *ind)
{
	if (line[0] == 'R' && line[1] == ' ')
		parse_resolution(line, scene);
	if (line[0] == 'A' && line[1] == ' ')
		scene->ambient_light = parse_amblight(line);
	if (line[0] == 'c' && line[1] == ' ')
		scene->camera[ind->camera_i++] = parse_camera(line);
	if (line[0] == 'l' && line[1] == ' ')
		scene->light[ind->light_i++] = parse_light(line);
	if (line[0] == 'p' && line[1] == 'l')
		scene->plane[ind->plane_i++] = parse_plane(line);
	if (line[0] == 's' && line[1] == 'p')
		scene->sphere[ind->sphere_i++] = parse_sphere(line);
	if (line[0] == 's' && line[1] == 'q')
		scene->square[ind->square_i++] = parse_square(line);
	if (line[0] == 'c' && line[1] == 'y')
		scene->cylinder[ind->cylinder_i++] = parse_cylinder(line);
	if (line[0] == 't' && line[1] == 'r')
		scene->triangle[ind->triangle_i++] = parse_triangle(line);
}

static void obj_parse(char *path, t_scene *scene, t_obj_indexes *ind)
{
	int fd;
	int i;
	char *line;

	fd = open(path, O_RDONLY);
	while ((i = get_next_line(fd, &line)))
	{
		line_parse(line, scene, ind);
		free(line);
	}
	if (i < 0)
		exit(1);
	line_parse(line, scene, ind);
	free(line);
	close(fd);
}

void 			allocate(t_scene *scene)
{
	if (!(scene->camera = malloc(sizeof(t_camera *) * scene->camera_count)))
		exit(1);
	if (!(scene->light = malloc(sizeof(t_light *) * scene->lights_count)))
		exit(1);
	if (!(scene->sphere = malloc(sizeof(t_sphere *) * scene->sphere_count)))
		exit(1);
	if (!(scene->plane = malloc(sizeof(t_plane *) * scene->plane_count)))
		exit(1);
	if (!(scene->square = malloc(sizeof(t_square *) * scene->square_count)))
		exit(1);
	if (!(scene->cylinder = malloc(sizeof(t_cylinder *) * scene->cylinder_count)))
		exit(1);
	if (!(scene->triangle = malloc(sizeof(t_triangle *) * scene->triangle_count)))
		exit(1);
}

void 			parse(char *path, t_scene *scene)
{
	t_obj_indexes *ind;

	if (!(ind = malloc(sizeof(t_obj_indexes))))
		exit(1);
	ind->camera_i = 0;
	ind->light_i = 0;
	ind->plane_i = 0;
	ind->sphere_i = 0;
	ind->square_i = 0;
	ind->cylinder_i = 0;
	ind->triangle_i = 0;
	obj_counting(path, scene);
	allocate(scene);
	obj_parse(path, scene, ind);
	free(ind);
}