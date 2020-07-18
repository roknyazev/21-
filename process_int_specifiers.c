/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_specifiers.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/14 18:05:23 by wrudy             #+#    #+#             */
/*   Updated: 2020/07/17 23:46:13 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*nbr_with_pr(unsigned pr, char *n, unsigned len, const char *s_p)
{
	char	*result;

	if (n[0] == '0' && s_p != NULL && s_p[0] != '-')
	{
		result = malloc(sizeof(char) * (pr + 1));
		fill_s_pr0(pr, '0', &result, "");
		return (result);
	}
	if (len >= pr)
		return (pf_strdup(n));
	if (n[0] == '-')
	{
		result = malloc(sizeof(char) * (pr + 2));
		result[0] = '-';
		pr++;
		n++;
		fill_s_pr1(pr, '0', &result, n);
	}
	else
	{
		result = malloc(sizeof(char) * (pr + 1));
		fill_s_pr0(pr, '0', &result, n);
	}
	return (result);
}

static char	*case_with_minus(unsigned width, char *content)
{
	unsigned		len;
	char			*result;
	unsigned		i;

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

static char	*case_without_m(char *s_fl, unsigned wid, const char *s_p, char *c)
{
	unsigned		len;
	char			*result;

	len = pf_strlen(c);
	if (len >= wid)
		return (pf_strdup(c));
	if (s_fl != NULL && pf_strchr(s_fl, '0') && s_p == NULL)
	{
		if (c[0] == '-')
			result = nbr_with_pr(wid - 1, c, len, s_p);
		else
			result = nbr_with_pr(wid, c, len, s_p);
		return (result);
	}
	result = malloc(sizeof(char) * (wid + 1));
	fill_s_m(wid, ' ', &result, c);
	return (result);
}

char		*pr_int_spec(char *s_f, char *s_wi, char *s_p, char *nb)
{
	char		*result;
	char		*content;
	unsigned	len;
	int			precision;
	unsigned	width;

	len = pf_strlen(nb);
	if (s_p == NULL)
		content = pf_strdup(nb);
	else
	{
		if ((precision = pf_atoi(s_p)) < 0)
			precision = 0;
		content = nbr_with_pr(precision, nb, len, s_p);
	}
	if (s_wi == NULL)
		width = 0;
	else
		width = pf_atoi(s_wi);
	if (s_f != NULL && pf_strchr(s_f, '-'))
		result = case_with_minus(width, content);
	else
		result = case_without_m(s_f, width, s_p, content);
	free(content);
	return (result);
}
