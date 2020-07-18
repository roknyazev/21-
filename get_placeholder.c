/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_placeholder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 20:45:18 by wrudy             #+#    #+#             */
/*   Updated: 2020/07/17 23:46:13 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_placehold	*get_placeholder(char *format_string)
{
	t_placehold	*plh;
	int			plh_len;

	plh = malloc(sizeof(t_placehold));
	plh_len = 1;
	plh_len = plh_len + get_flag(format_string + plh_len, plh);
	plh_len = plh_len + get_width(format_string + plh_len, plh);
	plh_len = plh_len + get_precision(format_string + plh_len, plh);
	plh_len = plh_len + get_size(format_string + plh_len, plh);
	plh_len = plh_len + get_type(format_string + plh_len, plh);
	plh->len = plh_len;
	return (plh);
}
