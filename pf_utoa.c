/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_utoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 19:58:40 by wrudy             #+#    #+#             */
/*   Updated: 2020/07/17 23:46:13 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_getorder(unsigned int n)
{
	int order;

	order = 0;
	while (n >= 10)
	{
		n = n / 10;
		order++;
	}
	return (order);
}

static void	ft_setdigits(char *number, unsigned int n, int den)
{
	unsigned int digit;

	digit = n / den;
	*number = (char)(digit + '0');
	if (den >= 10)
		return (ft_setdigits(number + 1, n % den, den / 10));
	else
		*(number + 1) = '\0';
}

char		*pf_utoa(unsigned int n)
{
	char	*number;
	int		den;
	int		i;
	int		order;

	order = ft_getorder(n);
	den = 1;
	i = 0;
	while (i++ < order)
		den = den * 10;
	if ((number = malloc((order + 2) * sizeof(char))) == NULL)
		return (NULL);
	ft_setdigits(number, n, den);
	return (number);
}
