/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:44:22 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/02/28 14:53:06 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	read_matrix(t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	game->map.copymap = ft_calloc(game->map.height + 1, sizeof(char *));
	if (!(game->map.copymap))
		return ;
	while (i < game->map.height)
	{
		game->map.copymap[i] = ft_calloc(game->map.width + 1, sizeof(char *));
		if (!(game->map.copymap))
			return ;
		j = 0;
		while (j < game->map.width)
			game->map.copymap[i][j++] = game->map.line[k++];
		i++;
	}
}

void	read_map(t_game *game, char *str)
{
	int		fd;
	char	*line;

	fd = open(str, O_RDONLY);
	if (fd == -1)
		put_error_message("Error: the map does not exist");
	line = get_next_line(fd);
	if (!line)
		put_error_message("Error: the map does not exist");
	game->map.height = 0;
	game->map.width = ft_strlen(line) - 1;
	game->map.line = (ft_strdup_without_nl(line));
	free(line);
	while (line)
	{
		line = get_next_line(fd);
		game->map.line = ft_strjoin_without_nl(game->map.line, line);
		game->map.height++;
	}
	close(fd);
	read_matrix(game);
	check_map(game);
}
