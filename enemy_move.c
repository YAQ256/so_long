/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_move.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 12:32:55 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/02/15 19:00:32 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	end_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

static void	cardinal_comprobation(t_game *game, int i)
{
	if (game->map.line[i - game->map.width] == 'C'
		|| game->map.line[i - game->map.width] == 'E'
		|| game->map.line[i - game->map.width] == '1'
		|| game->map.line[i + game->map.width] == 'C'
		|| game->map.line[i + game->map.width] == 'E'
		|| game->map.line[i + game->map.width] == '1'
		|| game->map.line[i + 1] == 'C'
		|| game->map.line[i + 1] == 'E'
		|| game->map.line[i + 1] == '1'
		|| game->map.line[i - 1] == 'C'
		|| game->map.line[i - 1] == 'E'
		|| game->map.line[i - 1] == '1')
		game->map.enemy_flg = 0;
}

static void	put_enemy_flg(t_game *game, int i)
{
	if (game->map.line[i - game->map.width] != '1'
		&& game->map.line[i - game->map.width] != 'E'
		&& game->map.line[i - game->map.width] != 'P'
		&& game->map.line[i - game->map.width] != 'C')
		game->map.enemy_flg = 1;
	if (game->map.line[i + game->map.width] != '1'
		&& game->map.line[i + game->map.width] != 'E'
		&& game->map.line[i + game->map.width] != 'P'
		&& game->map.line[i + game->map.width] != 'C')
		game->map.enemy_flg = 2;
	if (game->map.line[i + 1] != '1'
		&& game->map.line[i + 1] != 'E'
		&& game->map.line[i + 1] != 'P'
		&& game->map.line[i + 1] != 'C')
		game->map.enemy_flg = 3;
	if (game->map.line[i - 1] != '1'
		&& game->map.line[i - 1] != 'E'
		&& game->map.line[i - 1] != 'P'
		&& game->map.line[i - 1] != 'C')
		game->map.enemy_flg = 4;
}

void	enemy_flg_move(t_game *game, int i)
{
	if (game->map.enemy_flg == 1)
	{
		game->map.line[i] = '0';
		game->map.line[i - game->map.width] = 'M';
	}
	else if (game->map.enemy_flg == 2)
	{
		game->map.line[i] = '0';
		game->map.line[i + game->map.width] = 'M';
	}
	else if (game->map.enemy_flg == 3)
	{
		game->map.line[i] = '0';
		game->map.line[i + 1] = 'M';
	}
	else if (game->map.enemy_flg == 4)
	{
		game->map.line[i] = '0';
		game->map.line[i - 1] = 'M';
	}
}

void	enemy_move(t_game *game)
{
	int	i;

	i = 0;
	while (i++ < (int)ft_strlen(game->map.line))
	{
		if (game->map.line[i] == 'M')
			break ;
	}
	cardinal_comprobation(game, i);
	put_enemy_flg(game, i);
	enemy_flg_move(game, i);
}
