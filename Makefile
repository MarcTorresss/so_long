# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: martorre <martorre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 15:18:11 by martorre          #+#    #+#              #
#    Updated: 2023/11/09 15:20:40 by martorre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= so_long
FLAGS 	= -Wall -Wextra -Werror -I./libft
INCLUDE = so_long.h
CC = cc
DIR_OBJ = temp/

SOURCES = main.c\


OBJ = $(addprefix $(DIR_OBJ), $(SOURCES:.c=.o))


all: temp MAKELIB $(NAME)

temp:
	mkdir -p $(DIR_OBJ)

$(NAME): $(OBJ)
	@$(CC) $(FLAGS) $(OBJ) libft/libft.a -o $(NAME)
	@echo so_long compiled

all_test: temp MAKELIB test

test: $(OBJ)
	$(CC)  ./libft/libft.a $(OBJ)

MAKELIB:
	$(MAKE) -C ./libft

$(DIR_OBJ)%.o: %.c Makefile $(INCLUDE)
	@mkdir -p $(dir $@)
	@$(CC) $(FLAGS) -c $< -o $@
	@echo Compiling $< ...

clean:
	@rm -rf $(DIR_OBJ)
	@echo Deleting all objects

fclean: clean
	@rm -rf $(NAME) $(BONUS_NAME)
	@echo Deleting all

re : fclean all

.PHONY: all clean fclean re