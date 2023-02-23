# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/02/22 15:42:10 by cyacoub-          #+#    #+#              #
#    Updated: 2023/02/23 19:29:31 by cyacoub-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
NAME_BONUS = so_long_bonus

HEADER = so_long.h

CC = gcc
CFLAGS = -Wall -Wextra -Werror
MLX_FLAGS = -framework OpenGL -framework AppKit
LIBFT = ./libft/libft.a
MLX = ./mlx/libmlx.a
LIB = ./src/so_long.h
LIB_BONUS = ./src/so_long_bonus.h
SRC_PATH = ./src/
SRC_BONUS_PATH = ./src_bonus/

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

SRC_BONUS =	so_long_bonus.c\
			read_map_bonus.c\
			write_map_bonus.c\
			xpm_variable_bonus.c\
			hooks_bonus.c\
			steps_bonus.c\
			map_errors_bonus.c\
			map_errors2_bonus.c\
			map_errors3_bonus.c\
			enemy_move_bonus.c\
			put_images_bonus.c\
			map_route_bonus.c\
			win_lost_bonus.c

SRCS = $(addprefix $(SRC_PATH), $(SRC))
SRCS_BONUS = $(addprefix $(SRC_BONUS_PATH), $(SRC))

OBJS = $(SRCS:.c=.o)
OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all: make_libft make_mlx $(NAME)

bonus: make_libft make_mlx $(NAME_BONUS)

make_libft:
	@make all -C ./libft

make_mlx:
	@make all -C ./mlx

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -I $(LIB) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME)

$(NAME_BONUS): $(OBJS_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) -I $(LIB_BONUS) $(LIBFT) $(MLX) $(MLX_FLAGS) -o $(NAME_BONUS)

clean:
	@rm -f $(OBJS) $(OBJS_BONUS)
	@make clean -C ./libft
	@make clean -C ./mlx

fclean: clean
	@rm -f $(NAME) $(NAME_BONUS)
	@make fclean -C ./libft
	@make clean -C ./mlx

re: fclean all

re_bonus: fclean all

.PHONY: all clean fclean re bonus