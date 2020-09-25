/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 18:48:29 by wrudy             #+#    #+#             */
/*   Updated: 2020/09/25 23:14:37 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

static t_vector	*ray_direction(int cx, int cy, t_scene *scene, int selected_camera)
{
	double		dx;
	double		dy;
	double		dz;
	double		m;
	t_vector	*camera_pos;
	t_vector	*result;

	camera_pos = scene->camera[selected_camera]->pos;

	dx = (double)cx - (((double)scene->resolution_x) / 2.);
	dy = -(double)cy + (((double)scene->resolution_y) / 2.);
	dz = scene->camera[selected_camera]->distance_to_viewport;
	result = new_vector(dx, dy, dz);
	camera_pos->product_by_scalar(camera_pos, -1.);
	result = vec_sum(result, camera_pos, result);
	m = result->magnitude(result);
	result->product_by_scalar(result, 1./m);
	return (result);
}

static t_vector *solve_sphere(t_vector *o, t_vector *d, t_sphere *sphere)
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
		return (new_vector(1e308, 1e308, 0));

	t1 = (-k2 + sqrt(discriminant)) / (2*k1);
	t2 = (-k2 - sqrt(discriminant)) / (2*k1);
	return (new_vector(t1, t2, 0));
}

double 			intersection(t_scene *scene,t_object *object, t_vector *o, t_vector *d, double t_min, double t_max)
{
	int i;
	double t;
	t_vector *solution;

	t = t_max;
	object->sphere = NULL;
	i = 0;
	while (i < scene->sphere_count)
	{
		solution = solve_sphere(o, d, scene->sphere[i]);
		if (solution->x < t && solution->x > t_min && solution->x < t_max)
		{
			t = solution->x;
			object->sphere = scene->sphere[i];
		}
		if (solution->y < t && solution->y > t_min && solution->y < t_max)
		{
			t = solution->y;
			object->sphere = scene->sphere[i];
		}
		i++;
	}
	return (t);
}

t_color *final_color(t_object *object, t_vector *p, t_vector *n, t_scene *scene, t_vector *v)
{
	t_color *result;
	double tmp;
	double bright;
	t_vector *r;
	int i;
	t_vector *l;
	t_vector *buf;
	t_object *flag;

	flag = new_object();
	bright = scene->ambient_light->ratio;
	l = new_vector(0, 0, 0);
	i = 0;
	r = new_vector(0, 0, 0);
	buf = new_vector(0, 0, 0);
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
			tmp = 2 * scalar_multiplication(n, l);
			multiplication_by_scalar(n, tmp, buf);
			vec_diff(buf, l, r);

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

t_color			*raytrace(int canvas_x, int canvas_y, t_scene *scene, int selected_camera)
{
	t_color		*color;
	t_vector	*d;
	t_vector	*o;
	t_vector	*n;
	t_vector	*p;
	t_vector	*sphere_center;
	t_object	*closest_object;
	double 		t;

	d = ray_direction(canvas_x, canvas_y, scene, selected_camera);
	o = scene->camera[selected_camera]->pos;

	closest_object = new_object();
	t = intersection(scene, closest_object, o, d, 0, scene->ray_length);

	if (closest_object->sphere == NULL)
	{
		color = new_color(0, 0, 0);
		return (color);
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
	color = final_color(closest_object, p, n, scene, d);
	return (color);
}
