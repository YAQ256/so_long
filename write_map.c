/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:20:44 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/02/12 18:05:04 by cyacoub-         ###   ########.fr       */
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
				mlx_put_image_to_window(game->mlx, game->win, game->map.wall, j * 32, i * 32);
			else if (game->map.line[k] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, game->player.left, j * 32, i * 32);
			/* else if (game->map.line[k] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, game->map.cell, j * 32, i * 32); */
			else
				mlx_put_image_to_window(game->mlx, game->win, game->map.cell, j * 32, i * 32);
			k++;
			j++;
		}
		i++;
	}
}