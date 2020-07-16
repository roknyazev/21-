/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_str_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 23:44:28 by wrudy             #+#    #+#             */
/*   Updated: 2020/07/16 16:34:46 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void case_with_minus(int width, int max_str_len, char *str)
{
	int		i;
	char	c;

	i = 0;
	c = ' ';
	while (i < width)
	{
		if (i < max_str_len)
			write(1, &str[i], 1);
		else
			write(1, &c, 1);
		i++;
	}
}

static void case_without_minus(int width, int max_str_len, char *str)
{
	int		i;
	char 	c;

	i = 0;
	c = ' ';
	while (i < width)
	{
		if (i < (width - max_str_len))
			write(1, &c, 1);
		else
			write(1, &str[i - width + max_str_len], 1);
		i++;
	}
}

int	process_str_specifiers(char *s_fl, char *s_wid, char *s_pr, char *str)
{
	int		width;
	int		max_str_len;
	int 	str_len;

	str_len = ft_strlen(str);
	if (s_pr != NULL)
		max_str_len = ft_atoi(s_pr);
	else
		max_str_len = str_len;
	if (s_wid != NULL)
	{
		width = ft_atoi(s_wid);
		if (width < max_str_len)
			width = max_str_len;
	}
	else
		width = max_str_len;
	if (s_fl != NULL && ft_strchr(s_fl, '-'))
		case_with_minus(width, max_str_len, str);
	else
		case_without_minus(width, max_str_len, str);
	return (width);
}