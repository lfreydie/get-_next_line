# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lfreydie <lfreydie@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 13:51:27 by lefreydier        #+#    #+#              #
#    Updated: 2023/01/17 10:18:48 by lfreydie         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = get_next_line

CFLAGS = -Wall -Wextra -Werror

INCLUDE = get_next_line.h

SRC = get_next_line.c	get_next_line_utils.c	main.c

OBJ = $(SRC:.c=.o)

$(NAME): $(OBJ) $(INCLUDE)
	$(CC) -o $(NAME) $(OBJ)

all:	$(NAME)

clean:
			$(RM) $(OBJECTS)

fclean: clean
			$(RM) $(NAME)

re:			fclean all

.PHONY: all clean fclean re
