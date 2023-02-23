/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:20:44 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/02/23 19:51:23 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	write_map_w(t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.line[k] == '1' || game->map.line[k] == 'E')
				put_rocks_exit(game, j, i, k);
			else if (game->map.line[k] == 'P')
				put_player_back(game, j, i);
			else if (game->map.line[k] == 'C')
				put_potions(game, j, i);
			else
				mlx_put_image_to_window(game->mlx, game->win,
					game->map.cell, j * 32, i * 32);
			k++;
			j++;
		}
		i++;
	}
}

void	write_map_s(t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.line[k] == '1' || game->map.line[k] == 'E')
				put_rocks_exit(game, j, i, k);
			else if (game->map.line[k] == 'P')
				put_player_right(game, j, i);
			else if (game->map.line[k] == 'C')
				put_potions(game, j, i);
			else
				mlx_put_image_to_window(game->mlx, game->win,
					game->map.cell, j * 32, i * 32);
			k++;
			j++;
		}
		i++;
	}
}

void	write_map_a(t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.line[k] == '1' || game->map.line[k] == 'E')
				put_rocks_exit(game, j, i, k);
			else if (game->map.line[k] == 'P')
				put_player_left(game, j, i);
			else if (game->map.line[k] == 'C')
				put_potions(game, j, i);
			else
				mlx_put_image_to_window(game->mlx, game->win,
					game->map.cell, j * 32, i * 32);
			k++;
			j++;
		}
		i++;
	}
}

void	write_map_d(t_game *game)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.line[k] == '1' || game->map.line[k] == 'E')
				put_rocks_exit(game, j, i, k);
			else if (game->map.line[k] == 'P')
				put_player_right(game, j, i);
			else if (game->map.line[k] == 'C')
				put_potions(game, j, i);
			else
				mlx_put_image_to_window(game->mlx, game->win,
					game->map.cell, j * 32, i * 32);
			k++;
			j++;
		}
		i++;
	}
}
