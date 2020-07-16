/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_int_specifier_support.cpp                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 22:18:48 by wrudy             #+#    #+#             */
/*   Updated: 2020/07/16 21:21:05 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	fill_s_with_pr1(int width, char c, char **str, char *cnt)
{
	int		j;
	int		i;
	int		len;
	char	*s;

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

void	fill_s_with_pr0(int width, char c, char **str, char *cnt)
{
	int		j;
	int		i;
	int		len;
	char	*s;

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

void	fill_s_without_m(int width, char c, char **str, char *cnt)
{
	int		j;
	int		i;
	int		len;
	char	*s;

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
