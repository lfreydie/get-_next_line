# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lefreydier <lefreydier@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/01/13 13:51:27 by lefreydier        #+#    #+#              #
#    Updated: 2023/01/13 14:02:58 by lefreydier       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CC = gcc

NAME = get_next_line

CFLAGS = -Wall -Wextra -Werror

INCLUDE = get_next_line.h

SRC = get_next_line.c	get_next_line_utils.c

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
