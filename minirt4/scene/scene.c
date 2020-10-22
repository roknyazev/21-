/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 20:33:31 by wrudy             #+#    #+#             */
/*   Updated: 2020/10/22 19:27:11 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_scene			*new_scene(char *path)
{
	t_scene *result;

	if (!(result = malloc(sizeof(t_scene))))
		exit(EXIT_FAILURE);
	result->amblight_lines_count = 0;
	result->resolution_lines_count = 0;

	result->camera_count = 0;
	result->lights_count = 0;
	result->sphere_count = 0;
	result->plane_count = 0;
	result->square_count = 0;
	result->cylinder_count = 0;
	result->triangle_count = 0;
	parse(path, result);

	result->destroy = scene_destructor;
	return (result);
}

void 			scene_destructor(t_scene *self)
{
	self->ambient_light->destroy(self->ambient_light);
	while (self->camera_count--)
		self->camera[self->camera_count]->destroy(self->camera[self->camera_count]);
	while (self->lights_count--)
		self->light[self->lights_count]->destroy(self->light[self->lights_count]);
	while (self->sphere_count--)
		self->sphere[self->sphere_count]->destroy(self->sphere[self->sphere_count]);
	while (self->plane_count--)
		self->plane[self->plane_count]->destroy(self->plane[self->plane_count]);
	while (self->square_count--)
		self->square[self->square_count]->destroy(self->square[self->square_count]);
	while (self->cylinder_count--)
		self->cylinder[self->cylinder_count]->destroy(self->cylinder[self->cylinder_count]);
	while (self->triangle_count--)
		self->triangle[self->triangle_count]->destroy(self->triangle[self->triangle_count]);
	free(self->camera);
	free(self->light);
	free(self->sphere);
	free(self->plane);
	free(self->square);
	free(self->cylinder);
	free(self->triangle);
	free(self);
}
