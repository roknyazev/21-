/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   objects.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 23:54:16 by wrudy             #+#    #+#             */
/*   Updated: 2020/09/24 22:25:49 by wrudy            ###   ########.fr       */
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
	double 		specular;
	void 		(* destroy)(struct s_sphere *self);
}				t_sphere;

t_sphere		*new_sphere(t_vector *pos, t_color *color, double d, double specular);
void 			sphere_destructor(t_sphere *self);

/*
** class plane
*/
typedef struct s_plane
{

}				t_plane;

/*
** square
*/
typedef struct s_square
{

}				t_square;

/*
** class cylinder
*/
typedef struct s_cylinder
{

}				t_cylinder;

/*
** class triangle
*/
typedef struct s_triangle
{

}				t_triangle;

/*
** class object
*/
typedef struct s_object
{
	t_sphere	*sphere;
	t_plane		*plane;
	t_square	*square;
	t_cylinder	*cylinder;
	t_triangle	*triangle;
	void 		(* destroy)(struct s_object *self);
}				t_object;

t_object	*new_object();
void 		object_destructor(t_object *self);
#endif
