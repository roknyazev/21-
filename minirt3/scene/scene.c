/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scene.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 20:33:31 by wrudy             #+#    #+#             */
/*   Updated: 2020/10/19 21:58:32 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_scene			*new_scene(char *path)
{
	/* FIXME Полность переписать*/
	path = NULL;
	t_scene *result;

	t_vector	*light_pos1;
	t_color		*light_color1;
	double		light_brightness1;

	t_vector	*light_pos2;
	t_color		*light_color2;
	double		light_brightness2;

	t_vector	*light_pos3;
	t_color		*light_color3;
	double		light_brightness3;

	t_vector	*light_pos4;
	t_color		*light_color4;
	double		light_brightness4;


	/*
	 *
	 */

	t_vector	*camera_pos;
	t_vector	*camera_orient;
	double 		fov;

	t_vector	*sphere1_pos;
	t_color		*sphere1_color;
	double		sphere1_diameter;

	t_vector	*sphere2_pos;
	t_color		*sphere2_color;
	double		sphere2_diameter;

	t_vector	*sphere3_pos;
	t_color		*sphere3_color;
	double		sphere3_diameter;

	t_vector	*sphere4_pos;
	t_color		*sphere4_color;
	double		sphere4_diameter;

	t_vector	*sphere5_pos;
	t_color		*sphere5_color;
	double		sphere5_diameter;

	t_vector	*sphere6_pos;
	t_color		*sphere6_color;
	double		sphere6_diameter;

	t_vector	*sphere7_pos;
	t_color		*sphere7_color;
	double		sphere7_diameter;


	if (!(result = malloc(sizeof(t_scene))))
		return (NULL);

	result->resolution_x = 800;
	result->resolution_y = 600;

	result->lights_count = 4;
	result->light = malloc(result->lights_count * sizeof(t_light *));

	light_pos1 = new_vector(15, 15, 0);
	light_color1 = new_color(255, 255, 255);
	light_brightness1 = 0.65;
	result->light[0] = new_light(light_pos1, light_color1, light_brightness1);

	light_pos2 = new_vector(-15, 15, 30);
	light_color2 = new_color(255, 255, 255);
	light_brightness2 = 0.3;
	result->light[1] = new_light(light_pos2, light_color2, light_brightness2);

	light_pos3 = new_vector(15, 15, -10);
	light_color3 = new_color(255, 255, 255);
	light_brightness3 = 0.4;
	result->light[2] = new_light(light_pos3, light_color3, light_brightness3);

	light_pos4 = new_vector(0, 1, 0);
	light_color4 = new_color(255, 255, 255);
	light_brightness4 = 0.65;
	result->light[3] = new_light(light_pos4, light_color4, light_brightness4);

	t_color *amblight_color;
	amblight_color = new_color(0xFF, 0xFF, 0xFF);
	result->ambient_light = new_amblight(amblight_color, 0.1);

	result->camera_count = 1;
	result->camera = malloc(result->camera_count * sizeof(t_camera *));
	camera_pos = new_vector(-30, 25, -45);
	//camera_orient = new_vector(0, -1, 0);
	camera_orient = new_vector(1, -1, 2); //FIXME
	fov =70;
	result->camera[0] = new_camera(camera_pos, camera_orient, fov, result->resolution_x);

	result->plane_count = 1;
	result->plane = malloc(result->plane_count * sizeof(t_plane *));
	t_vector *plane1_pos;
	t_color *plane1_color;
	t_vector *plane1_norm;
	t_plane *plane1;
	plane1_pos = new_vector(0, -6, 0);
	plane1_norm = new_vector(0, -1, 0);
	plane1_color = new_color(60, 25, 50);
	plane1 = new_plane(plane1_pos, plane1_norm, plane1_color);

	result->plane[0] = plane1;

	result->square_count = 1;
	result->square = (t_square **)calloc(result->square_count, sizeof(t_square *));

	t_vector *square_pos;
	t_color *square_color;
	t_vector *square_norm;
	t_square *square;
	square_pos = new_vector(0, 0, 0);
	square_norm = new_vector(0.3, 1, 0);
	square_color = new_color(70, 140, 180);
	square = new_square(square_pos, square_norm, square_color, 10);

	result->square[0] = square;

	result->cylinder_count = 1;

	result->cylinder = (t_cylinder **)calloc(result->cylinder_count, sizeof(t_cylinder *));

	t_vector *cylinder_pos;
	t_color *cylinder_color;
	t_vector *cylinder_norm;
	t_cylinder *cylinder;
	cylinder_pos = new_vector(-30, 0, -10);
	cylinder_norm = new_vector(-0.265, 0, 1);
	cylinder_color = new_color(10, 60, 80);
	cylinder = new_cylinder(cylinder_pos, cylinder_norm, cylinder_color, 20);
	result->cylinder[0] = cylinder;

	result->triangle_count = 1;
	result->triangle = (t_triangle **)calloc(result->triangle_count, sizeof(t_triangle *));
	t_vector *triangle_pos1;
	t_vector *triangle_pos2;
	t_vector *triangle_pos3;
	t_color *triangle_color;
	t_triangle *triangle;
	triangle_pos1 = new_vector(20, 0, -10);
	triangle_pos2 = new_vector(10, 0, 10);
	triangle_pos3 = new_vector(30, 15, 20);

	triangle_color = new_color(100, 160, 80);
	triangle = new_triangle(triangle_pos1, triangle_pos2, triangle_pos3, triangle_color);
	result->triangle[0] = triangle;



	result->sphere_count = 6;
	result->sphere = (t_sphere **)malloc(result->sphere_count *  sizeof(t_sphere *));

	sphere1_pos = new_vector(0, 0, -23);
	sphere1_color = new_color(0xFF, 0xFF, 0xFF);
	sphere1_diameter = 17;

	sphere2_pos = new_vector(0, 10, 0);
	sphere2_color = new_color(250, 130, 0);
	sphere2_diameter = 7;

	sphere3_pos = new_vector(-8.5, 0, 0);
	sphere3_color = new_color(40, 250, 250);
	sphere3_diameter = 7;

	sphere4_pos = new_vector(8.2, 0, 0);
	sphere4_color = new_color(20, 60, 100);
	sphere4_diameter = 7;

	sphere5_pos = new_vector(0, 10, 20);
	sphere5_color = new_color(220, 250, 10);
	sphere5_diameter = 8;

	//sphere6_pos = new_vector(0, -5000, 0);
	//sphere6_color = new_color(60, 25, 50);
	//sphere6_diameter = 10000 - 10;

	sphere7_pos = new_vector(-15, 3, 36);
	sphere7_color = new_color(150, 50, 50);
	sphere7_diameter = 15;

	result->sphere[0] = new_sphere(sphere1_pos, sphere1_color, sphere1_diameter);
	result->sphere[1] = new_sphere(sphere2_pos, sphere2_color, sphere2_diameter);
	result->sphere[2] = new_sphere(sphere3_pos, sphere3_color, sphere3_diameter);
	result->sphere[3] = new_sphere(sphere4_pos, sphere4_color, sphere4_diameter);
	result->sphere[4] = new_sphere(sphere5_pos, sphere5_color, sphere5_diameter);
	result->sphere[5] = new_sphere(sphere7_pos, sphere7_color, sphere7_diameter);

	result->destroy = scene_destructor;
	return (result);
}

void 			scene_destructor(t_scene *self)
{
	/* FIXME  Полность переписать*/
	free(self);
}
