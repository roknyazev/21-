/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:47:39 by wrudy             #+#    #+#             */
/*   Updated: 2020/10/26 16:59:10 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_MINIRT_H
#define MINIRT_MINIRT_H
#include <stdlib.h>
#include <stdio.h>

#include "linalg/linalg.h"
#include "canvas/canvas.h"
#include "scene/scene.h"
#include "raytrace/raytrace.h"
#include "bmp/bmp.h"
#include "mlx/mlx.h"

# define KEY_TAB 48
# define KEY_ESC 53

typedef struct  s_data
{
	void        *img;
	char        *addr;
	int         bpp;
	int         line_lenght;
	int         endian;
}               t_data;

typedef struct  s_mlx
{
	void    	*mlx;
	void    	*win;
}               t_mlx;

typedef struct	s_rt
{
	t_mlx		mlx;
	t_data		img;
	t_scene		*scene;
}				t_rt;

t_canvas		*render(t_scene *scene, int camera_index);
void			my_mlx_pixel_put(t_data *data, int x, int y, int color);
void			put_pixels_into_image(t_scene *scene, t_canvas *canvas, t_data img);
int				keypress(int key, t_rt *rt);
int				red_cross_click(int check);

#endif
