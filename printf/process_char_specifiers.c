/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_char_specifiers.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 22:46:17 by wrudy             #+#    #+#             */
/*   Updated: 2020/07/15 23:31:29 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void case_with_minus(int width, char c)
{
	int		i;
	char	filler;

	filler = ' ';
	write(1, &c, 1);
	i = 1;
	while (i < width)
	{
		write(1, &filler, 1);
		i++;
	}
}

static void case_without_minus(char *s_flag, int width, char c)
{
	int		i;
	char 	filler1;
	char 	filler2;

	i = 0;
	filler1 = '0';
	filler2 = ' ';
	while (i < width - 1)
	{
		if (s_flag != NULL && ft_strchr(s_flag, '0'))
			write(1, &filler1, 1);
		else
			write(1, &filler2, 1);
		i++;
	}
	write(1, &c, 1);
}

int			process_char_specifiers(char *s_fl, char *s_wid, unsigned char c)
{
	int		width;

	if (s_wid != NULL)
		width = ft_atoi(s_wid);
	else
		width = 0;
	if (s_fl != NULL && ft_strchr(s_fl, '-'))
		case_with_minus(width, (char)c);
	else
		case_without_minus(s_fl, width, (char)c);
	if (width > 1)
		return (width);
	else
		return (1);
}

