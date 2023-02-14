/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:20:44 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/02/14 15:38:08 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	write_map_w(t_game *game)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.line[k] == '1')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->map.cell[2], j * 32, i * 32);
				mlx_put_image_to_window(game->mlx, game->win, game->map.wall, j * 32, i * 32);
			}
			else if (game->map.line[k] == 'P')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->map.cell[2], j * 32, i * 32);
				mlx_put_image_to_window(game->mlx, game->win, game->player.player_back, j * 32, i * 32);
			}
			else if (game->map.line[k] == 'E')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->map.cell[2], j * 32, i * 32);
				if (game->map.potion == game->map.all_potion)
					mlx_put_image_to_window(game->mlx, game->win, game->map.exit, j * 32, i * 32);
				else
					mlx_put_image_to_window(game->mlx, game->win, game->map.wall, j * 32, i * 32);
			}
			else if (game->map.line[k] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->map.cell[2], j * 32, i * 32);
				mlx_put_image_to_window(game->mlx, game->win, game->map.potion_img, j * 32, i * 32);
			}
			else if (game->map.line[k] == 'M')
			{
				if (game->map.enemy_pos >= 0 && game->map.enemy_pos <= 3)
				{
					mlx_put_image_to_window(game->mlx, game->win, game->map.cell[2], j * 32, i * 32);
					mlx_put_image_to_window(game->mlx, game->win, game->map.enemy_left, j * 32, i * 32);
					game->map.enemy_pos++;
				}
				else if (game->map.enemy_pos > 3 && game->map.enemy_pos <= 6)
				{
					mlx_put_image_to_window(game->mlx, game->win, game->map.cell[2], j * 32, i * 32);
					mlx_put_image_to_window(game->mlx, game->win, game->map.enemy_right, j * 32, i * 32);
					game->map.enemy_pos++;
				}
				else
					game->map.enemy_pos = 0;
			}
			else
				mlx_put_image_to_window(game->mlx, game->win, game->map.cell[2], j * 32, i * 32);
			k++;
			j++;
		}
		i++;
	}
}
void	write_map_a(t_game *game)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.line[k] == '1')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->map.cell[2], j * 32, i * 32);
				mlx_put_image_to_window(game->mlx, game->win, game->map.wall, j * 32, i * 32);
			}
			else if (game->map.line[k] == 'P')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->map.cell[2], j * 32, i * 32);
				mlx_put_image_to_window(game->mlx, game->win, game->player.player_left, j * 32, i * 32);
			}
			else if (game->map.line[k] == 'E')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->map.cell[2], j * 32, i * 32);
				if (game->map.potion == game->map.all_potion)
					mlx_put_image_to_window(game->mlx, game->win, game->map.exit, j * 32, i * 32);
				else
					mlx_put_image_to_window(game->mlx, game->win, game->map.wall, j * 32, i * 32);
			}
			else if (game->map.line[k] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->map.cell[2], j * 32, i * 32);
				mlx_put_image_to_window(game->mlx, game->win, game->map.potion_img, j * 32, i * 32);
			}
			else if (game->map.line[k] == 'M')
			{
				if (game->map.enemy_pos >= 0 && game->map.enemy_pos <= 3)
				{
					mlx_put_image_to_window(game->mlx, game->win, game->map.cell[2], j * 32, i * 32);
					mlx_put_image_to_window(game->mlx, game->win, game->map.enemy_left, j * 32, i * 32);
					game->map.enemy_pos++;
				}
				else if (game->map.enemy_pos > 3 && game->map.enemy_pos <= 6)
				{
					mlx_put_image_to_window(game->mlx, game->win, game->map.cell[2], j * 32, i * 32);
					mlx_put_image_to_window(game->mlx, game->win, game->map.enemy_right, j * 32, i * 32);
					game->map.enemy_pos++;
				}
				else
					game->map.enemy_pos = 0;
			}
			else
				mlx_put_image_to_window(game->mlx, game->win, game->map.cell[2], j * 32, i * 32);
			k++;
			j++;
		}
		i++;
	}
}
void	write_map_s(t_game *game)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.line[k] == '1')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->map.cell[2], j * 32, i * 32);
				mlx_put_image_to_window(game->mlx, game->win, game->map.wall, j * 32, i * 32);
			}
			else if (game->map.line[k] == 'P')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->map.cell[2], j * 32, i * 32);
				mlx_put_image_to_window(game->mlx, game->win, game->player.player_right, j * 32, i * 32);
			}
			else if (game->map.line[k] == 'E')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->map.cell[2], j * 32, i * 32);
				if (game->map.potion == game->map.all_potion)
					mlx_put_image_to_window(game->mlx, game->win, game->map.exit, j * 32, i * 32);
				else
					mlx_put_image_to_window(game->mlx, game->win, game->map.wall, j * 32, i * 32);
			}
			else if (game->map.line[k] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->map.cell[2], j * 32, i * 32);
				mlx_put_image_to_window(game->mlx, game->win, game->map.potion_img, j * 32, i * 32);
			}
			else if (game->map.line[k] == 'M')
			{
				if (game->map.enemy_pos >= 0 && game->map.enemy_pos <= 3)
				{
					mlx_put_image_to_window(game->mlx, game->win, game->map.cell[2], j * 32, i * 32);
					mlx_put_image_to_window(game->mlx, game->win, game->map.enemy_left, j * 32, i * 32);
					game->map.enemy_pos++;
				}
				else if (game->map.enemy_pos > 3 && game->map.enemy_pos <= 6)
				{
					mlx_put_image_to_window(game->mlx, game->win, game->map.cell[2], j * 32, i * 32);
					mlx_put_image_to_window(game->mlx, game->win, game->map.enemy_right, j * 32, i * 32);
					game->map.enemy_pos++;
				}
				else
					game->map.enemy_pos = 0;
			}
			else
				mlx_put_image_to_window(game->mlx, game->win, game->map.cell[2], j * 32, i * 32);
			k++;
			j++;
		}
		i++;
	}
}
void	write_map_d(t_game *game)
{
	int i;
	int j;
	int k;

	i = 0;
	k = 0;
	while (i < game->map.height)
	{
		j = 0;
		while (j < game->map.width)
		{
			if (game->map.line[k] == '1')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->map.cell[2], j * 32, i * 32);
				mlx_put_image_to_window(game->mlx, game->win, game->map.wall, j * 32, i * 32);
			}
			else if (game->map.line[k] == 'P')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->map.cell[2], j * 32, i * 32);
				mlx_put_image_to_window(game->mlx, game->win, game->player.player_right, j * 32, i * 32);
			}
			else if (game->map.line[k] == 'E')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->map.cell[2], j * 32, i * 32);
				if (game->map.potion == game->map.all_potion)
					mlx_put_image_to_window(game->mlx, game->win, game->map.exit, j * 32, i * 32);
				else
					mlx_put_image_to_window(game->mlx, game->win, game->map.wall, j * 32, i * 32);
			}
			else if (game->map.line[k] == 'C')
			{
				mlx_put_image_to_window(game->mlx, game->win, game->map.cell[2], j * 32, i * 32);
				mlx_put_image_to_window(game->mlx, game->win, game->map.potion_img, j * 32, i * 32);
			}
			else if (game->map.line[k] == 'M')
			{
				if (game->map.enemy_pos >= 0 && game->map.enemy_pos <= 3)
				{
					mlx_put_image_to_window(game->mlx, game->win, game->map.cell[2], j * 32, i * 32);
					mlx_put_image_to_window(game->mlx, game->win, game->map.enemy_left, j * 32, i * 32);
					game->map.enemy_pos++;
				}
				else if (game->map.enemy_pos > 3 && game->map.enemy_pos <= 6)
				{
					mlx_put_image_to_window(game->mlx, game->win, game->map.cell[2], j * 32, i * 32);
					mlx_put_image_to_window(game->mlx, game->win, game->map.enemy_right, j * 32, i * 32);
					game->map.enemy_pos++;
				}
				else
					game->map.enemy_pos = 0;
			}
			else
				mlx_put_image_to_window(game->mlx, game->win, game->map.cell[2], j * 32, i * 32);
			k++;
			j++;
		}
		i++;
	}
}