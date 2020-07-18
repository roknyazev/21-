/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specifiers.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 20:49:21 by wrudy             #+#    #+#             */
/*   Updated: 2020/07/17 23:46:13 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	get_flag(const char *f_str, t_placehold *plh)
{
	int		len;
	char	*flag;

	len = 0;
	while (f_str[len] == '-' || f_str[len] == '+' || f_str[len] == ' ' ||
	f_str[len] == '#' || f_str[len] == '0')
		len++;
	if (len == 0)
	{
		plh->flag = NULL;
		return (0);
	}
	if (!(flag = malloc(sizeof(char) * (len + 1))))
		return (0);
	len = 0;
	while (f_str[len] == '-' || f_str[len] == '+' || f_str[len] == ' ' ||
	f_str[len] == '#' || f_str[len] == '0')
	{
		flag[len] = f_str[len];
		len++;
	}
	flag[len] = '\0';
	plh->flag = flag;
	return (len);
}

int	get_width(char *f_str, t_placehold *plh)
{
	int		len;
	char	*width;
	char	*res;

	len = 0;
	while (pf_isdigit(f_str[len]) || f_str[len] == '*')
		len++;
	if (len == 0)
	{
		plh->width = NULL;
		return (len);
	}
	if (!(width = malloc(sizeof(char) * (len + 1))))
		return (0);
	res = width;
	while (pf_isdigit(*f_str) || *f_str == '*')
		*(width++) = *(f_str++);
	*width = '\0';
	plh->width = res;
	return (len);
}

int	get_precision(char *f_str, t_placehold *plh)
{
	int		len;
	char	*precision;
	char	*res;

	if (f_str[0] != '.')
	{
		plh->precision = NULL;
		return (0);
	}
	len = 1;
	while (pf_isdigit(f_str[len]) || f_str[len] == '*')
		len++;
	if (len == 1)
	{
		plh->precision = pf_calloc(1, 1);
		return (len);
	}
	if (!(precision = malloc(sizeof(char) * (len))))
		return (0);
	res = precision;
	while (pf_isdigit(*(++f_str)) || *f_str == '*')
		*(precision++) = *(f_str);
	*precision = '\0';
	plh->precision = res;
	return (len);
}

int	get_size(const char *f_str, t_placehold *plh)
{
	char	*size;
	char	*res;
	int		len;

	len = 0;
	while (f_str[len] == 'j' || f_str[len] == 'z'
	|| f_str[len] == 'l' || f_str[len] == 'h' ||
	f_str[len] == 't' || f_str[len] == 'L')
		len++;
	if (len == 0)
	{
		plh->size = NULL;
		return (0);
	}
	if (!(size = malloc(sizeof(char) * (len + 1))))
		return (0);
	res = size;
	while (*f_str == 'j' || *f_str == 'z' || *f_str == 'l' || *f_str == 'h' ||
	*f_str == 't' || *f_str == 'L')
		*(size++) = *(f_str++);
	*size = '\0';
	plh->size = res;
	return (len);
}

int	get_type(const char *format_string, t_placehold *plh)
{
	if (format_string[0] != '\0')
	{
		plh->type = format_string[0];
		return (1);
	}
	else
	{
		plh->type = 0;
		return (0);
	}
}
