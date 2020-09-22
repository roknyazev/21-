/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 20:33:31 by wrudy             #+#    #+#             */
/*   Updated: 2020/09/22 23:16:14 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_scene			*new_scene(char *path)
{
	/* FIXME Полность переписать*/
	path = NULL;
	t_scene *result;

	t_vector	*light_pos;
	t_color		*light_color;
	double		light_brightness;

	t_vector	*camera_pos;
	t_vector	*camera_orient;
	double 		fov;

	t_vector	*sphere1_pos;
	t_color		*sphere1_color;
	double		sphere1_diameter;
	t_vector	*sphere2_pos;
	t_color		*sphere2_color;
	double		sphere2_diameter;

	if (!(result = malloc(sizeof(t_scene))))
		return (NULL);

	result->lights_count = 1;
	result->light = malloc(result->lights_count * sizeof(t_light *));
	light_pos = new_vector(50, 50, 50);
	light_color = new_color(255, 255, 255);
	light_brightness = 0.7;
	result->light[0] = new_light(light_pos, light_color, light_brightness);

	result->ambient_light = NULL;

	result->camera_count = 1;
	result->camera = malloc(result->camera_count * sizeof(t_camera *));
	camera_pos = new_vector(0, 0, 0);
	camera_orient = new_vector(0 ,0 , 1);
	fov = 60;
	result->camera[0] = new_camera(camera_pos, camera_orient, fov);

	result->sphere_count = 2;
	result->sphere = malloc(result->sphere_count *  sizeof(t_sphere *));
	sphere1_pos = new_vector(-5, 15, 34);
	sphere1_color = new_color(200, 60, 0);
	sphere1_diameter = 10;
	sphere2_pos = new_vector(5, -1, 18);
	sphere2_color = new_color(10, 160, 70);
	sphere2_diameter = 10;
	result->sphere[0] = new_sphere(sphere1_pos, sphere1_color, sphere1_diameter);
	result->sphere[1] = new_sphere(sphere2_pos, sphere2_color, sphere2_diameter);

	result->resolution_x = 1920;
	result->resolution_y = 1080;
	result->destroy = scene_destructor;
	return (result);
}

void 			scene_destructor(t_scene *self)
{
	/* FIXME  Полность переписать*/
	free(self);
}
