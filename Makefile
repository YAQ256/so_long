# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/11/08 13:51:55 by cyacoub-          #+#    #+#              #
#    Updated: 2022/11/08 13:54:10 by cyacoub-         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

CC = gcc
CFLAGS = -Werror -Wall -Wextra
RM = rm -rf

SRC = 

OBJS = $(SRC:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	@ar crs $(NAME) $(OBJS)

clean:
	@$(RM) $(OBJS)

fclean: clean
	@rm -f $(NAME)

re: fclean all

.PHONY: all re clean fclean 