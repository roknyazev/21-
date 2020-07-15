/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_int_specifier_support.cpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 22:18:48 by wrudy             #+#    #+#             */
/*   Updated: 2020/07/15 22:18:48 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_str_with_precision_1(int width, char c, char **str, char *content)
{
	int		j;
	int		i;
	int		len;
	char	*s;

	i = 1;
	j = 0;
	s = *str;
	len = ft_strlen(content);
	while (i < width)
	{
		if (i < (width - len))
			s[i] = c;
		else
			s[i] = content[j++];
		i++;
	}
	s[i] = '\0';
}

void	fill_str_with_precision_0(int width, char c, char **str, char *content)
{
	int		j;
	int		i;
	int		len;
	char	*s;

	i = 0;
	j = 0;
	s = *str;
	len = ft_strlen(content);
	while (i < width)
	{
		if (i < (width - len))
			s[i] = c;
		else
			s[i] = content[j++];
		i++;
	}
	s[i] = '\0';
}

void	fill_str_without_minus(int width, char c, char **str, char *content)
{
	int		j;
	int		i;
	int		len;
	char	*s;

	j = 0;
	i = 0;
	s = *str;
	len = ft_strlen(content);
	while (i < width)
	{
		if (i < (width - len))
			s[i] = c;
		else
			s[i] = content[j++];
		i++;
	}
	s[i] = '\0';
}
