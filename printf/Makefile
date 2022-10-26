# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/10/18 17:34:53 by ayakoubi          #+#    #+#              #
#    Updated: 2022/10/19 13:55:54 by ayakoubi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	=	libftprintf.a
SRC		=	ft_printf.c \
			ft_putchar.c \
			ft_putnbr.c \
			ft_putstr.c \
			ft_putuns.c \
			ft_puthex.c

OBJ		=	$(SRC:.c=.o)

CC		=	gcc

CFLAGS	=	-Wall -Wextra -Werror

all	:	$(NAME)

$(NAME)	:	$(OBJ)
	$(CC) $(CFLAGS) -c $(SRC)
	ar -r $@ $^

clean	:
	rm -f *.o

fclean	:	clean
	rm -f *.a

re : fclean all

.PHONY : all clean fclean re

