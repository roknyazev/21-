/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   square.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/15 19:50:42 by wrudy             #+#    #+#             */
/*   Updated: 2020/10/15 23:31:37 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"
#include "stdio.h"

t_square		*new_square(t_vector *pos, t_vector *normal, t_color *color, double side_size)
{
	t_square *result;

	if (!(result = malloc(sizeof(t_plane))))
		return (NULL);
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

	if (!(result = new_vector(self->normal_vector->x, self->normal_vector->y, self->normal_vector->z)))
		return (NULL);
	return result;
}

double			square_intersection(t_vector *o, t_vector *d, t_square *square)
{
	double		t;
	t_vector	*p;
	t_vector	*e1;
	t_vector	*e2;
	t_vector	*tmp;
	t_vector	*v;
	double 		proj1;
	double 		proj2;

	if ((t = plane_intersection(o, d, (t_plane *)square)) >= 1e100)
	{
		return (t);
	}

	p = new_vector(0, 0, 0);
	p = multiplication_by_scalar(d, t, p);
	p = vec_sum(o, p, p);
	//tmp = new_vector(1e-100, 1, 1e-100);
	//e1 = cross_product(tmp, square->normal_vector);
	//e2 = cross_product(e1, square->normal_vector);
	//e1->product_by_scalar(e1, 1./e1->magnitude(e1));
	//e2->product_by_scalar(e2, 1./e2->magnitude(e2));
	v = new_vector(0, 0, 0);
	vec_diff(p, square->pos, v);
	//proj1 = sc_mult(v, e1);
	//proj2 = sc_mult(v, e2);
	//if (!((proj1 < square->side_size && proj1 > 0) && (proj2 < square->side_size && proj2 > 0)))
	//	return (1e100);
	printf("%f\n", t);
	//return (t);
	if (fabs(v->x) > (square->side_size / 2)
		|| fabs(v->y) > (square->side_size / 2)
		|| fabs(v->z) > (square->side_size / 2))
		return (1e100);
	else
		return (t);
}

void 			square_destructor(t_square *self)
{
	self->normal_vector->destroy(self->normal_vector);
	self->color->destroy(self->color);
	self->pos->destroy(self->pos);
	free(self);
}