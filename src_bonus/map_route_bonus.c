/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_route_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 15:49:28 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/02/23 12:42:11 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

static void	change_map(t_game *game, int x, int y)
{
	if (game->map.copymap[x][y] == 'C' || game->map.copymap[x][y] == '0')
		game->map.copymap[x][y] = 'P';
}

static int	search_route(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map.height)
	{
		y = 0;
		while (y < game->map.width)
		{
			if ((game->map.copymap[x][y] == 'E'
				&& game->map.copymap[x][y + 1] == 'P')
				|| (game->map.copymap[x][y] == 'E' &&
				game->map.copymap[x][y - 1] == 'P')
				|| (game->map.copymap[x][y] == 'E' &&
				game->map.copymap[x - 1][y] == 'P')
				|| (game->map.copymap[x][y] == 'E' &&
				game->map.copymap[x + 1][y] == 'P'))
				return (1);
			y++;
		}
		x++;
	}
	put_invalid_path();
	return (0);
}

static int	check_exit(t_game *game, int x, int y)
{
	if (game->map.copymap[x][y] == 'P' &&
	(game->map.copymap[x][y + 1] == '0'
	|| game->map.copymap[x][y + 1] == 'C'
	|| game->map.copymap[x][y - 1] == '0'
	|| game->map.copymap[x][y - 1] == 'C'
	|| game->map.copymap[x + 1][y] == '0'
	|| game->map.copymap[x + 1][y] == 'C'
	|| game->map.copymap[x - 1][y] == 'C'
	|| game->map.copymap[x - 1][y] == '0'))
		return (1);
	return (0);
}

static int	check_collect(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.copymap[i][j] == 'C')
				put_invalid_path();
			j++;
		}
		i++;
	}
	return (1);
}

int	search_route_exit(t_game *game)
{
	int	x;
	int	y;

	x = 0;
	while (x < game->map.height)
	{
		y = 0;
		while (y < game->map.width)
		{
			if (check_exit(game, x, y))
			{
				change_map(game, x + 1, y);
				change_map(game, x - 1, y);
				change_map(game, x, y + 1);
				change_map(game, x, y - 1);
				x = 0;
			}
			y++;
		}
		x++;
	}
	check_collect(game);
	if (search_route(game))
		return (1);
	return (0);
}
