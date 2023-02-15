# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 13:51:55 by cyacoub-          #+#    #+#              #
#    Updated: 2023/02/15 16:09:24 by cyacoub-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

HEADER = so_long.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror -fsanitize=address
MLX_FLAGS = -framework OpenGL -framework AppKit
LIBFT = ./libft/libft.a
MLX = ./mlx/libmlx.a
MAIN = so_long.c
SRC = 	read_map.c\
		write_map.c\
		xpm_variable.c\
		hooks.c\
		steps.c\
		map_errors.c\
		map_errors2.c\
		enemy_move.c\
		put_images.c

OBJS = $(SRC:.c=.o)

all: make_libft make_mlx $(NAME)

make_libft:
	@make all -C ./libft

make_mlx:
	@make all -C ./mlx

$(NAME): $(OBJS) $(MAIN)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) $(MLX) $(MLX_FLAGS) $(MAIN) -o $(NAME)

bonus: all

clean:
	@rm -f $(OBJS)
	@make clean -C ./libft
	@make clean -C ./mlx

fclean: clean
	@rm -f $(NAME)
	@make fclean -C ./libft
	@make clean -C ./mlx

re: fclean all 

.PHONY: all clean fclean re bonus