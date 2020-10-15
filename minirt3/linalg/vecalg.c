/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecalg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 22:59:37 by wrudy             #+#    #+#             */
/*   Updated: 2020/10/14 16:29:16 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linalg.h"

t_vector	*new_vector(double x, double y, double z)
{
	t_vector *result;

	if (!(result = malloc(sizeof(t_vector))))
		return (NULL);
	result->x = x;
	result->y = y;
	result->z = z;
	result->product_by_scalar = self_multiplication_by_scalar;
	result->magnitude = magnitude;
	result->destroy = vector_destructor;
	return (result);
}

double 			magnitude(t_vector *self)
{
	return (sqrt(pow(self->x, 2.0) + pow(self->y, 2.0) + pow(self->z, 2.0)));
}

void		self_multiplication_by_scalar(t_vector *self, double scalar)
{
	self->x = (self->x) * scalar;
	self->y = (self->y) * scalar;
	self->z = (self->z) * scalar;
}

void 		vector_destructor(t_vector *vector)
{
	free(vector);
}


double 			sc_mult(t_vector *vec1, t_vector *vec2)
{
	return ((vec1->x * vec2->x) + (vec1->y * vec2->y) + (vec1->z * vec2->z));
}

t_vector		*vec_sum(t_vector *vec1, t_vector *vec2, t_vector *buf)
{
	buf->x = vec1->x + vec2->x;
	buf->y = vec1->y + vec2->y;
	buf->z = vec1->z + vec2->z;
	return (buf);
}

t_vector		*vec_diff(t_vector *vec1, t_vector *vec2, t_vector *buf)
{
	buf->x = vec1->x - vec2->x;
	buf->y = vec1->y - vec2->y;
	buf->z = vec1->z - vec2->z;
	return (buf);
}

t_vector		*multiplication_by_scalar(t_vector *vec, double scalar, t_vector *buf)
{
	buf->x = (vec->x) * scalar;
	buf->y = (vec->y) * scalar;
	buf->z = (vec->z) * scalar;
	return (buf);
}

t_vector	*cross_product(t_vector *u, t_vector *v)
{
	t_vector	*p;

	p = new_vector(0,0,0);
	p->x = v->z * u->y - v->y * u->z;
	p->y = v->x * u->z - v->z * u->x;
	p->z = v->y * u->x - v->x * u->y;
	return (p);
}