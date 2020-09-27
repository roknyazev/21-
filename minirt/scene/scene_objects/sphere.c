/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sphere.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 21:34:36 by wrudy             #+#    #+#             */
/*   Updated: 2020/09/27 08:45:51 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_sphere		*new_sphere(t_vector *pos, t_color *color, double d, double s, double r)
{
	t_sphere *result;

	if (!(result = malloc(sizeof(t_sphere))))
		return (NULL);
	result->pos = pos;
	result->color = color;
	result->diameter = d;
	result->specular = s;
	result->reflective = r;
	result->intersection = sphere_intersection;
	result->destroy = sphere_destructor;
	return (result);
}

static double check(double t1, double t2,double t_min, double t_max)
{
	double result;

	result = t_max;
	if (t1 > t_min && t1 < t_max)
		result = t1;
	if (t2 > t_min && t2 < t_max)
		result = t2;
	return (result);
}

double sphere_intersection(t_vector *o, t_vector *d, t_sphere *sphere, double t_min, double t_max)
{
	t_vector *c;
	t_vector *oc;
	double 	 r;
	double	k1;
	double 	k2;
	double	k3;
	double	discriminant;
	double	t1;
	double 	t2;

	c = sphere->pos;
	r = sphere->diameter/2.;
	oc = new_vector(o->x - c->x,o->y - c->y,o->z - c->z);

	k1 = scalar_multiplication(d, d);
	k2 = 2.0 * scalar_multiplication(oc, d);
	k3 = scalar_multiplication(oc, oc) - r * r;
	oc->destroy(oc);
	discriminant = k2 * k2 - 4 * k1 * k3;
	if (discriminant < 0)
		return (1e308);
	t1 = (-k2 + sqrt(discriminant)) / (2*k1);
	t2 = (-k2 - sqrt(discriminant)) / (2*k1);
	return (check(t1, t2, t_min, t_max));
}

void 			sphere_destructor(t_sphere *self)
{
	self->pos->destroy(self->pos);
	self->color->destroy(self->color);
	free(self);
}
