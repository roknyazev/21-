/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raytrace.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/27 07:48:47 by wrudy             #+#    #+#             */
/*   Updated: 2020/10/13 17:55:38 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef MINIRT_RAYTRACE_H
#define MINIRT_RAYTRACE_H
#include "../canvas/canvas.h"
#include "../linalg/linalg.h"
#include "../scene/scene.h"

typedef struct	s_flag
{
	char 	type;
	double	t;
	int 	index;
}				t_flag;

t_color		*raytrace(int canvas_x, int canvas_y, t_scene *scene, int camera_index);
t_vector	*ray_cast(int cx, int cy, t_scene *scene, int camera_index);
t_vector	*intersection(t_scene *scene, t_object *object, t_vector *o, t_vector *d);
void 		intersection_with_sphere(t_flag *flag, t_scene *scene, t_vector *o, t_vector *d);
void 	intersection_with_plane(t_flag *flag, t_scene *scene, t_vector *o, t_vector *d);
void 	intersection_with_cylinder(t_flag *flag, t_scene *scene, t_vector *o, t_vector *d);
void 	intersection_with_square(t_flag *flag, t_scene *scene, t_vector *o, t_vector *d);
void 	intersection_with_triangle(t_flag *flag, t_scene *scene, t_vector *o, t_vector *d);

#endif
