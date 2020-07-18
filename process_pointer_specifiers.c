/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_pointer_specifiers.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:43:56 by wrudy             #+#    #+#             */
/*   Updated: 2020/07/17 23:46:13 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	case_with_minus(int width, int str_len, char *ptr_str)
{
	int		i;
	char	c;

	write(1, "0x", 2);
	i = 2;
	c = ' ';
	while (i < width)
	{
		if (i < str_len + 2)
			write(1, &ptr_str[i - 2], 1);
		else
			write(1, &c, 1);
		i++;
	}
}

static void	case_without_minus(int width, int str_len, char *ptr_str)
{
	int		i;
	int		j;
	char	c;

	i = 0;
	c = ' ';
	while (i < (width - str_len - 2))
	{
		write(1, &c, 1);
		i++;
	}
	write(1, "0x", 2);
	j = 0;
	while (j < str_len)
	{
		write(1, &ptr_str[j], 1);
		j++;
	}
}

int			pr_ptr_spec(char *s_fl, char *s_w, unsigned long long p)
{
	int		width;
	int		str_len;
	char	*pointer_string;

	pointer_string = pf_ptoa(p);
	str_len = pf_strlen(pointer_string);
	if (s_w == NULL)
		width = str_len + 2;
	else
	{
		width = pf_atoi(s_w);
		if (width < (str_len + 2))
			width = str_len + 2;
	}
	if (s_fl != NULL && pf_strchr(s_fl, '-'))
		case_with_minus(width, str_len, pointer_string);
	else
		case_without_minus(width, str_len, pointer_string);
	return (width);
}
