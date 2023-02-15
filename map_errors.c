/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:33:02 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/02/15 15:42:50 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_elements_utis(int e, int c, int p)
{
	if (e != 1 || c != 1 || p != 1)
	{
		ft_putstr_fd(RED"Error:\n"RESET, 1);
		ft_putstr_fd(RED"The map must contain at least\n"RESET, 1);
		ft_putstr_fd(RED"-Exit\n-Starting point\n-Collectible\n"RESET, 1);
		exit(EXIT_ERROR);
	}
}

static void	check_elements(char *line)
{
	int	i;
	int	e;
	int	c;
	int	p;

	i = 0;
	e = 0;
	c = 0;
	p = 0;
	while (line[i])
	{
		if (line[i] == 'E')
			e = 1;
		if (line[i] == 'C')
			c = 1;
		if (line[i] == 'P')
			p = 1;
		i++;
	}
	check_elements_utis(e, c, p);
}

static void	check_walls_conditions(char *line, t_game *game, int i)
{
	if (i < game->map.width && line[i] != '1')
	{
		ft_putstr_fd(RED"Error:\n"RESET, 1);
		ft_putstr_fd(RED"The map is not surrounded by walls\n"RESET, 1);
		exit(EXIT_ERROR);
	}
	else if ((i % game->map.width == 0 || i % game->map.width
			== game->map.width - 1) && line[i] != '1')
	{
		ft_putstr_fd(RED"Error:\n"RESET, 1);
		ft_putstr_fd(RED"The map is not surrounded by walls\n"RESET, 1);
		exit(EXIT_ERROR);
	}
	else if (i > (ft_strlen(line) - game->map.width) && line[i] != '1')
	{
		ft_putstr_fd(RED"Error:\n"RESET, 1);
		ft_putstr_fd(RED"The map is not surrounded by walls\n"RESET, 1);
		exit(EXIT_ERROR);
	}
}

static void	check_walls(char *line, t_game *game)
{
	int	i;

	i = 0;
	while (i < ft_strlen(line))
	{
		check_walls_conditions(line, game, i);
		i++;
	}
}

void	check_map(t_game *game)
{
	check_elements(game->map.line);
	check_map2(game);
	check_walls(game->map.line, game);
}
