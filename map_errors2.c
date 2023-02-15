/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:29:57 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/02/15 15:44:11 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_unrecognized(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != 'E' && line[i] != 'C' && line[i] != 'P'
			&& line[i] != '0' && line[i] != '1' && line[i] != 'M')
		{
			ft_putstr_fd(RED"Error:\n"RESET, 1);
			ft_putstr_fd(RED"The map has unrecognized elements\n"RESET, 1);
			exit(EXIT_ERROR);
		}
		i++;
	}
}

static void	check_rectangular(char *line, t_game *game)
{
	if (game->map.width * game->map.height != ft_strlen(line))
	{
		ft_putstr_fd(RED"Error:\n"RESET, 1);
		ft_putstr_fd(RED"Map is not rectangular\n"RESET, 1);
		exit(EXIT_ERROR);
	}
}

void	check_map2(t_game *game)
{
	check_unrecognized(game->map.line);
	check_rectangular(game->map.line, game);
}
