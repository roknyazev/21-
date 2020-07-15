/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 19:06:13 by wrudy             #+#    #+#             */
/*   Updated: 2020/07/14 18:43:34 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_FT_PRINTF_H
# define PRINTF_FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct		p_struct
{
	char			*flag;
	char			*width;
	char			*precision;
	char			*size;
	char			type;
	int				len;
}					placeholder;

typedef struct		f_list
{
	char			*text;
	placeholder		*plh;
	int				elem_len;
	struct f_list	*next;
}					format_list;

int					ft_printf(char *format, ...);
/*
 *					functions for parsing format string
 */
format_list			*parse(char *format_string);
placeholder			*get_placeholder(char *format_string);
int					get_flag(const char *f_str, placeholder *plh);
int					get_width(char *format_string, placeholder *plh);
int					get_precision(char *f_str, placeholder *plh);
int					get_size(const char *format_string, placeholder *plh);
int					get_type(const char *format_string, placeholder *plh);
/*
 *					functions for processing format list and printing result
 */
int					process(format_list *format, va_list *arg);
int					process_int(placeholder *plh, va_list *arg);
char				*process_int_specifiers(char *s_fl, char *s_wid, char *s_pr, char *nbr);
int					process_float(placeholder *plh, va_list *arg);
int					process_char(placeholder *plh, va_list *arg);
int					process_string(placeholder *plh, va_list *arg);
int					process_pointer(placeholder *plh, va_list *arg);
/*
 * 					assist functions
 */
int					ft_isdigit(int c);
int					ft_isalpha(int c);
size_t				ft_strlen(const char *str);
char				*ft_strdup(const char *s);
char				*ft_itoa(int n);
char				*ft_utoa(unsigned int n);
char				*ft_xtoa(unsigned long long n, char reg);
int 				ft_atoi(const char *nptr);
void				ft_bzero(void *s, size_t n);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strchr(const char *s, int c);

#endif
