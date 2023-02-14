/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   steps.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/14 13:15:53 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/02/14 17:17:04 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	t_steps(t_game *game)
{
	ft_putstr_fd("You have taken ", 1);
	ft_putnbr_fd(game->player.steps, 1);
	ft_putstr_fd(" steps", 1);
	ft_putchar_fd('\n', 1);
	game->player.steps_flg = 0;
}

static void	win_steps(t_game *game)
{
	char	*str;

	str = ft_itoa(game->player.steps);
	mlx_string_put(game->mlx, game->win, 0, 10, 0x000000, str);
}

int	t_win_steps(t_game *game)
{
	if (game->player.steps_flg)
		t_steps(game);
	mlx_put_image_to_window(game->mlx, game->win, game->map.cell[2], 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->map.wall, 0, 0);
	mlx_put_image_to_window(game->mlx, game->win, game->map.cell[2], 0, 32);
	mlx_put_image_to_window(game->mlx, game->win, game->map.wall, 0, 32);
	win_steps(game);
	return (0);
}