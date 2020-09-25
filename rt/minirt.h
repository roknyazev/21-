/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:47:39 by wrudy             #+#    #+#             */
/*   Updated: 2020/09/23 20:23:16 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_MINIRT_H
#define MINIRT_MINIRT_H
#include <stdlib.h>
#include <stdio.h>

#include "linalg/linalg.h"
#include "canvas/canvas.h"
#include "scene/scene.h"

t_canvas	*render(t_scene *scene, int selected_camera);


t_color		*raytrace(int canvas_x, int canvas_y, t_scene *scene, int selected_camera);

#endif
