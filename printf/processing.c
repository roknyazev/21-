/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 21:35:08 by wrudy             #+#    #+#             */
/*   Updated: 2020/07/13 22:19:41 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_arg(placeholder *plh, va_list *arg)
{
	int count;

	count = 0;
	if (plh->type == 'd' || plh->type == 'i' || plh->type == 'u' ||
	plh->type == 'x' || plh->type == 'X')
		process_int(plh, arg);
	else if (plh->type == 'c')
		process_char(plh, arg);
	else if (plh->type == 's')
		process_string(plh, arg);
	else
		process_pointer(plh, arg);
	return (count);
}

static int	process_plh_elem(placeholder *plh, va_list *arg)
{
	if (plh->type == '%')
	{
		write(1, &plh->type, 1);
		return (1);
	}
	if (plh->type == 0)
		return (0);
	if (plh->width != NULL && plh->width[0] == '*')
	{
		free(plh->width);
		plh->width = ft_itoa(va_arg(*arg, int));
	}
	if (plh->precision != NULL && plh->precision[0] == '*')
	{
		free(plh->precision);
		plh->precision = ft_itoa(va_arg(*arg, int));
	}
	return (print_arg(plh, arg));
}

static void	format_list_free(format_list *fmt)
{
	format_list *tmp;

	while (fmt)
	{
		if (fmt->plh == NULL)
			free(fmt->text);
		else
		{
			free(fmt->plh->flag);
			free(fmt->plh->width);
			free(fmt->plh->precision);
			free(fmt->plh->size);
			free(fmt->plh);
		}
		tmp = fmt;
		fmt = fmt->next;
		free(tmp);
	}
}

int			process(format_list *format, va_list *arg)
{
	format_list	*fmt;
	int			count;

	fmt = format;
	count = 0;
	while (format)
	{
		if (format->plh == NULL)
		{
			count = count + format->elem_len;
			write(1, format->text, format->elem_len);
		}
		else
			count = count + process_plh_elem(format->plh, arg);
		format = format->next;
	}
	format_list_free(fmt);
	return (count);
}
