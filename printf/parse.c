/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 19:59:50 by wrudy             #+#    #+#             */
/*   Updated: 2020/07/12 20:28:54 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	format_list	*fmt_lst_last(format_list *fmt)
{
	if (!fmt)
		return (fmt);
	while (fmt->next)
		fmt = fmt->next;
	return (fmt);
}

static	void		fmt_lst_add_back(format_list **fmt, format_list *new_elem)
{
	format_list	*last;

	if (*fmt)
	{
		last = fmt_lst_last(*fmt);
		last->next = new_elem;
	}
	else
		*fmt = new_elem;
}

static	format_list	*new_text_elem(const char *format_string)
{
	char		*text;
	format_list	*new_elem;
	int			i;

	i = 0;
	while (format_string[i] != '%' && format_string[i] != '\0')
		i++;
	if (!(text = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	if (!(new_elem = malloc(sizeof(format_list))))
		return (NULL);
	new_elem->next = NULL;
	new_elem->plh = NULL;
	new_elem->elem_len = i;
	i = 0;
	while (format_string[i] != '%' && format_string[i] != '\0')
	{
		text[i] = format_string[i];
		i++;
	}
	text[i] = '\0';
	new_elem->text = text;
	return (new_elem);
}

static	format_list	*new_plh_elem(char *format_string)
{
	format_list *new_elem;

	if (!(new_elem = malloc(sizeof(format_list))))
		return (NULL);
	new_elem->next = NULL;
	new_elem->text = NULL;
	new_elem->plh = get_placeholder(format_string);
	new_elem->elem_len = new_elem->plh->len;
	return (new_elem);
}

format_list			*parse(char *format_string)
{
	format_list	*fmt;
	format_list	*new_elem;

	fmt = NULL;
	while (*format_string != '\0')
	{
		if (*format_string != '%')
		{
			new_elem = new_text_elem(format_string);
			fmt_lst_add_back(&fmt, new_elem);
			format_string = format_string + new_elem->elem_len;
		}
		else
		{
			new_elem = new_plh_elem(format_string);
			fmt_lst_add_back(&fmt, new_elem);
			format_string = format_string + new_elem->elem_len;
		}
	}
	return (fmt);
}
