/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 22:50:05 by wrudy             #+#    #+#             */
/*   Updated: 2020/09/27 07:36:06 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_canvas	*render(t_scene *scene, int camera_index)
{
	int width;
	int height;
	t_canvas *canvas;
	t_color *color;

	width = scene->resolution_x;
	height = scene->resolution_y;
	canvas = new_canvas(width, height);
	scene->camera[camera_index]->distance_to_viewport = (double)width/(2. * tan(scene->camera[camera_index]->fov * M_PI / 360.));
	while (height--)
	{
		width = scene->resolution_x;
		while (width--)
		{
			if (!(color = raytrace(width, height, scene, camera_index)))
				return (NULL);
			canvas->set_pixel(canvas, width, height, color);
		}
	}
	return (canvas);
}