/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 23:54:16 by wrudy             #+#    #+#             */
/*   Updated: 2020/10/15 20:03:01 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_OBJECTS_H
#define MINIRT_OBJECTS_H

#include "linalg/linalg.h"
#include "canvas/canvas.h"

/*
** class sphere
*/
typedef	struct	s_sphere
{
	t_vector	*pos;
	t_color		*color;
	double		diameter;
	t_vector	*(* get_normal)(struct s_sphere *self, t_vector *intersection_point);
	double 		(* intersection)(t_vector *o, t_vector *d, struct s_sphere *sphere);
	void 		(* destroy)(struct s_sphere *self);
}				t_sphere;

t_sphere		*new_sphere(t_vector *pos, t_color *color, double d);
t_vector		*get_sphere_normal(struct s_sphere *self, t_vector *intersection_point);
double			sphere_intersection(t_vector *o, t_vector *d, t_sphere *sphere);
void 			sphere_destructor(t_sphere *self);

/*
** class plane
*/
typedef struct s_plane
{
	t_vector	*pos;
	t_color		*color;
	t_vector	*normal_vector;
	t_vector	*(* get_normal)(struct s_plane *self);
	double 		(* intersection)(t_vector *o, t_vector *d, struct s_plane *plane);
	void 		(* destroy)(struct s_plane *self);
}				t_plane;

t_plane			*new_plane(t_vector *pos, t_vector *normal ,t_color *color);
t_vector		*get_plane_normal(t_plane *self);
double			plane_intersection(t_vector *o, t_vector *d, t_plane *plane);
void 			plane_destructor(t_plane *self);
/*
** square
*/
typedef struct s_square
{
	t_vector	*pos;
	t_color		*color;
	t_vector	*normal_vector;
	t_vector	*(* get_normal)(struct s_square *self);
	double 		(* intersection)(t_vector *o, t_vector *d, struct s_square *square);
	void 		(* destroy)(struct s_square *self);
	double		side_size;
}				t_square;

t_square		*new_square(t_vector *pos, t_vector *normal, t_color *color, double side_size);
t_vector		*get_square_normal(t_square *self);
double			square_intersection(t_vector *o, t_vector *d, t_square *square);
void 			square_destructor(t_square *self);
/*
** class cylinder
*/
typedef struct s_cylinder
{
	t_color		*color;
	t_vector	*(* get_normal)();
	double 		(* intersection)();
}				t_cylinder;

/*
** class triangle
*/
typedef struct s_triangle
{
	t_color		*color;
	t_vector	*(* get_normal)();
	double 		(* intersection)();
}				t_triangle;

/*
** class object
*/
typedef struct s_object
{
	int 		exist;
	double		t;
	t_color		*color;
	t_vector	*normal_vec;
	void 		(* destroy)(struct s_object *self);
}				t_object;

t_object	*new_object();
void 		object_destructor(t_object *self);
#endif
