/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_int_specifier_support.cpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 22:18:48 by wrudy             #+#    #+#             */
/*   Updated: 2020/07/17 23:46:13 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_s_pr1(unsigned width, char c, char **str, char *cnt)
{
	unsigned		j;
	unsigned		i;
	unsigned		len;
	char			*s;

	i = 1;
	j = 0;
	s = *str;
	len = pf_strlen(cnt);
	while (i < width)
	{
		if (i < (width - len))
			s[i] = c;
		else
			s[i] = cnt[j++];
		i++;
	}
	s[i] = '\0';
}

void	fill_s_pr0(unsigned width, char c, char **str, char *cnt)
{
	unsigned		j;
	unsigned		i;
	unsigned		len;
	char			*s;

	i = 0;
	j = 0;
	s = *str;
	len = pf_strlen(cnt);
	while (i < width)
	{
		if (i < (width - len))
			s[i] = c;
		else
			s[i] = cnt[j++];
		i++;
	}
	s[i] = '\0';
}

void	fill_s_m(unsigned width, char c, char **str, char *cnt)
{
	unsigned		j;
	unsigned		i;
	unsigned		len;
	char			*s;

	j = 0;
	i = 0;
	s = *str;
	len = pf_strlen(cnt);
	while (i < width)
	{
		if (i < (width - len))
			s[i] = c;
		else
			s[i] = cnt[j++];
		i++;
	}
	s[i] = '\0';
}
