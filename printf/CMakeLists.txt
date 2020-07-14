cmake_minimum_required(VERSION 3.16)
project(printf C)

set(CMAKE_C_STANDARD 99)

add_executable(printf main.c ft_strlen.c ft_printf.h parse.c ft_printf.c get_placeholder.c get_specifiers.c ft_isdigit.c processing.c process_types.c ft_itoa.c ft_xtoa.c ft_utoa.c ft_strdup.c process_specifiers.c ft_atoi.c ft_calloc.c ft_bzero.c ft_strchr.c)