/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_types.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 22:47:04 by wrudy             #+#    #+#             */
/*   Updated: 2020/07/13 23:11:58 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int process_int(placeholder *plh, va_list *arg)
{
	int		len;
	char	*nmb_str;
	char	*out;

	if (plh->type == 'd' || plh -> type == 'i')
		nmb_str = ft_itoa(va_arg(*arg, int));
	else if (plh->type == 'u')
		nmb_str = ft_utoa(va_arg(*arg, unsigned int));
	else
		nmb_str = ft_xtoa(va_arg(*arg, unsigned  int), plh->type);
	out = nmb_str;
	//out = process_flags(plh->flag, plh->width, plh->precision, nmb_str);
	len = ft_strlen(out);
	write(1, out, len);

	free(nmb_str);
	//free(out);
	return (len);
}

int process_float(placeholder *plh, va_list *arg)
{
	int i;

	i = 0;
	return (i);
}

int process_char(placeholder *plh, va_list *arg)
{
	int				len;
	unsigned char	c;
	char			*out;

	c = (unsigned char)va_arg(*arg, int);
	//out = process_flags(plh->flag, plh->width, plh->precision, &c);
	len = ft_strlen(out);
	write(1, out, len);

	free(out);
	return (len);
}

int process_string(placeholder *plh, va_list *arg)
{
	int		len;
	char	*s;
	char	*out;

	s = va_arg(*arg, char *);
	//out = process_flags(plh->flag, plh->width, plh->precision, s);
	len = ft_strlen(out);
	write(1, out, len);

	free(s);
	free(out);
	return (len);
}

int process_pointer(placeholder *plh, va_list *arg)
{
	int				len;
	unsigned int	p;
	char			*out;

	p = va_arg(*arg, unsigned int);
	out = ft_xtoa(p, 'x');
	//out = process_flags(plh->flag, plh->width, plh->precision, p);
	len = ft_strlen(out);
	write(1, out, len);

	//free(out);
	return (len);
}