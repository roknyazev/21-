/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_xtoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 20:03:00 by wrudy             #+#    #+#             */
/*   Updated: 2020/07/17 23:46:13 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_getorder(unsigned int n)
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

static void	ft_setdigits(char *number, unsigned int n, int den, char reg)
{
	unsigned int digit;

	digit = n / den;
	if (digit <= 9)
		*number = (char)(digit + '0');
	else
	{
		if (reg == 'x')
			*number = (char)(digit - 10 + 'a');
		else
			*number = (char)(digit - 10 + 'A');
	}
	if (den >= 16)
		return (ft_setdigits(number + 1, n % den, den / 16, reg));
	else
		*(number + 1) = '\0';
}

char		*pf_xtoa(unsigned long long n, char reg)
{
	char	*number;
	int		den;
	int		i;
	int		order;

	order = ft_getorder(n);
	den = 1;
	i = 0;
	while (i++ < order)
		den = den * 16;
	if ((number = malloc((order + 2) * sizeof(char))) == NULL)
		return (NULL);
	ft_setdigits(number, n, den, reg);
	return (number);
}
