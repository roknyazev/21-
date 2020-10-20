/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cylinder.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/17 20:43:36 by wrudy             #+#    #+#             */
/*   Updated: 2020/10/19 20:31:40 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_cylinder		*new_cylinder(t_vector *pos, t_vector *normal, t_color *color, double diameter)
{
	t_cylinder *result;

	if (!(result = malloc(sizeof(t_cylinder))))
		exit(EXIT_FAILURE);
	result->pos = pos;
	normal->product_by_scalar(normal, 1./(normal->magnitude(normal)));
	result->normal_vector = normal;
	result->diameter = diameter;
	result->color = color;
	result->intersection = cylinder_intersection;
	result->get_normal = get_cylinder_normal;
	result->destroy = cylinder_destructor;
	return (result);
}

t_vector		*get_cylinder_normal(t_cylinder *self, t_vector *intersection_point)
{
	t_vector *tmp;
	t_vector *tmp2;
	t_vector *result;

	tmp = new_vector(0, 0 ,0);
	tmp = vec_diff(intersection_point, self->pos, tmp);
	tmp2 = cross_product(tmp, self->normal_vector);
	result = cross_product(tmp2, self->normal_vector);
	tmp->destroy(tmp);
	tmp2->destroy(tmp2);
	return (result);
}

static t_vector	*get_abd(t_vector *vec1, t_vector *vec2, t_cylinder *cylinder)
{
	t_vector *result;
	double a;
	double b;
	double c;
	double d;

	result = new_vector(0, 0, 0);
	a = sc_mult(vec1, vec1);
	b = 2 * sc_mult(vec1, vec2);
	c = sc_mult(vec2, vec2) - (cylinder->diameter / 2.) * (cylinder->diameter / 2.);
	d = b*b - 4*a*c;
	result->x = a;
	result->y = b;
	result->z = d;
	return (result);
}

double			cylinder_intersection(t_vector *o, t_vector *d, t_cylinder *cylinder)
{
	t_vector	*vec1;
	t_vector	*vec2;
	t_vector	*dp;
	t_vector	*abd;
	double		result;

	vec1 = new_vector(0, 0 , 0);
	vec2 = new_vector(0, 0 , 0);

	vec1 = multiplication_by_scalar(cylinder->normal_vector, sc_mult(d, cylinder->normal_vector), vec1);
	vec1 = vec_diff(d, vec1, vec1);
	dp = new_vector(0, 0, 0);
	dp = vec_diff(o, cylinder->pos, dp);
	vec2 = multiplication_by_scalar(cylinder->normal_vector, sc_mult(dp, cylinder->normal_vector), vec2);
	vec2 = vec_diff(dp, vec2, vec2);
	abd = get_abd(vec1, vec2, cylinder);
	if (abd->z < 0.)
		return (1e100);
	result = choice((-abd->y + sqrt(abd->z)) / (2. * abd->x),
					(-abd->y - sqrt(abd->z)) / (2. * abd->x), 1e-3, 1e100);
	vec1->destroy(vec1);
	vec2->destroy(vec2);
	dp->destroy(dp);
	abd->destroy(abd);
	return (result);
}

void 			cylinder_destructor(t_cylinder *self)
{
	self->normal_vector->destroy(self->normal_vector);
	self->color->destroy(self->color);
	self->pos->destroy(self->pos);
	free(self);
}