# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 15:42:10 by cyacoub-          #+#    #+#              #
#    Updated: 2023/02/22 15:43:13 by cyacoub-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

HEADER = so_long.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -framework OpenGL -framework AppKit
LIBFT = ./libft/libft.a
MLX = ./mlx/libmlx.a
LIB = ./src/so_long.h
SRC_PATH = ./src/
SRC = 	so_long.c\
		read_map.c\
		write_map.c\
		xpm_variable.c\
		hooks.c\
		steps.c\
		map_errors.c\
		map_errors2.c\
		map_errors3.c\
		enemy_move.c\
		put_images.c\
		map_route.c\
		win_lost.c

SRCS = $(addprefix $(SRC_PATH), $(SRC))

OBJS = $(SRCS:.c=.o)

all: make_libft make_mlx $(NAME)

make_libft:
	@make all -C ./libft

make_mlx:
	@make all -C ./mlx

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I $(LIB) $(LIBFT) $(MLX) $(MLX_FLAGS) $(MAIN) -o $(NAME)

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