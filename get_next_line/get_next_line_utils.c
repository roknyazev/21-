/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 18:11:40 by wrudy             #+#    #+#             */
/*   Updated: 2020/07/23 15:03:25 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	gnl_bzero(void *s, size_t n)
{
	size_t			i;
	unsigned char	*p;

	i = 0;
	p = (unsigned char *)s;
	while (i < n)
	{
		p[i] = '\0';
		i++;
	}
}

void	*gnl_calloc(size_t nmemb, size_t size)
{
	char	*s;

	if ((s = malloc(nmemb * size)) == NULL)
		return (NULL);
	gnl_bzero(s, nmemb * size);
	return (s);
}

size_t	gnl_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*gnl_strchr(const char *s, int c)
{
	size_t i;

	i = 0;
	if (c == '\0')
		return ((char *)(s + gnl_strlen(s)));
	while (s[i] != '\0')
	{
		if (s[i] == c)
			return ((char *)(s + i));
		i++;
	}
	return (NULL);
}

static char	*gnl_strcpy(char *dest, const char *src)
{
	size_t i;

	i = 0;
	while (*(src + i) != '\0')
	{
		*(dest + i) = *(src + i);
		i++;
	}
	*(dest + i) = '\0';
	return (dest);
}

char		*gnl_strjoin(char const *s1, char const *s2)
{
	char	*res;
	size_t	len_s1;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	len_s1 = gnl_strlen(s1);
	if ((res = malloc((len_s1 + gnl_strlen(s2) + 1) * sizeof(char))) == NULL)
		return (NULL);
	gnl_strcpy(res, s1);
	gnl_strcpy(res + len_s1, s2);
	return (res);
}