/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_types.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 22:47:04 by wrudy             #+#    #+#             */
/*   Updated: 2020/07/17 23:46:13 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	process_int(t_placehold *plh, va_list *arg)
{
	int		len;
	char	*nbr_s;
	char	*out;

	if (plh->type == 'd' || plh->type == 'i')
		nbr_s = pf_itoa(va_arg(*arg, int));
	else if (plh->type == 'u')
		nbr_s = pf_utoa(va_arg(*arg, unsigned int));
	else
		nbr_s = pf_xtoa(va_arg(*arg, unsigned int), plh->type);
	out = pr_int_spec(plh->flag, plh->width, plh->precision, nbr_s);
	len = pf_strlen(out);
	write(1, out, len);
	free(nbr_s);
	free(out);
	return (len);
}

int	process_char(t_placehold *plh, va_list *arg)
{
	int				len;
	unsigned char	c;

	c = (unsigned char)va_arg(*arg, int);
	len = pr_char_spec(plh->flag, plh->width, c);
	return (len);
}

int	process_string(t_placehold *plh, va_list *arg)
{
	int		len;
	char	*s;

	s = va_arg(*arg, char *);
	if (s == NULL)
	{
		s = malloc(sizeof(char) * 6);
		s[0] = '(';
		s[1] = 'n';
		s[2] = 'u';
		s[3] = 'l';
		s[4] = 'l';
		s[5] = ')';
	}
	len = pr_str_spec(plh->flag, plh->width, plh->precision, s);
	return (len);
}

int	process_pointer(t_placehold *plh, va_list *arg)
{
	int					len;
	unsigned long long	p;

	p = va_arg(*arg, unsigned long long);
	len = pr_ptr_spec(plh->flag, plh->width, p);
	return (len);
}
