/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/20 21:32:41 by wrudy             #+#    #+#             */
/*   Updated: 2020/10/21 23:03:59 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "scene.h"

int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

static int	get_nmb(const char *str)
{
	size_t number;
	size_t order;
	size_t len;

	order = 1;
	len = 0;
	while (ft_isdigit(str[len]))
		len++;
	number = (int)(*str) - '0';
	while (order < len)
	{
		number = number * 10;
		order++;
	}
	if (order > 1)
		return ((int)(number + get_nmb(str + 1)));
	else
		return (number);
}

int			ft_atoi(const char *nptr)
{
	int sign;

	while (*nptr == ' ' || *nptr == '\v' || *nptr == '\r' \
		|| *nptr == '\t' || *nptr == '\n' || *nptr == '\f')
		nptr++;
	if (*nptr == '-')
		sign = -1;
	else
		sign = 1;
	if (*nptr == '-' || *nptr == '+')
		nptr++;
	if (ft_isdigit(*nptr))
		return (get_nmb(nptr) * sign);
	else
		exit(1);
}

int 		ft_atof(const char *nptr, double *nmb)
{
	double n;
	double after_dot;
	double divider;
	int i;

	i = 0;
	divider = 1;
	n = (float)ft_atoi(nptr);
	while (ft_isdigit(nptr[i]) || nptr[i] == '-')
		i++;
	if (nptr[i] != '.' || !ft_isdigit(nptr[i + 1]))
	{
		*nmb = n;
		return i;
	}
	i++;
	after_dot = ft_atoi(&nptr[i]);
	while (ft_isdigit(nptr[i]))
	{
		divider = divider * 10;
		i++;
	}
	if (nptr[0] == '-')
		*nmb = n - (after_dot / divider);
	else
		*nmb = n + (after_dot / divider);
	return (i);
}

int parse_pos(const char *line, t_vector *pos)
{
	int i;
	double *nmb;

	nmb = malloc(sizeof(double));
	i = ft_atof(line, nmb);
	pos->x = *nmb;
	if (line[i] != ',' || !(ft_isdigit(line[i + 1]) || line[i + 1] == '-'))
		exit(1);
	i = i + ft_atof(&line[i + 1], nmb) + 1;
	pos->y = *nmb;
	if (line[i] != ',' || !(ft_isdigit(line[i + 1]) || line[i + 1] == '-'))
		exit(1);
	i = i + ft_atof(&line[i + 1], nmb) + 1;
	pos->z = *nmb;
	if (line[i] != ' ' && line[i] != '\t' && line[i] != '\0')
		exit(1);
	free(nmb);
	return (i);
}

int parse_orient(const char *line, t_vector *orient)
{
	int i;

	i = parse_pos(line, orient);
	if (orient->x > 1.0 || orient->x < -1.0)
		exit(0);
	if (orient->y > 1.0 || orient->y < -1.0)
		exit(0);
	if (orient->z > 1.0 || orient->z < -1.0)
		exit(0);
	return (i);
}

int parse_color(const char *line, t_color *color)
{
	int i;
	int nmb;

	i = 0;
	nmb = ft_atoi(line);
	color->rgb_color->x = (double)nmb;
	while (ft_isdigit(line[i]))
		i++;
	if (line[i++] != ',' || !ft_isdigit(line[i]))
		exit(1);
	nmb = ft_atoi(&line[i]);
	color->rgb_color->y = (double)nmb;
	while (ft_isdigit(line[i]))
		i++;
	if (line[i++] != ',' || !ft_isdigit(line[i]))
		exit(1);
	nmb = ft_atoi(&line[i]);
	color->rgb_color->z = (double)nmb;
	while (ft_isdigit(line[i]))
		i++;
	if (line[i] == ' ' || line[i] == '\t' || line[i] == '\0')
		return (i);
	exit(1);
}