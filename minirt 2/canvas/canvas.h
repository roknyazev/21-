/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   canvas.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/27 00:52:00 by wrudy             #+#    #+#             */
/*   Updated: 2020/08/27 06:05:17 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_CANVAS_H
#define MINIRT_CANVAS_H
#include "../linalg/linalg.h"

typedef struct	s_color
{
	t_vector	*color;
	int 		(* get_hex_color)(struct s_color *self);
	void 		(* destroy)(struct s_color *self);
}				t_color;

typedef struct	s_canvas
{

}				t_canvas;

void 			color_destructor(t_color *color);
t_color			*color(float r, float g, float b);

#endif
