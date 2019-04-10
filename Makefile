# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mqian <mqian@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/09 18:00:11 by mqian             #+#    #+#              #
#    Updated: 2019/04/09 19:27:39 by mqian            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fillit

CC = gcc

FLAGS = -Wall -Wextra -Werror -o

SRC_PATH = ./srcs/
SFILES = fillit.c solve.c parse.c map.c parse_helpers.c
SRC = $(addprefix $(SRC_PATH), $(SFILES))

OFILES = $(SRC:.c=.o)

INCLUDES = -Iincludes/

LINCLUDES = -Ilibft/includes/libft.h

.PHONY: $(NAME) all clean fclean re

all: $(NAME)

$(NAME):
	$(CC) $(FLAGS) $(NAME) $(SRC) libft.a $(INCLUDES) $(LINCLUDES)

clean:
	rm -f $(OFILES)

fclean: clean
	rm -f $(NAME)

re: fclean all
