/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:13:30 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/02/14 15:28:35 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void total_potion(t_game *game)
{
	int i;

	game->map.all_potion = 0;
	i = 0;
	while(game->map.line[i])
	{
		if (game->map.line[i] == 'C')
			game->map.all_potion++;
		i++;
	}
}

int	redcross(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
	return (0);
}

static	int	loop_hook(t_game *game)
{
	 t_win_steps(game);
	 return (0);
}
int	main(void)
{
	t_game	game;

	read_map(&game);
	total_potion(&game);
	game.player.steps = 0;
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx, game.map.width * 32, game.map.height * 32, "Fase Beta");
	map_xpm(&game);
	player_xpm(&game);
	game.map.potion = 0;
	game.map.enemy_pos = 0;
	write_map_s(&game);
	mlx_key_hook(game.win, press_key, &game);
	mlx_loop_hook(game.mlx, &loop_hook, &game);
	mlx_hook(game.win, DESTROY_NOTIFY, 0, redcross, &game);
	mlx_loop(game.mlx);
}
