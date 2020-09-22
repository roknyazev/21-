/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 22:50:05 by wrudy             #+#    #+#             */
/*   Updated: 2020/09/22 23:10:07 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_canvas	*render(t_scene *scene)
{
	int width;
	int height;
	t_canvas *canvas;
	t_color *color;

	width = scene->resolution_x;
	height = scene->resolution_y;
	canvas = new_canvas(width, height);
	while (width--)
	{
		height = scene->resolution_y;
		while (height--)
		{
			color = ray_trace();
			//color = new_color(width, height, width + height);
			canvas->set_pixel(canvas, width, height, color);
		}
	}
	return (canvas);
}