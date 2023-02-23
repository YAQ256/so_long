/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/12 19:01:23 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/02/23 12:35:38 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <stddef.h>
# include <stdlib.h>
# include <ctype.h>
# include <string.h>
# include <fcntl.h>
# include <limits.h>
# include <stdint.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t count, size_t size);
char	*ft_itoa(int n);
void	*ft_memset(void *b, int c, size_t n);
void	ft_putchar_fd(char c, int fd);
void	ft_putnbr_fd(int n, int fd);
void	ft_putstr_fd(char *s, int fd);
int		ft_strlen(const char *str);

char	*get_next_line(int fd);
size_t	ft_strlen_gnl(char *str);
char	*ft_strjoin_gnl(char *s1, char *s2);
char	*ft_strchr_gnl(char *str, int c);
char	*ft_strdup_without_nl(char *s);
char	*ft_strjoin_without_nl(char *s1, char *s2);

#endif
