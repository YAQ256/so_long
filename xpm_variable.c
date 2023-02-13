/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_variable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 12:59:03 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/02/13 18:28:48 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_xpm(t_game *game)
{
	game->player.player_right = mlx_xpm_file_to_image(game->mlx, "./xpm/character_right.xpm", &game->img_width, &game->img_height);
	game->player.player_left = mlx_xpm_file_to_image(game->mlx, "./xpm/character_left.xpm", &game->img_width, &game->img_height);
	game->player.player_back = mlx_xpm_file_to_image(game->mlx, "./xpm/character_back.xpm", &game->img_width, &game->img_height);
}
void	map_xpm(t_game *game)
{
	game->map.cell[0] = mlx_xpm_file_to_image(game->mlx, "./xpm/grass1.xpm", &game->img_width, &game->img_height);
	game->map.cell[1] = mlx_xpm_file_to_image(game->mlx, "./xpm/grass2.xpm", &game->img_width, &game->img_height);
	game->map.cell[2] = mlx_xpm_file_to_image(game->mlx, "./xpm/grass3.xpm", &game->img_width, &game->img_height);
	game->map.wall = mlx_xpm_file_to_image(game->mlx, "./xpm/rock.xpm", &game->img_width, &game->img_height);
	game->map.potion = mlx_xpm_file_to_image(game->mlx, "./xpm/potion.xpm", &game->img_width, &game->img_height);
	game->map.exit = mlx_xpm_file_to_image(game->mlx, "./xpm/exit.xpm", &game->img_width, &game->img_height);
}