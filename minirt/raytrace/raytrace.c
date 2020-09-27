/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 18:48:29 by wrudy             #+#    #+#             */
/*   Updated: 2020/09/27 20:25:48 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytrace.h"

static t_vector *reflect_ray(t_vector *r, t_vector *n)
{
	double tmp;
	t_vector *result;

	result = new_vector(0, 0, 0);
	tmp = 2 * scalar_multiplication(n, r);
	multiplication_by_scalar(n, tmp, result);
	vec_diff(result, r, result);
	return (result);
}

t_color *object_color(t_object *object, t_vector *p, t_vector *n, t_scene *scene, t_vector *v)
{
	t_color *result;
	double tmp;
	double bright;
	t_vector *r;
	int i;
	t_vector *l;
	t_object *flag;

	flag = new_object();
	bright = scene->ambient_light->ratio;
	l = new_vector(0, 0, 0);
	i = 0;
	while (i < scene->lights_count)
	{
		l = vec_diff(scene->light[i]->pos, p, l);

		intersection(scene, flag, p, l, 0.001, scene->ray_length);
		if (flag->sphere != NULL)
		{
			i++;
			continue;
		}

		tmp = scalar_multiplication(n, l);
		if (tmp > 0)
			bright = bright + scene->light[i]->brightness * tmp / (n->magnitude(n) * l->magnitude(l));
		if (object->sphere->specular > 0)
		{
			r = reflect_ray(l, n);

			tmp = scalar_multiplication(r, v);
			if (tmp < 0)
				bright = bright + scene->light[i]->brightness *
						pow(tmp / (r->magnitude(r) * v->magnitude(v)), object->sphere->specular);
		}
		i++;
	}

	result = new_color(object->sphere->color->rgb_color->x * bright,
					   object->sphere->color->rgb_color->y * bright,
					   object->sphere->color->rgb_color->z * bright);
	return (result);
}

t_color			*trace(t_vector *o, t_vector *d, t_scene *scene, int depth)
{
	double t;
	double reflective;
	t_color *local_color;
	t_color *reflected_color;
	t_color *result;
	t_vector *n;
	t_vector *p;
	t_vector *sphere_center;
	t_object *closest_object;
	t_vector *r;

	closest_object = new_object();
	t = intersection(scene, closest_object, o, d, 0.001, scene->ray_length);

	if (closest_object->sphere == NULL)
	{
		local_color = new_color(0, 0, 0);
		return (local_color);
	}
	p = new_vector(0, 0, 0);
	n = new_vector(0, 0, 0);
	d->product_by_scalar(d, t);
	p = vec_sum(o, d, p);
	sphere_center = new_vector(closest_object->sphere->pos->x,
							   closest_object->sphere->pos->y,
							   closest_object->sphere->pos->z);
	n = vec_diff(p, sphere_center, n);
	n->product_by_scalar(n, 1./n->magnitude(n));
	local_color = object_color(closest_object, p, n, scene, d);

	reflective = closest_object->sphere->reflective;
	if (depth <= 0 || reflective <= 0)
		return local_color;

	d->product_by_scalar(d, -1);
	r = reflect_ray(d, n);
	reflected_color = trace(p, r, scene, depth - 1);

	local_color->rgb_color->product_by_scalar(local_color->rgb_color, 1 - reflective);
	reflected_color->rgb_color->product_by_scalar(reflected_color->rgb_color, reflective);
	result = new_color(0, 0, 0);
	vec_sum(local_color->rgb_color, reflected_color->rgb_color, result->rgb_color);
	return (result);
}

t_color			*raytrace(int canvas_x, int canvas_y, t_scene *scene, int selected_camera)
{
	t_vector	*d;
	t_vector	*o;

	d = ray_direction(canvas_x, canvas_y, scene, selected_camera);
	o = scene->camera[selected_camera]->pos;

	return (trace(o, d, scene, 8));
}
