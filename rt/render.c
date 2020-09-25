/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 22:50:05 by wrudy             #+#    #+#             */
/*   Updated: 2020/09/24 22:47:44 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_canvas	*render(t_scene *scene, int selected_camera)
{
	int width;
	int height;
	t_canvas *canvas;
	t_color *color;

	width = scene->resolution_x;
	height = scene->resolution_y;
	canvas = new_canvas(width, height);
	while (height--)
	{
		width = scene->resolution_x;
		while (width--)
		{
			//color = new_color(width, height, height + width);
			color = raytrace(width, height, scene, selected_camera);
			canvas->set_pixel(canvas, width, height, color);
		}
	}
	return (canvas);
}