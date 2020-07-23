/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 17:11:29 by wrudy             #+#    #+#             */
/*   Updated: 2020/07/23 15:05:50 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int get_next_line(int fd, char **line, int BUFFER_SIZE)
{
	static char		*surplus;
	char 			*tmp;
	char 			*str;
	int 			tmp_len;

	if (BUFFER_SIZE < 1)
		return (-1);
	if (surplus == NULL)
		str = gnl_calloc(1, sizeof(char));
	else
	{
		tmp = surplus;
		if ((surplus = gnl_strchr(tmp, '\n')))
		{
			surplus[0] = '\0';
			surplus = gnl_strjoin("", surplus + 1);
			str = gnl_strjoin("", tmp);
			*line = str;
			return (1);
		}
		else
		{
			str = gnl_strjoin("", tmp);
			*line = str;
		}
	}
	while (surplus == NULL || (surplus != NULL && !gnl_strchr(surplus, '\n')))
	{
		tmp = gnl_calloc(BUFFER_SIZE + 1, sizeof(char));
		tmp_len = read(fd, tmp, BUFFER_SIZE);
		if (tmp_len < 1)
			return (tmp_len);
		if ((surplus = gnl_strchr(tmp, '\n')))
		{
			surplus[0] = '\0';
			surplus = gnl_strjoin("", surplus + 1);
			str = gnl_strjoin(str, tmp);
			break;
		}
		str = gnl_strjoin(str, tmp);
		*line = str;
	}
	*line = str;
	return (1);
}