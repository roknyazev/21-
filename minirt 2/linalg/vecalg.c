/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecalg.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 22:59:37 by wrudy             #+#    #+#             */
/*   Updated: 2020/09/16 21:17:17 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "linalg.h"

t_vector	*new_vector(double x, double y, double z)
{
	t_vector *result;

	if (!(result = malloc(sizeof(t_vector))))
		return (NULL);
	result->x = x;
	result->y = y;
	result->z = z;
	result->scalar_product = scalar_multiplication;
	result->destroy = vector_destructor;
	return (result);
}

void		scalar_multiplication(t_vector *vector, double scalar)
{
	vector->x = (vector->x) * scalar;
	vector->y = (vector->y) * scalar;
	vector->z = (vector->z) * scalar;
}

void 		vector_destructor(t_vector *vector)
{
	free(vector);
}