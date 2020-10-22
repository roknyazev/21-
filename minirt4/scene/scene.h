/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/21 22:09:27 by wrudy             #+#    #+#             */
/*   Updated: 2020/10/21 22:29:16 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_SCENE_H
#define MINIRT_SCENE_H

#include "scene_objects/objects.h"
#include "linalg/linalg.h"
#include "canvas/canvas.h"
#include "../gnl/get_next_line.h"

/*
** class light
*/
typedef struct s_light
{
	t_vector	*pos;
	t_color		*color;
	double		brightness;
	void 		(* destroy)(struct s_light *self);
}				t_light;

t_light			*new_light(t_vector *pos, t_color *color, double brightness);
void 			light_destructor(t_light *self);

/*
** class ambient light
*/
typedef struct	s_amblight
{
	double		ratio;
	t_color		*color;
	void 		(* destroy)(struct s_amblight *self);
}				t_amblight;

t_amblight		*new_amblight(t_color *color, double ratio);
void 			amblight_destructor(t_amblight *self);

/*
** class camera
*/
typedef struct	s_camera
{
	t_vector	*pos;
	t_vector	*orient;
	double 		fov;
	double		distance_to_viewport;
	void 		(* destroy)(struct s_camera *self);
}				t_camera;

t_camera		*new_camera(t_vector *pos, t_vector *orient, double fov);
void 			camera_destructor(t_camera *self);

/*
** class scene
*/
typedef struct	s_scene
{
	int 		resolution_x;
	int 		resolution_y;
	t_camera	**camera;

	t_amblight	*ambient_light;
	t_light		**light;

	t_sphere	**sphere;
	t_plane		**plane;
	t_cylinder	**cylinder;
	t_square	**square;
	t_triangle	**triangle;

	int 		camera_count;
	int 		lights_count;

	int			resolution_lines_count;
	int 		amblight_lines_count;
	int 		sphere_count;
	int 		plane_count;
	int 		cylinder_count;
	int 		square_count;
	int 		triangle_count;

	void 		(* destroy)(struct s_scene *self);
}				t_scene;

typedef struct s_obj_indexes
{
	int camera_i;
	int light_i;
	int plane_i;
	int sphere_i;
	int square_i;
	int cylinder_i;
	int triangle_i;
}				t_obj_indexes;


t_scene			*new_scene(char *path);
void 			scene_destructor(t_scene *self);

void 			parse(char *path, t_scene *scene);
void 			parse_resolution(const char *line, t_scene *scene);
t_amblight 		*parse_amblight(const char *line);
t_camera 		*parse_camera(const char *line);
t_light			*parse_light(const char *line);
t_sphere 		*parse_sphere(const char *line);
t_plane 		*parse_plane(const char *line);
t_square 		*parse_square(const char *line);
t_cylinder 		*parse_cylinder(const char *line);
t_triangle 		*parse_triangle(const char *line);




int				ft_isdigit(int c);
int				ft_atoi(const char *nptr);
int				ft_atof(const char *nptr, double *nmb);
int				parse_pos(const char *line, t_vector *pos);
int				parse_orient(const char *line, t_vector *orient);
int				parse_color(const char *line, t_color *color);
#endif
