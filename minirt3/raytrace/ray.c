/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 07:56:48 by wrudy             #+#    #+#             */
/*   Updated: 2020/10/15 20:05:00 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raytrace.h"

t_vector		*ray_cast(int cx, int cy, t_scene *scene, int camera_index)
{
	t_vector	*tmp;
	t_vector	*right;
	t_vector	*up;
	t_vector	*dir;
	t_vector	*result;

	tmp = new_vector((double)cx - (((double)scene->resolution_x) / 2.),
					 -(double)cy + (((double)scene->resolution_y) / 2.),
					 scene->camera[camera_index]->distance_to_viewport);
	result = new_vector(0, 0, 0);
	dir = scene->camera[camera_index]->orient;
	dir->product_by_scalar(dir, 1. / dir->magnitude(dir));
	up = new_vector(1e-100, 1, 1e-100);
	right = cross_product(up, dir);
	right->product_by_scalar(right, 1. / right->magnitude(right));
	up->destroy(up);
	up = cross_product(dir, right);
	up->product_by_scalar(up, 1. / up->magnitude(up));
	result->x = tmp->x * right->x + tmp->y * up->x + tmp->z * dir->x;
	result->y = tmp->x * right->y + tmp->y * up->y + tmp->z * dir->y;
	result->z = tmp->x * right->z + tmp->y * up->z + tmp->z * dir->z;
	tmp->destroy(tmp);
	right->destroy(right);
	up->destroy(up);
	return (result);
}

static void		set_normal_vec(t_flag *flag, t_vector *intersection_point,
							t_scene *scene, t_object *object)
{
	if (flag->type == 's')
		object->normal_vec = scene->sphere[flag->index]->
				get_normal(scene->sphere[flag->index], intersection_point);
	if (flag->type == 'p')
		object->normal_vec = scene->plane[flag->index]->
				get_normal(scene->plane[flag->index]);
	if (flag->type == 'c')
		object->normal_vec = scene->cylinder[flag->index]->
				get_normal(scene->cylinder[flag->index], intersection_point);
	if (flag->type == 'q')
		object->normal_vec = scene->square[flag->index]->
				get_normal(scene->square[flag->index]);
	if (flag->type == 't')
		object->normal_vec = scene->triangle[flag->index]->
				get_normal(scene->triangle[flag->index]);
}

static void		set_color(t_flag *flag, t_scene *scene, t_object *object)
{
	if (flag->type == 's')
		object->color = scene->sphere[flag->index]->color;
	if (flag->type == 'p')
		object->color = scene->plane[flag->index]->color;
	if (flag->type == 'c')
		object->color = scene->cylinder[flag->index]->color;
	if (flag->type == 'q')
		object->color = scene->square[flag->index]->color;
	if (flag->type == 't')
		object->color = scene->triangle[flag->index]->color;
}

t_vector		*intersection(t_scene *scene, t_object *object,
						t_vector *o, t_vector *d)
{
	t_vector	*result;
	t_flag		flag;

	result = new_vector(0, 0, 0);
	object->exist = 0;
	flag.type = 0;
	flag.t = 1e100;
	intersection_with_sphere(&flag, scene, o, d);
	intersection_with_plane(&flag, scene, o, d);
	intersection_with_cylinder(&flag, scene, o, d);
	intersection_with_square(&flag, scene, o, d);
	intersection_with_triangle(&flag, scene, o, d);
	if (flag.type != 0)
	{
		object->exist = 1;
		object->t = flag.t;
		d->product_by_scalar(d, flag.t);
		result = vec_sum(o, d, result);
	}
	set_color(&flag, scene, object);
	set_normal_vec(&flag, result, scene, object);
	return (result);
}
