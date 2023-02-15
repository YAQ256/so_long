/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/29 14:05:17 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/02/15 15:15:28 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_get_line(char *stash)
{
	int			i;
	static char	*str;

	i = 0;
	if (!stash[i])
		return (0);
	while (stash[i] && stash[i] != '\n')
		i++;
	str = malloc(sizeof(char) * (i + 2));
	if (!str)
		return (0);
	i = 0;
	while (stash[i] && stash[i] != '\n')
	{
		str[i] = stash[i];
		i++;
	}
	if (stash[i] == '\n')
	{
		str[i] = stash[i];
		i++;
	}
	str[i] = '\0';
	return (str);
}

static char	*ft_stash(char *stash)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (stash[i] && stash[i] != '\n')
		i++;
	if (!stash[i])
	{
		free(stash);
		return (0);
	}
	str = malloc(sizeof(char) * (ft_strlen_gnl(stash) - i + 1));
	if (!str)
		return (0);
	i++;
	j = 0;
	while (stash[i])
		str[j++] = stash[i++];
	str[j] = '\0';
	free (stash);
	return (str);
}

static char	*ft_read_and_stash(int fd, char *stash)
{
	char	*buf;
	int		readed;

	buf = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buf)
		return (0);
	readed = 1;
	while (!ft_strchr_gnl(stash, '\n') && readed != 0)
	{
		readed = read(fd, buf, BUFFER_SIZE);
		if (readed < 0)
		{
			free(buf);
			return (0);
		}
		buf[readed] = '\0';
		stash = ft_strjoin_gnl(stash, buf);
	}
	free(buf);
	return (stash);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*stash;

	if (fd < 0 || BUFFER_SIZE <= 0 || read(fd, 0, 0) < 0)
	{
		free(stash);
		stash = 0;
		return (0);
	}
	stash = ft_read_and_stash(fd, stash);
	if (!stash)
		return (0);
	line = ft_get_line(stash);
	stash = ft_stash(stash);
	return (line);
}
