# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: yel-mard <yel-mard@student.s19.be>         +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/01 12:15:54 by yel-mard          #+#    #+#              #
#    Updated: 2023/01/03 14:11:42 by yel-mard         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a
CC = gcc
FLAGS = -Wall -Wextra -Werror
RM = rm -f
LIBC = ar rcs
SRCS = ft_printf.c \
	   ft_print_ptr.c ft_print_hex.c \
       ft_print_chars.c ft_print_unsigned.c ft_print_nbr.c
OBJS = $(addprefix srcs/, $(SRCS:.c=.o))

.c.o:
			$(CC) $(FLAGS) -c -I./include $< -o $(<:.c=.o)

all:	    $(NAME)

$(NAME):	$(OBJS)
			$(LIBC) $(NAME) $(OBJS)

clean:
			$(RM) $(OBJS)


fclean: clean
			$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re
