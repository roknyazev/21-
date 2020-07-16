/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_specifiers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 18:05:23 by wrudy             #+#    #+#             */
/*   Updated: 2020/07/16 21:21:05 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*nbr_with_precision(int precision, char *nbr, int len)
{
	char	*result;

	if (len >= precision)
		return (pf_strdup(nbr));
	if (nbr[0] == '-')
	{
		result = malloc(sizeof(char) * (precision + 2));
		result[0] = '-';
		precision++;
		nbr++;
		fill_s_with_pr1(precision, '0', &result, nbr);
	}
	else
	{
		result = malloc(sizeof(char) * (precision + 1));
		fill_s_with_pr0(precision, '0', &result, nbr);
	}
	return (result);
}

static char	*case_with_minus(int width, char *content)
{
	int		len;
	char	*result;
	int		i;

	i = 0;
	len = pf_strlen(content);
	if (len >= width)
		return (pf_strdup(content));
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

static char	*case_without_minus(char *s_fl, int wid, const char *s_p, char *cn)
{
	int		len;
	char	*result;

	len = pf_strlen(cn);
	if (len >= wid)
		return (pf_strdup(cn));
	result = malloc(sizeof(char) * (wid + 1));
	if (s_fl != NULL && pf_strchr(s_fl, '0') && s_p == NULL)
	{
		if (cn[0] == '-')
			result = nbr_with_precision(wid - 1, cn, len);
		else
			result = nbr_with_precision(wid, cn, len);
		return (result);
	}
	fill_s_without_m(wid, ' ', &result, cn);
	return (result);
}

char		*pr_int_spec(char *s_f, char *s_wi, char *s_p, char *nb)
{
	char	*result;
	char	*content;
	int		len;
	int		precision;
	int		width;

	len = pf_strlen(nb);
	if (s_p == NULL)
		content = pf_strdup(nb);
	else
	{
		precision = pf_atoi(s_p);
		content = nbr_with_precision(precision, nb, len);
	}
	if (s_wi == NULL)
		width = 0;
	else
		width = pf_atoi(s_wi);
	if (s_f != NULL && pf_strchr(s_f, '-'))
		result = case_with_minus(width, content);
	else
		result = case_without_minus(s_f, width, s_p, content);
	free(content);
	return (result);
}
