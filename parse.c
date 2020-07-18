/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 19:59:50 by wrudy             #+#    #+#             */
/*   Updated: 2020/07/17 23:46:13 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static	t_form_list	*fmt_lst_last(t_form_list *fmt)
{
	if (!fmt)
		return (fmt);
	while (fmt->next)
		fmt = fmt->next;
	return (fmt);
}

static	void		fmt_lst_add_back(t_form_list **fmt, t_form_list *new_elem)
{
	t_form_list	*last;

	if (*fmt)
	{
		last = fmt_lst_last(*fmt);
		last->next = new_elem;
	}
	else
		*fmt = new_elem;
}

static	t_form_list	*new_text_elem(const char *format_string)
{
	char		*text;
	t_form_list	*new_elem;
	int			i;

	i = 0;
	while (format_string[i] != '%' && format_string[i] != '\0')
		i++;
	if (!(text = malloc(sizeof(char) * (i + 1))))
		return (NULL);
	if (!(new_elem = malloc(sizeof(t_form_list))))
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

static	t_form_list	*new_plh_elem(char *format_string)
{
	t_form_list *new_elem;

	if (!(new_elem = malloc(sizeof(t_form_list))))
		return (NULL);
	new_elem->next = NULL;
	new_elem->text = NULL;
	new_elem->plh = get_placeholder(format_string);
	new_elem->elem_len = new_elem->plh->len;
	return (new_elem);
}

t_form_list			*parse(char *format_string)
{
	t_form_list	*fmt;
	t_form_list	*new_elem;

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
