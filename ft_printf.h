/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/07/12 19:06:13 by wrudy             #+#    #+#             */
/*   Updated: 2020/07/17 23:46:13 by wrudy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_FT_PRINTF_H
# define PRINTF_FT_PRINTF_H

# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

typedef struct		s_struct
{
	char			*flag;
	char			*width;
	char			*precision;
	char			*size;
	char			type;
	int				len;
}					t_placehold;

typedef struct		s_list
{
	char			*text;
	t_placehold		*plh;
	int				elem_len;
	struct s_list	*next;
}					t_form_list;

int					ft_printf(char *format, ...);

/*
**					functions for parsing format string
*/

t_form_list			*parse(char *format_string);
t_placehold			*get_placeholder(char *format_string);
int					get_flag(const char *f_str, t_placehold *plh);
int					get_width(char *format_string, t_placehold *plh);
int					get_precision(char *f_str, t_placehold *plh);
int					get_size(const char *format_string, t_placehold *plh);
int					get_type(const char *format_string, t_placehold *plh);

/*
**					functions for processing format list and printing result
*/

int					process(t_form_list *format, va_list *arg);
int					process_int(t_placehold *plh, va_list *arg);
char				*pr_int_spec(char *s_f, char *s_wi, char *s_p, char *nb);
int					process_char(t_placehold *plh, va_list *arg);
int					pr_char_spec(char *s_fl, char *s_wid, unsigned char c);
int					process_string(t_placehold *plh, va_list *arg);
int					pr_str_spec(char *s_fl, char *s_w, char *s_p, char *str);
int					process_pointer(t_placehold *plh, va_list *arg);
int					pr_ptr_spec(char *s_fl, char *s_w, unsigned long long p);

/*
** 					support functions
*/

int					pf_isdigit(int c);
size_t				pf_strlen(const char *str);
char				*pf_strdup(const char *s);
char				*pf_itoa(int n);
char				*pf_utoa(unsigned int n);
char				*pf_xtoa(unsigned long long n, char reg);
char				*pf_ptoa(unsigned long long n);
size_t				pf_atoi(const char *nptr);
void				pf_bzero(void *s, size_t n);
void				*pf_calloc(size_t nmemb, size_t size);
char				*pf_strchr(const char *s, int c);
void				fill_s_pr1(unsigned width, char c, char **str, char *cnt);
void				fill_s_pr0(unsigned width, char c, char **str, char *cnt);
void				fill_s_m(unsigned width, char c, char **str, char *cnt);

#endif
