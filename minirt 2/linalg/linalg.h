/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linalg.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 21:37:41 by wrudy             #+#    #+#             */
/*   Updated: 2020/09/16 23:12:39 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_LINALG_H
# define MINIRT_LINALG_H

# include "stdlib.h"
# include "math.h"

/*
** class vector
*/
typedef struct	s_vector
{
	double		x;
	double		y;
	double		z;
	void		(* scalar_product)(struct s_vector *self, double scalar);
	void 		(* destroy)(struct s_vector *self);
}				t_vector;

t_vector		*new_vector(double x, double y, double z);
void			scalar_multiplication(t_vector *vector, double scalar);
void 			vector_destructor(t_vector *vector);

#endif
