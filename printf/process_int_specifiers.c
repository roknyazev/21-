/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_specifiers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 18:05:23 by wrudy             #+#    #+#             */
/*   Updated: 2020/07/15 22:29:15 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*nbr_with_precision(int precision, char *nbr, int len)
{
	char	*result;

	if (len >= precision)
		return (ft_strdup(nbr));
	if (nbr[0] == '-')
	{
		result = malloc(sizeof(char) * (precision + 2));
		result[0] = '-';
		precision++;
		nbr++;
		fill_str_with_precision_1(precision, '0', &result, nbr);
	}
	else
	{
		result = malloc(sizeof(char) * (precision + 1));
		fill_str_with_precision_0(precision, '0', &result, nbr);
	}
	return (result);
}

static char	*case_with_minus(int width, char *content)
{
	int		len;
	char	*result;
	int		i;

	i = 0;
	len = ft_strlen(content);
	if (len >= width)
		return (ft_strdup(content));
	result = malloc(sizeof(char) * (width + 1));
	while (i < width)
	{
		if (i < len)
			result[i] = content[i];
		else
			result[i] = ' ';
		i++;
	}
	result[i] = '\0';
	return (result);
}

static char	*case_without_minus(char *s_fl, int wid, const char *s_pr, char *cnt)
{
	int		len;
	char	*result;

	len = ft_strlen(cnt);
	if (len >= wid)
		return (ft_strdup(cnt));
	result = malloc(sizeof(char) * (wid + 1));
	if (s_fl != NULL && ft_strchr(s_fl, '0') && s_pr == NULL)
	{
		if (cnt[0] == '-')
			result = nbr_with_precision(wid - 1, cnt, len);
		else
			result = nbr_with_precision(wid, cnt, len);
		return (result);
	}
	fill_str_without_minus(wid, ' ', &result, cnt);
	return (result);
}

char	*process_int_specifiers(char *s_fl, char *s_wid, char *s_pr, char *nbr)
{
	char	*result;
	char	*content;
	int		len;
	int		precision;
	int		width;

	len = ft_strlen(nbr);
	if (s_pr == NULL)
		content = ft_strdup(nbr);
	else
	{
		precision = ft_atoi(s_pr);
		content = nbr_with_precision(precision, nbr, len);
	}
	if (s_wid == NULL)
		width = 0;
	else
		width = ft_atoi(s_wid);
	if (s_fl != NULL && ft_strchr(s_fl, '-'))
		result = case_with_minus(width, content);
	else
		result = case_without_minus(s_fl, width, s_pr, content);
	free(content);
	return (result);
}
