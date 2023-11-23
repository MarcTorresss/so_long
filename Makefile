# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: martorre <martorre@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/09 15:18:11 by martorre          #+#    #+#              #
#    Updated: 2023/11/23 14:07:57 by martorre         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

C = clang
CC = gcc
NAME = so_long

FLAGS = -Wall -Wextra -Werror -O3 -I./libft

LIBFT = libft

DIR_O = temp

DIR_MLX = mlx

SOURCES = main.c check_map.c utils.c moves.c mlx_utils.c

OBJS = $(addprefix $(DIR_O)/,$(SOURCES:.c=.o))

all: temp make_lib make_mlx $(NAME)

$(NAME): $(OBJS) libft/libft.a mlx/libmlx.a
	$(CC) $(OBJS) libft/libft.a mlx/libmlx.a -Lmlx -lmlx -framework OpenGL -framework AppKit -o $(NAME)
	@echo "$(GREEN)so_long Compiled$(NC)"

make_lib:
	@$(MAKE) -C $(LIBFT) --no-print-directory

make_mlx:
	@$(MAKE) -C $(DIR_MLX) --no-print-directory

temp:
	@mkdir -p temp

$(DIR_O)/%.o: %.c $(NAME).h libft/libft.a
	$(CC) -Wall -Wextra -Werror -Imlx -c $< -o $@

clean:
	@rm -rf $(DIR_O)
	@echo Deleting all objects

fclean: clean
	@rm -rf $(NAME)
	@echo Deleting all

re : fclean all

.PHONY: all clean fclean re