/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/13 21:47:39 by wrudy             #+#    #+#             */
/*   Updated: 2020/09/22 21:31:47 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_MINIRT_H
#define MINIRT_MINIRT_H
#include <stdlib.h>
#include <stdio.h>

#include "linalg/linalg.h"
#include "canvas/canvas.h"
#include "scene/scene.h"

t_canvas	*render(t_scene *scene);

#endif
