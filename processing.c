/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   processing.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/13 21:35:08 by wrudy             #+#    #+#             */
/*   Updated: 2020/07/17 23:46:13 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_arg(t_placehold *plh, va_list *arg)
{
	int count;

	count = 0;
	if (plh->type == 'd' || plh->type == 'i' || plh->type == 'u' ||
	plh->type == 'x' || plh->type == 'X')
		count = count + process_int(plh, arg);
	else if (plh->type == 'c')
		count = count + process_char(plh, arg);
	else if (plh->type == '%')
		count = count + pr_char_spec(plh->flag, plh->width, '%');
	else if (plh->type == 's')
		count = count + process_string(plh, arg);
	else
		count = count + process_pointer(plh, arg);
	return (count);
}

static void	case_with_neg_width(t_placehold *plh)
{
	char	*new_flag_str;
	int		old_len;
	int		i;

	if (plh->flag != NULL && pf_strchr(plh->flag, '-'))
		return ;
	else if (plh->flag == NULL)
	{
		new_flag_str = malloc(sizeof(char) * 2);
		new_flag_str[0] = '-';
		new_flag_str[1] = '\0';
		plh->flag = new_flag_str;
	}
	else
	{
		i = 0;
		old_len = pf_strlen(plh->flag);
		new_flag_str = malloc(sizeof(char) * (old_len + 2));
		while (i++ < (old_len))
			new_flag_str[i - 1] = plh->flag[i - 1];
		new_flag_str[i - 1] = '-';
		new_flag_str[i + 1] = '\0';
		free(plh->flag);
		plh->flag = new_flag_str;
	}
}

static int	process_plh_elem(t_placehold *plh, va_list *arg)
{
	int				width;
	int				precision;

	if (plh->type == 0)
		return (0);
	if (plh->width != NULL && plh->width[0] == '*')
	{
		free(plh->width);
		width = va_arg(*arg, int);
		if (width < 0)
		{
			width = 0 - width;
			case_with_neg_width(plh);
		}
		plh->width = pf_itoa(width);
	}
	if (plh->precision != NULL && plh->precision[0] == '*')
	{
		free(plh->precision);
		precision = va_arg(*arg, int);
		plh->precision = pf_itoa(precision);
	}
	return (print_arg(plh, arg));
}

static void	format_list_free(t_form_list *fmt)
{
	t_form_list *tmp;

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

int			process(t_form_list *format, va_list *arg)
{
	t_form_list	*fmt;
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
