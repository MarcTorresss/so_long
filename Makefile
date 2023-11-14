# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: martorre <martorre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 15:18:11 by martorre          #+#    #+#              #
#    Updated: 2023/11/14 16:02:08 by martorre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= so_long
FLAGS 	= -Wall -Wextra -Werror -O3 -I./libft
INCLUDE = so_long.h
CC = cc
DIR_OBJ = temp/


SOURCES = main.c check_map.c\


OBJ = $(addprefix $(DIR_OBJ), $(SOURCES:.c=.o))


all: temp makelib $(NAME)

temp:
	mkdir -p $(DIR_OBJ)

$(NAME): $(OBJ) libft/libft.a
	@$(CC) $(FLAGS) -L libft -lft -o $@ $^ -framework OpenGL -framework AppKit -L mlx -lmlx
	@echo so_long compiled

all_test: temp MAKELIB

makelib:
	$(MAKE) -C ./mlx
	$(MAKE) -C ./libft

$(DIR_OBJ)%.o: %.c Makefile $(INCLUDE) libft/libft.a
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