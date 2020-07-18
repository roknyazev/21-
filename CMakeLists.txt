cmake_minimum_required(VERSION 3.16)
project(untitled C)

set(CMAKE_C_STANDARD 99)

add_executable(untitled main.c pf_strlen.c ft_printf.h parse.c ft_printf.c get_placeholder.c get_specifiers.c pf_isdigit.c processing.c process_types.c pf_itoa.c pf_xtoa.c pf_utoa.c pf_strdup.c process_int_specifiers.c pf_atoi.c pf_calloc.c pf_bzero.c pf_strchr.c process_int_specifier_support.c process_char_specifiers.c process_str_specifiers.c process_pointer_specifiers.c pf_ptoa.c)