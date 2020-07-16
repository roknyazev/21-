/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_pointer_specifiers.c                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/16 16:43:56 by wrudy             #+#    #+#             */
/*   Updated: 2020/07/16 19:02:08 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void case_with_minus(int width, int str_len, char *ptr_str)
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

static void case_without_minus(int width, int str_len, char *ptr_str)
{
	int		i;
	char 	c;

	i = 0;
	c = ' ';
	while (i < (width - str_len - 2))
	{
		write(1, &c, 1);
		i++;
	}
	write(1, "0x", 2);
	while (i < width)
	{
		write(1, &ptr_str[i - width + str_len], 1);
		i++;
	}
}

int	process_ptr_specifiers(char *s_fl, char *s_wid, unsigned long long ptr)
{
	int		width;
	int 	str_len;
	char	*pointer_string;

	pointer_string = ft_ptoa(ptr);
	str_len = ft_strlen(pointer_string);
	if (s_wid == NULL)
		width =	str_len;
	else
	{
		width = ft_atoi(s_wid);
		if (width < str_len)
			width = str_len;
	}
	if (s_fl != NULL && ft_strchr(s_fl, '-'))
		case_with_minus(width, str_len, pointer_string);
	else
		case_without_minus(width, str_len, pointer_string);
	return (width);
}
