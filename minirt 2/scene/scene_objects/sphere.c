/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 21:34:36 by wrudy             #+#    #+#             */
/*   Updated: 2020/09/22 21:38:42 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_sphere		*new_sphere(t_vector *pos, t_color *color, double d)
{
	t_sphere *result;

	if (!(result = malloc(sizeof(t_sphere))))
		return (NULL);
	result->pos = pos;
	result->color = color;
	result->diameter = d;
	result->destroy = sphere_destructor;
	return (result);
}

void 			sphere_destructor(t_sphere *self)
{
	self->pos->destroy(self->pos);
	self->color->destroy(self->color);
	free(self);
}
