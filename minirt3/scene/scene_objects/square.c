/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 19:50:42 by wrudy             #+#    #+#             */
/*   Updated: 2020/10/17 20:14:25 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "stdio.h"

t_square		*new_square(t_vector *pos, t_vector *normal, t_color *color, double side_size)
{
	t_square *result;

	if (!(result = malloc(sizeof(t_square))))
		exit(EXIT_FAILURE);
	result->pos = pos;
	result->normal_vector = normal;
	result->side_size = side_size;
	result->color = color;
	result->intersection = square_intersection;
	result->get_normal = get_square_normal;
	result->destroy = square_destructor;
	return (result);
}

t_vector		*get_square_normal(t_square *self)
{
	t_vector *result;

	result = new_vector(self->normal_vector->x, self->normal_vector->y, self->normal_vector->z);
	return result;
}

double			square_intersection(t_vector *o, t_vector *d, t_square *square)
{
	double		t;
	t_vector	*p;
	t_vector	*e1;
	t_vector	*e2;
	t_vector	*tmp;

	if ((t = plane_intersection(o, d, (t_plane *)square)) >= 1e100)
		return (t);
	p = new_vector(0, 0, 0);
	p = multiplication_by_scalar(d, t, p);
	p = vec_sum(o, p, p);
	tmp = new_vector(1e-100, 1, 1e-100);
	e1 = cross_product(tmp, square->normal_vector);
	tmp->destroy(tmp);
	e1->product_by_scalar(e1, 1./e1->magnitude(e1));
	if (fabs(sc_mult(e1, p)) >= square->side_size / 2.)
		return (1e100);
	e2 = cross_product(square->normal_vector, e1);
	e2->product_by_scalar(e2, 1./e2->magnitude(e2));
	if (fabs(sc_mult(e2, p)) >= square->side_size / 2.)
		return (1e100);
	p->destroy(p);
	e1->destroy(e1);
	e2->destroy(e2);
	return (t);
}

void 			square_destructor(t_square *self)
{
	self->normal_vector->destroy(self->normal_vector);
	self->color->destroy(self->color);
	self->pos->destroy(self->pos);
	free(self);
}
