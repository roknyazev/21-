/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_str_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 23:44:28 by wrudy             #+#    #+#             */
/*   Updated: 2020/07/17 23:46:13 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	case_with_minus(size_t width, size_t max_str_len, char *str)
{
	unsigned	i;
	char		c;

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

static void	case_without_minus(unsigned width, unsigned max_str_len, char *str)
{
	unsigned	i;
	char		c;

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

int			pr_str_spec(char *s_fl, char *s_w, char *s_p, char *str)
{
	int			width;
	unsigned	max_str_len;
	unsigned	str_len;

	str_len = pf_strlen(str);
	if (s_p != NULL)
	{
		if ((max_str_len = pf_atoi(s_p)) > str_len)
			max_str_len = str_len;
	}
	else
		max_str_len = str_len;
	if (s_w != NULL)
	{
		width = pf_atoi(s_w);
		if (width < (int)max_str_len)
			width = (int)max_str_len;
	}
	else
		width = (int)max_str_len;
	if (s_fl != NULL && pf_strchr(s_fl, '-'))
		case_with_minus(width, max_str_len, str);
	else
		case_without_minus(width, max_str_len, str);
	return (width);
}
