/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 20:25:32 by wrudy             #+#    #+#             */
/*   Updated: 2020/09/21 21:34:08 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"
#include <stdio.h>

t_canvas		*new_canvas(int width, int height)
{
	t_canvas	*result;
	t_color		**pixel_array;

	if (!(result = malloc(sizeof(t_canvas))))
		return (NULL);
	if (!(pixel_array = malloc(width * height * sizeof(t_color *))))
		return (NULL);
	result->pixel_array = pixel_array;
	result->set_pixel = set_pixel;
	result->get_pixel = get_pixel;
	result->destroy = canvas_destructor;
	result->width = width;
	result->height = height;
	return (result);
}

t_color			*get_pixel(struct s_canvas *self, int x, int y)
{
	int index;

	index = (y * self->width) + x;
	return (self->pixel_array[index]);
}

void			set_pixel(struct s_canvas *self, int x, int y, t_color *color)
{
	int index;

	index = (y * self->width) + x;
	self->pixel_array[index] = color;
}

void 			canvas_destructor(struct s_canvas *self)
{
	int len;

	len = self->width * self->height;
	while (len--)
	{
		self->pixel_array[len]->in_hex(self->pixel_array[len]);
		self->pixel_array[len]->destroy(self->pixel_array[len]);
	}
	free(self);
}