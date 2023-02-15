/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_images.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:58:38 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/02/15 19:13:43 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_rocks_exit(t_game *game, int j, int i, int k)
{
	if (game->map.line[k] == '1')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->map.cell[2], j * 32, i * 32);
		mlx_put_image_to_window(game->mlx, game->win,
			game->map.wall, j * 32, i * 32);
	}
	else if (game->map.line[k] == 'E')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->map.cell[2], j * 32, i * 32);
		if (game->map.potion == game->map.all_potion)
			mlx_put_image_to_window(game->mlx, game->win,
				game->map.exit, j * 32, i * 32);
		else
			mlx_put_image_to_window(game->mlx, game->win,
				game->map.wall, j * 32, i * 32);
	}
}

void	put_potions_enemys(t_game *game, int j, int i, int k)
{
	if (game->map.line[k] == 'C')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->map.cell[2], j * 32, i * 32);
		mlx_put_image_to_window(game->mlx, game->win,
			game->map.potion_img, j * 32, i * 32);
	}
	else if (game->map.line[k] == 'M')
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->map.cell[2], j * 32, i * 32);
		mlx_put_image_to_window(game->mlx, game->win,
			game->map.enemy_left, j * 32, i * 32);
	}
}

void	put_player_back(t_game *game, int j, int i)
{
	mlx_put_image_to_window(game->mlx, game->win,
		game->map.cell[2], j * 32, i * 32);
	mlx_put_image_to_window(game->mlx, game->win,
		game->player.player_back, j * 32, i * 32);
}

void	put_player_right(t_game *game, int j, int i)
{
	if (game->player.player_right_1_flg == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->map.cell[2], j * 32, i * 32);
		mlx_put_image_to_window(game->mlx, game->win,
			game->player.player_right, j * 32, i * 32);
		game->player.player_right_1_flg = 1;
	}
	else if (game->player.player_right_1_flg == 1)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->map.cell[2], j * 32, i * 32);
		mlx_put_image_to_window(game->mlx, game->win,
			game->player.player_right_1, j * 32, i * 32);
		game->player.player_right_1_flg = 0;
	}
}

void	put_player_left(t_game *game, int j, int i)
{
	if (game->player.player_left_1_flg == 0)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->map.cell[2], j * 32, i * 32);
		mlx_put_image_to_window(game->mlx, game->win,
			game->player.player_left, j * 32, i * 32);
		game->player.player_left_1_flg = 1;
	}
	else if (game->player.player_left_1_flg == 1)
	{
		mlx_put_image_to_window(game->mlx, game->win,
			game->map.cell[2], j * 32, i * 32);
		mlx_put_image_to_window(game->mlx, game->win,
			game->player.player_left_1, j * 32, i * 32);
		game->player.player_left_1_flg = 0;
	}
}
