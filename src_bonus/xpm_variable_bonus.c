/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm_variable_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 12:59:03 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/03/06 12:58:13 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	player_xpm(t_game *game)
{
	game->player.player_right = mlx_xpm_file_to_image(game->mlx,
			"./textures/character_right.xpm",
			&game->img_width, &game->img_height);
	if (!game->player.player_right)
		xpm_error();
	game->player.player_left = mlx_xpm_file_to_image(game->mlx,
			"./textures/character_left.xpm",
			&game->img_width, &game->img_height);
	if (!game->player.player_left)
		xpm_error();
	game->player.player_back = mlx_xpm_file_to_image(game->mlx,
			"./textures/character_back.xpm",
			&game->img_width, &game->img_height);
	if (!game->player.player_back)
		xpm_error();
}

void	map_xpm(t_game *game)
{
	game->map.cell = mlx_xpm_file_to_image(game->mlx,
			"./textures/grass.xpm", &game->img_width, &game->img_height);
	if (!game->map.cell)
		xpm_error();
	game->map.wall = mlx_xpm_file_to_image(game->mlx,
			"./textures/rock.xpm", &game->img_width, &game->img_height);
	if (!game->map.wall)
		xpm_error();
	game->map.exit = mlx_xpm_file_to_image(game->mlx,
			"./textures/exit.xpm", &game->img_width, &game->img_height);
	if (!game->map.exit)
		xpm_error();
	game->map.potion_img = mlx_xpm_file_to_image(game->mlx,
			"./textures/potion.xpm", &game->img_width, &game->img_height);
	if (!game->map.potion_img)
		xpm_error();
	game->map.enemy_left = mlx_xpm_file_to_image(game->mlx,
			"./textures/enemy_left.xpm", &game->img_width, &game->img_height);
	if (!game->map.enemy_left)
		xpm_error();
}

void	sprites_xpm(t_game *game)
{
	game->player.player_left_1 = mlx_xpm_file_to_image(game->mlx,
			"./textures/character_left_1.xpm",
			&game->img_width, &game->img_height);
	if (!game->player.player_left_1)
		xpm_error();
	game->player.player_right_1 = mlx_xpm_file_to_image(game->mlx,
			"./textures/character_right_1.xpm",
			&game->img_width, &game->img_height);
	if (!game->player.player_right_1)
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
