/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/22 20:20:11 by wrudy             #+#    #+#             */
/*   Updated: 2020/09/22 20:22:54 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

t_camera		*new_camera(t_vector *pos, t_vector *orient, double fov)
{
	t_camera *result;

	if (!(result = malloc(sizeof(t_camera))))
		return (NULL);
	result->pos = pos;
	result->orient = orient;
	result->fov = fov;
	result->destroy = camera_destructor;
	return (result);
}
void 			camera_destructor(t_camera *self)
{
	self->pos->destroy(self->pos);
	self->orient->destroy(self->orient);
	free(self);
}
