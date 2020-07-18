/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptrtoa.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 18:17:18 by wrudy             #+#    #+#             */
/*   Updated: 2020/07/17 23:46:13 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_getorder(unsigned long long n)
{
	int order;

	order = 0;
	while (n >= 16)
	{
		n = n / 16;
		order++;
	}
	return (order);
}

static void	ft_setdigits(char *p, unsigned long long n, unsigned long long den)
{
	unsigned int digit;

	digit = n / den;
	if (digit <= 9)
		*p = (char)(digit + '0');
	else
		*p = (char)(digit - 10 + 'a');
	if (den >= 16)
		return (ft_setdigits(p + 1, n % den, den / 16));
	else
		*(p + 1) = '\0';
}

char		*pf_ptoa(unsigned long long n)
{
	char				*number;
	unsigned long long	den;
	int					i;
	int					order;

	order = ft_getorder(n);
	den = 1;
	i = 0;
	while (i++ < order)
		den = den * 16;
	if ((number = malloc((order + 2) * sizeof(char))) == NULL)
		return (NULL);
	ft_setdigits(number, n, den);
	return (number);
}
