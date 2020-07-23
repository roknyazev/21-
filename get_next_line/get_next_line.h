/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/20 17:10:49 by wrudy             #+#    #+#             */
/*   Updated: 2020/07/20 21:23:26 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_GNL1_H
#define GET_NEXT_LINE_GNL1_H

#include "unistd.h"
#include "stdlib.h"

void	gnl_bzero(void *s, size_t n);
void	*gnl_calloc(size_t nmemb, size_t size);
size_t	gnl_strlen(const char *str);
int get_next_line(int fd, char **line, int BUFFER_SIZE);
char	*gnl_strchr(const char *s, int c);
char		*gnl_strjoin(char const *s1, char const *s2);

#endif
