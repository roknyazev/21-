/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 07:56:48 by wrudy             #+#    #+#             */
/*   Updated: 2020/09/27 08:44:32 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytrace.h"

t_vector	*ray_direction(int cx, int cy, t_scene *scene, int selected_camera)
{
	double		dx;
	double		dy;
	double		dz;
	double		m;
	t_vector	*camera_pos;
	t_vector	*result;

	camera_pos = scene->camera[selected_camera]->pos;

	dx = (double)cx - (((double)scene->resolution_x) / 2.);
	dy = -(double)cy + (((double)scene->resolution_y) / 2.);
	dz = scene->camera[selected_camera]->distance_to_viewport;
	result = new_vector(dx, dy, dz);
	camera_pos->product_by_scalar(camera_pos, -1.);
	result = vec_sum(result, camera_pos, result);
	m = result->magnitude(result);
	result->product_by_scalar(result, 1./m);
	return (result);
}

double 			intersection(t_scene *scene,t_object *object, t_vector *o, t_vector *d, double t_min, double t_max)
{
	int i;
	double t;
	double solution;

	t = t_max;
	object->sphere = NULL;
	i = 0;
	while (i < scene->sphere_count)
	{
		solution = scene->sphere[i]->intersection(o, d, scene->sphere[i], t_min, t_max);
		if (solution < t)
		{
			t = solution;
			object->sphere = scene->sphere[i];
		}
		i++;
	}
	return (t);
}
