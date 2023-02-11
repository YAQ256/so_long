/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_variable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 12:59:03 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/02/11 13:05:39 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_xpm(t_game *game)
{
	game->player.player_right = mlx_xpm_file_to_image(game->mlx, "./xpm/blanco32.xpm", game->img_width, game->img_height);
	game->player.player_left = mlx_xpm_file_to_image(game->mlx, "./xpm/blanco32.xpm", game->img_width, game->img_height);
}
void	map_xpm(t_game *game)
{
	game->map.cell = mlx_xpm_file_to_image(game->mlx, "./xpm/verde32.xpm", game->img_width, game->img_height);
	game->map.wall = mlx_xpm_file_to_image(game->mlx, "./xpm/azul32.xpm", game->img_width, game->img_height);
}