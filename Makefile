# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mqian <mqian@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/04/09 18:00:11 by mqian             #+#    #+#              #
#    Updated: 2019/04/16 17:26:15 by mqian            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# NAME = fillit
#
# CC = gcc
# FLAGS =  -g -static -c -Wall -Wextra -Werror -o
#
# SRC_PATH = ./srcs/
#
# SFILES = fillit.c solve.c parse.c map.c parse_helpers.c
# SRC = $(addprefix $(SRC_PATH), $(SFILES))
#
# OFILES = $(SRC:.c=.o)
#
# INCLUDES = -Iincludes/
#
# LINCLUDES = -Ilibft/includes/libft.h
#
# .PHONY: $(NAME) all clean fclean re
#
# all: $(NAME)
#
# $(NAME):
# 	$(CC) $(FLAGS) $(NAME)
# 	$(CC) $(FLAGS) $(NAME) $(SRC) libft.a $(INCLUDES) $(LINCLUDES)
#
# clean:
# 	rm -f $(OFILES)
#
# fclean: clean
# 	rm -f $(NAME)
# 	rm -f libft.a
#
# re: fclean all

.PHONY: all, $(NAME), clean, fclean, re

NAME = fillit

CC = gcc
CC_FLAGS = -Wall -Werror -Wextra

SRC_PATH = ./srcs/
INC_PATH = ./includes/
OBJ_PATH = ./obj/
LFT_PATH = ./libft/

SRC = $(addprefix $(SRC_PATH),$(SRC_NAME))
OBJ = $(addprefix $(OBJ_PATH),$(OBJ_NAME))
INC = $(addprefix -I,$(INC_PATH))

OBJ_NAME = $(SRC_NAME:.c=.o)

INC_NAME = fillit.h

SRC_NAME = fillit.c solve.c parse.c map.c parse_helpers.c helpers.c

all: $(NAME)

$(NAME): $(OBJ)
	@make -C $(LFT_PATH)
	@$(CC) -o $(NAME) $(OBJ) -lm -L $(LFT_PATH) -lft


$(OBJ_PATH)%.o: $(SRC_PATH)%.c
	@mkdir -p $(OBJ_PATH)
	@$(CC) $(CC_FLAGS) $(INC) -o $@ -c $<

clean:
	@make -C $(LFT_PATH) clean
	@rm -rf $(OBJ_PATH)

fclean: clean
	@make -C $(LFT_PATH) fclean
	@rm -f $(NAME)

re: fclean all
