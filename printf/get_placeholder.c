/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_placeholder.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 20:45:18 by wrudy             #+#    #+#             */
/*   Updated: 2020/07/12 20:48:41 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

placeholder	*get_placeholder(char *format_string)
{
	placeholder	*plh;
	int			plh_len;

	plh = malloc(sizeof(placeholder));
	plh_len = 1;
	plh_len = plh_len + get_flag(format_string + plh_len, plh);
	plh_len = plh_len + get_width(format_string + plh_len, plh);
	plh_len = plh_len + get_precision(format_string + plh_len, plh);
	plh_len = plh_len + get_size(format_string + plh_len, plh);
	plh_len = plh_len + get_type(format_string + plh_len, plh);
	plh->len = plh_len;
	return (plh);
}
