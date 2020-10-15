/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/09/24 19:38:45 by wrudy             #+#    #+#             */
/*   Updated: 2020/10/13 16:53:48 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "objects.h"

t_object	*new_object()
{
	t_object *result;

	if (!(result = malloc(sizeof(t_object))))
		return (NULL);
	result->exist = 0;
	result->normal_vec = NULL;
	result->color = NULL;
	result->destroy = object_destructor;
	return (result);
}

void 		object_destructor(t_object *self)
{
	if (self->normal_vec != NULL && self->exist)
		self->normal_vec->destroy(self->normal_vec);
	free(self);
}