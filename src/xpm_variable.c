/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_variable.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 12:59:03 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/02/23 19:47:23 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_xpm(t_game *game)
{
	game->player.player_right = mlx_xpm_file_to_image(game->mlx,
			"./textures/character_right.xpm",
			&game->img_width, &game->img_height);
	game->player.player_left = mlx_xpm_file_to_image(game->mlx,
			"./textures/character_left.xpm",
			&game->img_width, &game->img_height);
	game->player.player_back = mlx_xpm_file_to_image(game->mlx,
			"./textures/character_back.xpm",
			&game->img_width, &game->img_height);
	if (!(game->player.player_right || game->player.player_left
			|| game->player.player_back))
		xpm_error();
}

void	map_xpm(t_game *game)
{
	game->map.cell = mlx_xpm_file_to_image(game->mlx,
			"./textures/grass.xpm", &game->img_width, &game->img_height);
	game->map.wall = mlx_xpm_file_to_image(game->mlx,
			"./textures/rock.xpm", &game->img_width, &game->img_height);
	game->map.exit = mlx_xpm_file_to_image(game->mlx,
			"./textures/exit.xpm", &game->img_width, &game->img_height);
	game->map.potion_img = mlx_xpm_file_to_image(game->mlx,
			"./textures/potion.xpm", &game->img_width, &game->img_height);
	if (!(game->map.cell || game->map.wall || game->map.exit
			|| game->map.potion_img))
		xpm_error();
}

void	sprites_xpm(t_game *game)
{
	game->player.player_left_1 = mlx_xpm_file_to_image(game->mlx,
			"./textures/character_left_1.xpm",
			&game->img_width, &game->img_height);
	game->player.player_right_1 = mlx_xpm_file_to_image(game->mlx,
			"./textures/character_right_1.xpm",
			&game->img_width, &game->img_height);
	if (!(game->player.player_right_1 || game->player.player_left_1))
		xpm_error();
}

void	xpm_error(void)
{
	ft_putstr_fd(RED"-------------------------\n"RESET, 1);
	ft_putstr_fd(RED"Error:\n"RESET, 1);
	ft_putstr_fd(RED"No access to xpm images\n"RESET, 1);
	put_error_message("-------------------------\n");
	exit(EXIT_ERROR);
}
