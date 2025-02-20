# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: slimane <slimane@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2025/01/22 13:13:41 by slimane           #+#    #+#              #
#    Updated: 2025/02/17 02:30:23 by slimane          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = cc 
CFLAGS= -Wall -Wextra -Werror 

CFILES = lib/ft_isalpha.c lib/ft_isdigit.c lib/ft_isalnum.c lib/ft_isascii.c \
	   lib/ft_isprint.c lib/ft_strlen.c lib/ft_memset.c lib/ft_bzero.c \
	   lib/ft_memcpy.c lib/ft_memmove.c lib/ft_strlcpy.c lib/ft_strlcat.c \
	   lib/ft_calloc.c lib/ft_strdup.c lib/ft_toupper.c lib/ft_tolower.c \
	   lib/ft_strchr.c lib/ft_strncmp.c lib/ft_memchr.c lib/ft_memcmp.c \
	   lib/ft_strnstr.c lib/ft_atoi.c lib/ft_strrchr.c lib/ft_substr.c \
	   lib/ft_strjoin.c lib/ft_strtrim.c lib/ft_split.c lib/ft_itoa.c \
	   lib/ft_strmapi.c lib/ft_striteri.c lib/ft_putchar_fd.c \
	   lib/ft_putstr_fd.c lib/ft_putendl_fd.c lib/ft_putnbr_fd.c 

SRC= Mandatory/src/creating.c Mandatory/src/indexing.c Mandatory/src/options.c Mandatory/src/push_swap.c\
	Mandatory/sort/big_sort.c Mandatory/sort/sort_five.c Mandatory/sort/sort_four.c Mandatory/sort/sort_three.c\
	Mandatory/ERROR/check_arg.c Mandatory/ERROR/get_arg.c Mandatory/ERROR/ft_len.c Mandatory/src/is_sorting.c Mandatory/src/ft_lstsize.c 

BSRC = bonus/ERROR_bonus/check_arg_bonus.c bonus/ERROR_bonus/ft_len_bonus.c bonus/ERROR_bonus/get_arg_bonus.c bonus/src_bonus/checker_bonus.c bonus/src_bonus/creating_ins_bonus.c\
	   bonus/src_bonus/creating_bonus.c  bonus/src_bonus/do_checker_bonus.c bonus/src_bonus/indexing_bonus.c bonus/src_bonus/is_sorting_bonus.c bonus/src_bonus/options_bonus.c bonus/src_bonus/ft_lstsize_bonus.c

OBJ=${SRC:.c=.o}
BOBJ=${BSRC:.c=.o}

NAME = push_swap
NAME_BONUS = checker

all: ${NAME}

${NAME}: ${OBJ} Mandatory/src/push_swap.h Mandatory/ERROR/error.h Mandatory/sort/sort.h ${CFILES}
	make all -C lib
	${CC} ${CFLAGS} ${OBJ} lib/libft.a -o ${NAME}
	
%bonus.o:%bonus.c  bonus/src_bonus/checker_bonus.h bonus/ERROR_bonus/error_bonus.h lib/libft.h
	${CC} ${CFLAGS} -c $< -o $@

%.o:%.c Mandatory/src/push_swap.h Mandatory/ERROR/error.h Mandatory/sort/sort.h  lib/libft.h 
	${CC} ${CFLAGS} -c $< -o $@


bonus:${NAME_BONUS} 

${NAME_BONUS}: bonus/src_bonus/checker_bonus.h bonus/ERROR_bonus/error_bonus.h ${BOBJ} ${CFILES}
	make all -C lib
	${CC} ${CFLAGS} ${BOBJ} lib/libft.a -o ${NAME_BONUS} 


clean:
	make clean -C lib
	rm -rf ${OBJ} ${BOBJ}

fclean:clean
	make fclean -C lib
	rm -rf ${NAME} ${NAME_BONUS}

re:fclean all