/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:51:25 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/02/23 19:42:37 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_nmax_elements_utis(int e, int p)
{
	if (e > 1 || p > 1)
	{
		ft_putstr_fd(RED"Error:\n"RESET, 1);
		ft_putstr_fd(RED"-------------------------\n"RESET, 1);
		ft_putstr_fd(RED"There can only be:\n"RESET, 1);
		ft_putstr_fd(RED"-1 Exit\n-1 starting point\n"RESET, 1);
		put_error_message("-------------------------\n");
	}
}

void	end_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}
