/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/16 20:23:05 by wrudy             #+#    #+#             */
/*   Updated: 2020/09/21 21:25:57 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "canvas.h"

t_color			*new_color(double r, double g, double b)
{
	t_vector	*color;
	t_color		*result;

	if (!(color = new_vector(r, g, b)))
		return (NULL);
	if (!(result = malloc(sizeof(t_color))))
		return (NULL);
	if (r <= 255)
		color->x = r;
	else
		color->x = 255;
	if (g <= 255)
		color->y = g;
	else
		color->y = 255;
	if (b <= 255)
		color->z = b;
	else
		color->z = 255;
	result->rgb_color = color;
	result->in_hex = rgb_hex_transform;
	result->destroy = color_destructor;
	return (result);
}

int				rgb_hex_transform(t_color *rgb_color)
{
	unsigned r;
	unsigned g;
	unsigned b;
	int result;

	r = ((unsigned)round(rgb_color->rgb_color->x)) << 16u;
	g = (unsigned)round(rgb_color->rgb_color->y) << 8u;
	b = (unsigned)round(rgb_color->rgb_color->z);
	result = (int)(r | g | b);
	return (result);
}

void			color_destructor(t_color *color)
{
	color->rgb_color->destroy(color->rgb_color);
	free(color);
}