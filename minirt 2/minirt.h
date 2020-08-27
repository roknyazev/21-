/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:47:39 by wrudy             #+#    #+#             */
/*   Updated: 2020/08/26 21:32:10 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_MINIRT_H
#define MINIRT_MINIRT_H
#include <stdlib.h>
#include <stdio.h>
#include "linalg/linalg.h"
#include "canvas/canvas.h"




typedef struct	s_camera
{
	float		viewport_width;
	float		viewport_height;
	float 		distance;
	t_vector	*coordinates;
	t_vector	*orientation;
}				t_camera;

/*
*				parsing .rt file
*/

/*
*				initialization
*/
t_canvas 		*canvas_constructor(int width, int height);

/*
*				freeing
*/
void 			canvas_destructor(t_canvas *canvas);

/*
*				ray tracing
*/
t_color			*ray_trace(int i, int j, int width, int height);

/*
*				colors
*/
t_color			*get_rgb_color(int i, int j, int width, int height);
int				get_hex_color(int i, int j, int width, int height);

#endif
