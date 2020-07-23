/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/23 15:03:28 by wrudy             #+#    #+#             */
/*   Updated: 2020/07/23 18:52:08 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static int	process_surplus(char **out, char **surplus)
{
	char *tmp;

	if ((tmp = gnl_strjoin("", *surplus)))
	{
		free(surplus);
		if ((*surplus = gnl_strchr(tmp, '\n')))
		{
			*surplus[0] = '\0';
			*surplus = gnl_strjoin("", *(surplus + 1));
			*out = gnl_strjoin("", tmp);
		}
		else
			*out = gnl_strjoin("", tmp);
		if (!*surplus || !*out)
			return (-1);
		free(tmp);
	}
	else
	{
		if (surplus != NULL)
			return (-1);
		*out = gnl_calloc(1, sizeof(char));
	}
}

static int	reading(int fd, char *out, int BUFFER_SIZE, char *s)
{

}

int			get_next_line(int fd, char **line, int BUFFER_SIZE)
{
	static char 	*surplus;
	char 			*tmp;
	char 			*out;
	int 			flag;

	if (BUFFER_SIZE < 1)
		return (-1);
	if ((tmp = gnl_strjoin("", surplus)))
	{
		free(surplus);
		if ((surplus = gnl_strchr(tmp, '\n')))
		{
			surplus[0] = '\0';
			surplus = gnl_strjoin("", surplus + 1);
			out = gnl_strjoin("", tmp);
		}
		else
			out = gnl_strjoin("", tmp);
		if (!surplus || !out)
			return (-1);
		free(tmp);
	}
	else
	{
		if (surplus != NULL)
			return (-1);
		out = gnl_calloc(1, sizeof(char));
	}
	flag = 1;
	if (surplus == NULL || (surplus != NULL && !gnl_strchr(surplus, '\n')))
		flag = reading(fd, out, BUFFER_SIZE, surplus);
	if (!out)
		return (-1);
	*line = out;
	return (flag);
}