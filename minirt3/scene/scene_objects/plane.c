/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plane.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 23:13:16 by wrudy             #+#    #+#             */
/*   Updated: 2020/10/15 18:01:29 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_plane		*new_plane(t_vector *pos, t_vector *normal ,t_color *color)
{
	t_plane *result;
	if (!(result = malloc(sizeof(t_plane))))
		return (NULL);
	result->color = color;
	result->pos = pos;
	normal->product_by_scalar(normal, 1./normal->magnitude(normal));
	result->normal_vector = normal;
	result->get_normal = get_plane_normal;
	result->intersection = plane_intersection;
	result->destroy = plane_destructor;
	return (result);
}

t_vector	*get_plane_normal(t_plane *self)
{
	t_vector *result;

	if (!(result = new_vector(self->normal_vector->x, self->normal_vector->y,
						   self->normal_vector->z)))
		return (NULL);
	return (result);
}

double			plane_intersection(t_vector *o, t_vector *d, t_plane *plane)
{
	double r;
	double t;
	double dn;
	double an;

	r = sc_mult(plane->normal_vector, plane->pos);
	dn = sc_mult(d, plane->normal_vector);
	an = sc_mult(o, plane->normal_vector);
	t = (r - an) / dn;
	if (t < 1e-3 || dn == 0)
		t = 1e100;
	return (t);
}

void 			plane_destructor(t_plane *self)
{
	self->color->destroy(self->color);
	self->pos->destroy(self->pos);
	self->normal_vector->destroy(self->normal_vector);
	free(self);
}