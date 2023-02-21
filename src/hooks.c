/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 18:07:32 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/02/16 16:26:55 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_w(t_game *game)
{
	int	i;

	i = 0;
	while (i++ < (int)ft_strlen(game->map.line))
	{
		if (game->map.line[i] == 'P')
			break ;
	}
	if (game->map.line[i - game->map.width] == 'C')
			game->map.potion++;
	if (game->map.line[i - game->map.width] == 'E' && game->map.potion
		== game->map.all_potion)
		end_game(game);
	if (game->map.line[i - game->map.width] == 'M')
		end_game(game);
	else if (game->map.line[i - game->map.width] != '1'
		&& game->map.line[i - game->map.width] != 'E')
	{
		game->map.line[i] = '0';
		game->map.line[i - game->map.width] = 'P';
		game->player.steps++;
		game->player.steps_flg = 1;
		write_map_w(game);
	}
}

void	move_s(t_game *game)
{
	int	i;

	i = 0;
	while (i++ < (int)ft_strlen(game->map.line))
	{
		if (game->map.line[i] == 'P')
			break ;
	}
	if (game->map.line[i + game->map.width] == 'C')
			game->map.potion++;
	if (game->map.line[i + game->map.width] == 'E'
		&& game->map.potion == game->map.all_potion)
		end_game(game);
	if (game->map.line[i + game->map.width] == 'M')
		end_game(game);
	else if (game->map.line[i + game->map.width] != '1'
		&& game->map.line[i + game->map.width] != 'E')
	{
		game->map.line[i] = '0';
		game->map.line[i + game->map.width] = 'P';
		game->player.steps++;
		game->player.steps_flg = 1;
		write_map_s(game);
	}
}

void	move_d(t_game *game)
{
	int	i;

	i = 0;
	while (i++ < (int)ft_strlen(game->map.line))
	{
		if (game->map.line[i] == 'P')
			break ;
	}
	if (game->map.line[i + 1] == 'C')
			game->map.potion++;
	if (game->map.line[i + 1] == 'E'
		&& game->map.potion == game->map.all_potion)
		end_game(game);
	if (game->map.line[i + 1] == 'M')
		end_game(game);
	else if (game->map.line[i + 1] != '1'
		&& game->map.line[i + 1] != 'E')
	{
		game->map.line[i] = '0';
		game->map.line[i + 1] = 'P';
		game->player.steps++;
		game->player.steps_flg = 1;
		write_map_d(game);
	}
}

void	move_a(t_game *game)
{
	int	i;

	i = 0;
	while (i++ < (int)ft_strlen(game->map.line))
	{
		if (game->map.line[i] == 'P')
			break ;
	}
	if (game->map.line[i - 1] == 'C')
			game->map.potion++;
	if (game->map.line[i - 1] == 'E'
		&& game->map.potion == game->map.all_potion)
		end_game(game);
	if (game->map.line[i - 1] == 'M')
		end_game(game);
	else if (game->map.line[i - 1] != '1'
		&& game->map.line[i - 1] != 'E')
	{
		game->map.line[i] = '0';
		game->map.line[i - 1] = 'P';
		game->player.steps++;
		game->player.steps_flg = 1;
		write_map_a(game);
	}
}

int	press_key(int key_code, t_game *game)
{
	if (key_code == KEY_ESC)
		end_game(game);
	if (key_code == KEY_W)
	{
		move_w(game);
		enemy_move(game);
	}
	if (key_code == KEY_A)
	{
		move_a(game);
		enemy_move(game);
	}
	if (key_code == KEY_S)
	{
		move_s(game);
		enemy_move(game);
	}
	if (key_code == KEY_D)
	{
		move_d(game);
		enemy_move(game);
	}
	return (0);
}
