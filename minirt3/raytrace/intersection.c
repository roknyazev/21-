/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersection.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/13 17:21:04 by wrudy             #+#    #+#             */
/*   Updated: 2020/10/15 16:58:54 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void 	intersection_with_sphere(t_flag *flag, t_scene *scene, t_vector *o, t_vector *d)
{
	int		i;
	double	solution;
	double	t;
	int		result_i;

	i = 0;
	t = flag->t;
	result_i = -1;
	while (i < scene->sphere_count)
	{
		solution = scene->sphere[i]->intersection(o, d, scene->sphere[i]);
		if (solution < t)
		{
			t = solution;
			result_i = i;
		}
		i++;
	}
	if (result_i >= 0)
	{
		flag->type = 's';
		flag->t = t;
		flag->index = result_i;
	}
}

void 	intersection_with_plane(t_flag *flag, t_scene *scene, t_vector *o, t_vector *d)
{
	int		i;
	double	solution;
	double	t;
	int		result_i;

	i = 0;
	t = flag->t;
	result_i = -1;
	while (i < scene->plane_count)
	{
		solution = scene->plane[i]->intersection(o, d, scene->plane[i]);
		if (solution < t)
		{
			t = solution;
			result_i = i;
		}
		i++;
	}
	if (result_i >= 0)
	{
		flag->type = 'p';
		flag->t = t;
		flag->index = result_i;
	}
}

void 	intersection_with_cylinder(t_flag *flag, t_scene *scene, t_vector *o, t_vector *d)
{
	int		i;
	double	solution;
	double	t;
	int		result_i;

	i = 0;
	t = flag->t;
	result_i = -1;
	while (i < scene->cylinder_count)
	{
		solution = scene->cylinder[i]->intersection(o, d, scene->cylinder[i]);
		if (solution < t)
		{
			t = solution;
			result_i = i;
		}
		i++;
	}
	if (result_i >= 0)
	{
		flag->type = 'c';
		flag->t = t;
		flag->index = result_i;
	}
}

void 	intersection_with_square(t_flag *flag, t_scene *scene, t_vector *o, t_vector *d)
{
	int		i;
	double	solution;
	double	t;
	int		result_i;

	i = 0;
	t = flag->t;
	result_i = -1;
	while (i < scene->square_count)
	{
		solution = scene->square[i]->intersection(o, d, scene->square[i]);
		if (solution < t)
		{
			t = solution;
			result_i = i;
		}
		i++;
	}
	if (result_i >= 0)
	{
		flag->type = 'q';
		flag->t = t;
		flag->index = result_i;
	}
}

void 	intersection_with_triangle(t_flag *flag, t_scene *scene, t_vector *o, t_vector *d)
{
	int		i;
	double	solution;
	double	t;
	int		result_i;

	i = 0;
	t = flag->t;
	result_i = -1;
	while (i < scene->triangle_count)
	{
		solution = scene->triangle[i]->intersection(o, d, scene->triangle[i]);
		if (solution < t)
		{
			t = solution;
			result_i = i;
		}
		i++;
	}
	if (result_i >= 0)
	{
		flag->type = 't';
		flag->t = t;
		flag->index = result_i;
	}
}
