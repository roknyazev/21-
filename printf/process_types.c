/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_types.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 22:47:04 by wrudy             #+#    #+#             */
/*   Updated: 2020/07/16 18:53:55 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int process_int(placeholder *plh, va_list *arg)
{
	int		len;
	char	*nbr_str;
	char	*out;

	if (plh->type == 'd' || plh -> type == 'i')
		nbr_str = ft_itoa(va_arg(*arg, int));
	else if (plh->type == 'u')
		nbr_str = ft_utoa(va_arg(*arg, unsigned int));
	else
		nbr_str = ft_xtoa(va_arg(*arg, unsigned  int), plh->type);
	out = process_int_specifiers(plh->flag, plh->width, plh->precision, nbr_str);
	len = ft_strlen(out);
	write(1, out, len);

	free(nbr_str);
	free(out);
	return (len);
}

int process_char(placeholder *plh, va_list *arg)
{
	int				len;
	unsigned char	c;

	c = (unsigned char)va_arg(*arg, int);
	len = process_char_specifiers(plh->flag, plh->width, c);
	return (len);
}

int process_string(placeholder *plh, va_list *arg)
{
	int		len;
	char	*s;

	s = va_arg(*arg, char *);
	len = process_str_specifiers(plh->flag, plh->width, plh->precision, s);
	//free(s);
	return (len);
}

int process_pointer(placeholder *plh, va_list *arg)
{
	int					len;
	unsigned long long	p;

	p = va_arg(*arg, unsigned long long);
	len = process_ptr_specifiers(plh->flag, plh->width, p);
	return (len);
}