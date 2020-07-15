/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_str_flags.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/15 23:44:28 by wrudy             #+#    #+#             */
/*   Updated: 2020/07/15 23:54:23 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*process_str_specifiers(char *s_fl, char *s_wid, char *s_pr, char *nbr)
{
	int		width;
	int		max_symbols;
	char	*str;

	if (s_wid != NULL)
		width = ft_atoi(s_wid);
	else
		width = 0;
	if (s_pr != NULL)
		max_symbols = ft_atoi(s_pr);
	else
		max_symbols = -1;
	if (ft_strchr(s_fl, '-'))
		str = case_with_minus();
	else
		str = case_without_minus();
	return (str);
}