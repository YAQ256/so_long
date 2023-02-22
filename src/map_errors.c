/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:33:02 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/02/22 15:01:07 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	check_elements_utis(int e, int c, int p)
{
	if (e < 1 || c < 1 || p < 1)
	{
		ft_putstr_fd(RED"Error:\n"RESET, 1);
		ft_putstr_fd(RED"-------------------------\n"RESET, 1);
		ft_putstr_fd(RED"Missing items on the map.\n"RESET, 1);
		ft_putstr_fd(RED"The map should have\n"RESET, 1);
		ft_putstr_fd(RED"-Exit\n-Starting point\n-Collectible\n"RESET, 1);
		put_error_message("-------------------------\n");
	}
}

static void	check_elements(char *line)
{
	int	i;
	int	e;
	int	c;
	int	p;
	int	m;

	i = 0;
	e = 0;
	c = 0;
	p = 0;
	m = 0;
	while (line[i])
	{
		if (line[i] == 'E')
			e++;
		if (line[i] == 'C')
			c++;
		if (line[i] == 'P')
			p++;
		if (line[i] == 'M')
			m++;
		i++;
	}
	check_elements_utis(e, c, p);
	check_nmax_elements_utis(e, p, m);
}

static void	check_walls_conditions(char *line, t_game *game, int i)
{
	if (i < game->map.width && line[i] != '1')
	{
		ft_putstr_fd(RED"-------------------------\n"RESET, 1);
		ft_putstr_fd(RED"Error:\n"RESET, 1);
		ft_putstr_fd(RED"The map is not surrounded by walls\n"RESET, 1);
		put_error_message("-------------------------\n");
	}
	else if ((i % game->map.width == 0 || i % game->map.width
			== game->map.width - 1) && line[i] != '1')
	{
		ft_putstr_fd(RED"-------------------------\n"RESET, 1);
		ft_putstr_fd(RED"Error:\n"RESET, 1);
		ft_putstr_fd(RED"The map is not surrounded by walls\n"RESET, 1);
		put_error_message("-------------------------\n");
	}
	else if (i > (ft_strlen(line) - game->map.width) && line[i] != '1')
	{
		ft_putstr_fd(RED"-------------------------\n"RESET, 1);
		ft_putstr_fd(RED"Error:\n"RESET, 1);
		ft_putstr_fd(RED"The map is not surrounded by walls\n"RESET, 1);
		put_error_message("-------------------------\n");
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
	check_unrecognized(game->map.line);
	check_rectangular(game->map.line, game);
	check_walls(game->map.line, game);
	search_route_exit(game);
}
