/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/05/20 14:17:41 by wrudy             #+#    #+#             */
/*   Updated: 2020/07/17 23:46:13 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int		get_nmb(const char *str)
{
	size_t number;
	size_t order;
	size_t len;

	order = 1;
	len = 0;
	while (pf_isdigit(str[len]))
		len++;
	number = (int)(*str) - '0';
	while (order < len)
	{
		number = number * 10;
		order++;
	}
	if (order > 1)
		return ((int)number + get_nmb(str + 1));
	else
		return (number);
}

size_t			pf_atoi(const char *nptr)
{
	int sign;

	while (*nptr == ' ' || *nptr == '\v' || *nptr == '\r' \
		|| *nptr == '\t' || *nptr == '\n' || *nptr == '\f')
		nptr++;
	if (*nptr == '-')
		sign = -1;
	else
		sign = 1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	if (pf_isdigit(*nptr))
		return (get_nmb(nptr) * sign);
	else
		return (0);
}
