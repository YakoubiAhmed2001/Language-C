# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ayakoubi <ayakoubi@student.1337.ma>        +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/22 11:42:28 by ayakoubi          #+#    #+#              #
#    Updated: 2022/11/23 16:30:02 by ayakoubi         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME	= so_long.a
SRC		= $(wildcard *.c)
OBJ		= $(SRC:.c=.o)

all: $(NAME)

%.o: %.c
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

$(NAME): $(OBJ)
	$(CC) $(OBJ) -lmlx -framework OpenGL -framework AppKit -o $(NAME)

clean:	
	rm -f *.o

fclean:	clean
	rm -f *.a

re:	fclean all

.PHONY: all clean fclean re
