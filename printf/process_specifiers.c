/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_specifiers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 18:05:23 by wrudy             #+#    #+#             */
/*   Updated: 2020/07/14 21:31:51 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int max(int width, int precision, int len)
{
	if (width >= precision)
	{
		if (width >= len)
			return (width);
		else
			return (len);
	}
	else
	{
		if (precision >= len)
			return (precision);
		else
			return (len);
	}
}

static char *case_without_precision(char *s_flag, char *s_width, char *nbr, int len)
{
	char *result;
	char *tmp;
	int filler_size;
	int width;

	if (s_width != NULL)
		width = ft_atoi(s_width);
	else
		width = 0;
	if (width >= len)
	{
		tmp = malloc(sizeof(char) * (width + 1));
		filler_size = width - len;
	}
	else
	{
		tmp = malloc(sizeof(char) * (len + 1));
		filler_size = 0;
	}
	result = tmp;
	if (ft_strchr(s_flag, '0') && !ft_strchr(s_flag, '-'))
	{
		while (filler_size--)
			*(tmp++) = '0';
		while (len--)
			*(tmp++) = *(nbr++);
	}
	else if (ft_strchr(s_flag, '-'))
	{
		while (len--)
			*(tmp++) = *(nbr++);
		while (filler_size--)
			*(tmp++) = ' ';
	}
	else
	{
		while (filler_size--)
			*(tmp++) = ' ';
		while (len--)
			*(tmp++) = *(nbr++);
	}
	return (result);
}

char *case_width_precision(char *s_flag, char *s_precision, char *s_width, char *nbr, int len)
{
	
}

char *process_int_specifiers(char *s_flag, char *s_width, char *s_precision, char *nbr)
{
	char	*result;
	int		len;


	len = ft_strlen(nbr);
	if (s_precision == NULL)
		result = case_without_precision(s_flag, s_width, nbr, len);
	else
		result = case_with_precision(s_flag, s_precision, s_width, nbr, len);
	return result;
}

