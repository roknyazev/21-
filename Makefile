# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wrudy <wrudy@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2020/07/16 22:43:16 by wrudy             #+#    #+#              #
#    Updated: 2020/07/17 23:46:13 by wrudy            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIB = ar rcs

SRC = ft_printf.c\
get_placeholder.c\
get_specifiers.c\
parse.c\
pf_atoi.c\
pf_bzero.c\
pf_calloc.c\
pf_isdigit.c\
pf_itoa.c\
pf_ptoa.c\
pf_strchr.c\
pf_strdup.c\
pf_strlen.c\
pf_utoa.c\
pf_xtoa.c\
process_char_specifiers.c\
process_int_specifier_support.c\
process_int_specifiers.c\
process_pointer_specifiers.c\
process_str_specifiers.c\
process_types.c\
processing.c\

OBJ	=	$(SRC:.c=.o)

HEADER		=	ft_printf.h

CC			=	gcc

CWFLAGS		=	-Wall -Wextra -Werror

COFLAG		=	-c

CNAMEFLAG	=	-o

all			:	$(NAME)

$(NAME)		:	$(OBJ) $(HEADER)
				$(LIB) $(NAME) $?

%.o			:	%.c
				$(CC) $(CWFLAGS) $(COFLAG) $< $(CNAMEFLAG) $@

clean		:
				rm -f $(OBJ)

fclean		:	clean
				rm -f $(NAME)

re			:	fclean all