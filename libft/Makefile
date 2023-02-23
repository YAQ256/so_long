NAME = libft.a

CC = gcc
CFLAGS = -Werror -Wall -Wextra
RM = rm -rf

SRC =	ft_bzero.c\
		ft_calloc.c\
		ft_itoa.c\
		ft_memset.c\
		ft_putchar_fd.c\
		ft_putnbr_fd.c\
		ft_putstr_fd.c\
		ft_strlen.c\
		get_next_line.c\
		get_next_line_utils.c\
		ft_strdup_without_nl.c\
		ft_strjoin_without_nl.c

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