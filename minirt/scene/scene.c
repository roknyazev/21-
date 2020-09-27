/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 20:33:31 by wrudy             #+#    #+#             */
/*   Updated: 2020/09/27 20:45:42 by wrudy            ###   ########.fr       */
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

	t_vector	*sphere3_pos;
	t_color		*sphere3_color;
	double		sphere3_diameter;

	t_vector	*sphere4_pos;
	t_color		*sphere4_color;
	double		sphere4_diameter;

	t_vector	*sphere5_pos;
	t_color		*sphere5_color;
	double		sphere5_diameter;

	t_vector	*sphere6_pos;
	t_color		*sphere6_color;
	double		sphere6_diameter;

	t_vector	*sphere7_pos;
	t_color		*sphere7_color;
	double		sphere7_diameter;


	if (!(result = malloc(sizeof(t_scene))))
		return (NULL);

	result->resolution_x = 1800;
	result->resolution_y = 1180;

	result->lights_count = 3;
	result->light = malloc(result->lights_count * sizeof(t_light *));

	light_pos = new_vector(15, 15, 0);
	light_color = new_color(255, 255, 255);
	light_brightness = 0.45;
	result->light[0] = new_light(light_pos, light_color, light_brightness);

	light_pos = new_vector(-15, 15, 30);
	light_color = new_color(255, 255, 255);
	light_brightness = 0.35;
	result->light[1] = new_light(light_pos, light_color, light_brightness);

	light_pos = new_vector(15, 15, 10);
	light_color = new_color(255, 255, 255);
	light_brightness = 0.35;
	result->light[2] = new_light(light_pos, light_color, light_brightness);

	t_color *amblight_color;
	amblight_color = new_color(0xFF, 0xFF, 0xFF);
	result->ambient_light = new_amblight(amblight_color, 0.05);

	result->camera_count = 1;
	result->camera = malloc(result->camera_count * sizeof(t_camera *));
	camera_pos = new_vector(0, 0, 0);
	camera_orient = new_vector(0 ,0 , 1);
	fov = 75;
	result->camera[0] = new_camera(camera_pos, camera_orient, fov, result->resolution_x);


	result->sphere_count = 7;
	result->sphere = malloc(result->sphere_count *  sizeof(t_sphere *));

	sphere1_pos = new_vector(0, 0, 23);
	sphere1_color = new_color(0xFF, 90, 40);
	sphere1_diameter = 10;

	sphere2_pos = new_vector(-6, 10, 50);
	sphere2_color = new_color(250, 130, 0);
	sphere2_diameter = 15;

	sphere3_pos = new_vector(-8.5, 0, 26);
	sphere3_color = new_color(40, 250, 250);
	sphere3_diameter = 7;

	sphere4_pos = new_vector(8.2, 0, 34);
	sphere4_color = new_color(20, 60, 100);
	sphere4_diameter = 7;

	sphere5_pos = new_vector(5, 10, 35);
	sphere5_color = new_color(20, 160, 10);
	sphere5_diameter = 10;

	sphere6_pos = new_vector(0, -5000, 0);
	sphere6_color = new_color(30, 25, 25);
	sphere6_diameter = 10000 - 10;

	sphere7_pos = new_vector(-80, -20, 50);
	sphere7_color = new_color(150, 50, 50);
	sphere7_diameter = 70;

	result->sphere[0] = new_sphere(sphere1_pos, sphere1_color, sphere1_diameter, 1000, 0);
	result->sphere[1] = new_sphere(sphere2_pos, sphere2_color, sphere2_diameter, 10110, 0.5);
	result->sphere[2] = new_sphere(sphere3_pos, sphere3_color, sphere3_diameter, 500, 0.7);
	result->sphere[3] = new_sphere(sphere4_pos, sphere4_color, sphere4_diameter, 300, 0.3);
	result->sphere[4] = new_sphere(sphere5_pos, sphere5_color, sphere5_diameter, 100, 0.7);
	result->sphere[5] = new_sphere(sphere6_pos, sphere6_color, sphere6_diameter, 100, 0.4);
	result->sphere[6] = new_sphere(sphere7_pos, sphere7_color, sphere7_diameter, 100, 0.4);

	result->ray_length = 1e100;
	result->destroy = scene_destructor;
	return (result);
}

void 			scene_destructor(t_scene *self)
{
	/* FIXME  Полность переписать*/
	free(self);
}
