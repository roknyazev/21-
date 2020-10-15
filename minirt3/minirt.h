/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:47:39 by wrudy             #+#    #+#             */
/*   Updated: 2020/10/13 17:45:44 by wrudy            ###   ########.fr       */
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

t_canvas	*render(t_scene *scene, int camera_index);


#endif
