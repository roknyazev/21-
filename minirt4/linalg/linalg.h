/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   linalg.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/08/26 21:37:41 by wrudy             #+#    #+#             */
/*   Updated: 2020/10/14 16:29:16 by wrudy            ###   ########.fr       */
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
	void		(* product_by_scalar)(struct s_vector *self, double scalar);
	double		(* magnitude)(struct s_vector *self);
	void 		(* destroy)(struct s_vector *self);
}				t_vector;

t_vector		*new_vector(double x, double y, double z);
void			self_multiplication_by_scalar(t_vector *self, double scalar);
double 			magnitude(t_vector *self);
void 			vector_destructor(t_vector *self);

double 			sc_mult(t_vector *vec1, t_vector *vec2);
t_vector		*vec_sum(t_vector *vec1, t_vector *vec2, t_vector *buf);
t_vector		*vec_diff(t_vector *vec1, t_vector *vec2, t_vector *buf);
t_vector		*multiplication_by_scalar(t_vector *vec, double scalar, t_vector *buf);
t_vector		*cross_product(t_vector *u, t_vector *v);
#endif
