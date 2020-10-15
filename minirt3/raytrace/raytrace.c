/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/23 18:48:29 by wrudy             #+#    #+#             */
/*   Updated: 2020/10/15 17:30:18 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytrace.h"

static double	light_br(t_light *light, t_vector *n, t_vector *l, char channel)
{
	if (channel == 'r')
		return (light->brightness * (light->color->rgb_color->x / 255.) / (n->magnitude(n) * l->magnitude(l)));
	if (channel == 'g')
		return (light->brightness * (light->color->rgb_color->y / 255.) / (n->magnitude(n) * l->magnitude(l)));
	if (channel == 'b')
		return (light->brightness * (light->color->rgb_color->z / 255.) / (n->magnitude(n) * l->magnitude(l)));
	else
		return (0.);
}

static void		bright_calc(t_vector *bright, t_vector *p, t_vector *n, t_scene *scene)
{
	int			i;
	double		ang;
	t_vector	*l;
	t_object	*shadow_object;

	i = scene->lights_count;
	l = new_vector(0., 0., 0.);
	shadow_object = new_object();
	while (i--)
	{
		l = vec_diff(scene->light[i]->pos, p, l);
		vector_destructor(intersection(scene, shadow_object, p, l));
		if (shadow_object->exist && shadow_object->t < 1)
			continue;
		ang = sc_mult(n, l);
		if (ang > 0)
		{
			bright->x = bright->x + light_br(scene->light[i], n, l, 'r') * ang;
			bright->y = bright->y + light_br(scene->light[i], n, l, 'g') * ang;
			bright->z = bright->z + light_br(scene->light[i], n, l, 'b') * ang;
		}
	}
	l->destroy(l);
	shadow_object->destroy(shadow_object);
}

static t_color	*virtual_color(t_object *object, t_vector *p, t_vector *n, t_scene *scene)
{
	t_vector	*bright;
	t_color		*result;
	double		amb_ratio;

	amb_ratio = scene->ambient_light->ratio;
	bright = new_vector(
			amb_ratio * scene->ambient_light->color->rgb_color->x / 255.,
			amb_ratio * scene->ambient_light->color->rgb_color->y / 255.,
			amb_ratio * scene->ambient_light->color->rgb_color->z / 255.);
	bright_calc(bright, p, n, scene);
	result = new_color(object->color->rgb_color->x * bright->x,
					object->color->rgb_color->y * bright->y,
					object->color->rgb_color->z * bright->z);
	bright->destroy(bright);
	return (result);
}

static t_color	*trace(t_vector *o, t_vector *d, t_scene *scene)
{
	t_object	*object;
	t_vector	*intersection_point;
	t_color		*result;
	t_vector	*norm;


	object = new_object();
	intersection_point = intersection(scene, object, o, d);
	if (!(object->exist))
	{
		object->destroy(object);
		intersection_point->destroy(intersection_point);
		return (new_color(0., 0., 0.));
	}
	norm = object->normal_vec;
	if (sc_mult(norm, d) > 0)
		norm->product_by_scalar(norm, -1.);
	result = virtual_color(object, intersection_point, norm, scene);
	object->destroy(object);
	intersection_point->destroy(intersection_point);
	return (result);
}

t_color			*raytrace(int canvas_x, int canvas_y, t_scene *scene, int camera_index)
{
	t_vector	*d;
	t_vector	*o;
	t_color		*result;

	d = ray_cast(canvas_x, canvas_y, scene, camera_index);
	d->product_by_scalar(d, 1./d->magnitude(d));
	o = scene->camera[camera_index]->pos;
	result = trace(o, d, scene);
	d->destroy(d);
	return (result);
}
