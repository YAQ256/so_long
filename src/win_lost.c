/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_lost.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/21 20:13:52 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/02/21 20:36:06 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	win_game(t_game *game)
{
	ft_putstr_fd(GREEN"             --------\n"RESET, 1);
	ft_putstr_fd(GREEN"             You win\n"RESET, 1);
	ft_putstr_fd(GREEN"             --------\n"RESET, 1);
	ft_putstr_fd(GREEN"      ▄▄▄▄▀▀▀▀▀▀▀▀▄▄▄▄▄▄▄\n"RESET, 1);
	ft_putstr_fd(GREEN"     █░░░░░░░░░░░░░░░░░░▀▀▄\n"RESET, 1);
	ft_putstr_fd(GREEN"    █░░░░░░░░░░░░░░░░░░░░░░█\n"RESET, 1);
	ft_putstr_fd(GREEN"   █░░░░░░▄██▀▄▄░░░░░▄▄▄░░░░█\n"RESET, 1);
	ft_putstr_fd(GREEN" ▄▀░▄▄▄░░█▀▀▀▀▄▄█░░░██▄▄█░░░░█\n"RESET, 1);
	ft_putstr_fd(GREEN"█░░█░▄░▀▄▄▄▀░░░░░░░░█░░░░░░░░░█\n"RESET, 1);
	ft_putstr_fd(GREEN"█░░█░█▀▄▄░░░░░█▀░░░░▀▄░░▄▀▀▀▄░█\n"RESET, 1);
	ft_putstr_fd(GREEN" █░▀▄░█▄░█▀▄▄░▀░▀▀░▄▄▀░░░░█░░█\n"RESET, 1);
	ft_putstr_fd(GREEN"  █░░░▀▄▀█▄▄░█▀▀▀▄▄▄▄▀▀█▀██░█\n"RESET, 1);
	ft_putstr_fd(GREEN"   █░░░░██░░▀█▄▄▄█▄▄█▄▄██▄░░█\n"RESET, 1);
	ft_putstr_fd(GREEN"    █░░░░▀▀▄░█░░░█░█▀█▀█▀██░█\n"RESET, 1);
	ft_putstr_fd(GREEN"     ▀▄░░░░░▀▀▄▄▄█▄█▄█▄█▄▀░░█\n"RESET, 1);
	ft_putstr_fd(GREEN"       ▀▄▄░░░░░░░░░░░░░░░░░░░█\n"RESET, 1);
	ft_putstr_fd(GREEN"  ▐▌ █     ▀▀▄▄░░░░░░░░░░░░░░░█\n"RESET, 1);
	ft_putstr_fd(GREEN"   █▐▌      █░▀▄▄▄▄▄░░░░░░░░█\n"RESET, 1);
	ft_putstr_fd(GREEN"  ███     ▄▄█░▄▄░██▄▄▄▄▄▄▄▄▀\n"RESET, 1);
	ft_putstr_fd(GREEN" ▐████  ▄▀█▀█▄▄▄▄▄█▀▄▀▄\n"RESET, 1);
	ft_putstr_fd(GREEN"  █░░▌ █░░░▀▄░█▀█░▄▀░░░█\n"RESET, 1);
	ft_putstr_fd(GREEN"  █░░▌ █░░█░░█░░░█░░█░░█\n"RESET, 1);
	ft_putstr_fd(GREEN"  █░░▀▀░░██░░█░░░█░░█░░█\n"RESET, 1);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}

void	lost_game(t_game *game)
{
	ft_putstr_fd(RED"             --------\n"RESET, 1);
	ft_putstr_fd(RED"             You lost\n"RESET, 1);
	ft_putstr_fd(RED"             --------\n"RESET, 1);
	ft_putstr_fd(BLACK"▒▒▒▒▒▒▒▒▒▒▒▄▄▄▄░▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n"RESET, 1);
	ft_putstr_fd(BLACK"▒▒▒▒▒▒▒▒▒▄██████▒▒▒▒▒▄▄▄█▄▒▒▒▒▒▒▒▒▒▒\n"RESET, 1);
	ft_putstr_fd(BLACK"▒▒▒▒▒▒▒▄██▀░░▀██▄▒▒▒▒████████▄▒▒▒▒▒▒\n"RESET, 1);
	ft_putstr_fd(BLACK"▒▒▒▒▒▒███░░░░░░██▒▒▒▒▒▒█▀▀▀▀▀██▄▄▒▒▒\n"RESET, 1);
	ft_putstr_fd(BLACK"▒▒▒▒▒▄██▌░░░░░░░██▒▒▒▒▐▌▒▒▒▒▒▒▒▒▀█▄▒\n"RESET, 1);
	ft_putstr_fd(BLACK"▒▒▒▒▒███░░▐█░█▌░██▒▒▒▒█▌▒▒▒▒▒▒▒▒▒▒▀▌\n"RESET, 1);
	ft_putstr_fd(BLACK"▒▒▒▒████░▐█▌░▐█▌██▒▒▒██▒▒▒▒▒▒▒▒▒▒▒▒▒\n"RESET, 1);
	ft_putstr_fd(BLACK"▒▒▒▐████░▐░░░░░▌██▒▒▒█▌▒▒▒▒▒▒▒▒▒▒▒▒▒\n"RESET, 1);
	ft_putstr_fd(BLACK"▒▒▒▒████░░░▄█░░░██▒▒▐█▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n"RESET, 1);
	ft_putstr_fd(BLACK"▒▒▒▒████░░░██░░██▌▒▒█▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n"RESET, 1);
	ft_putstr_fd(BLACK"▒▒▒▒████▌░▐█░░███▒▒▒█▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n"RESET, 1);
	ft_putstr_fd(BLACK"▒▒▒▒▐████░░▌░███▒▒▒██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n"RESET, 1);
	ft_putstr_fd(BLACK"▒▒▒▒▒████░░░███▒▒▒▒█▌▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n"RESET, 1);
	ft_putstr_fd(BLACK"▒▒▒██████▌░████▒▒▒██▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n"RESET, 1);
	ft_putstr_fd(BLACK"▒▐████████████▒▒███▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n"RESET, 1);
	ft_putstr_fd(BLACK"▒█████████████▄████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n"RESET, 1);
	ft_putstr_fd(BLACK"██████████████████▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒▒\n"RESET, 1);
	mlx_destroy_window(game->mlx, game->win);
	exit(0);
}
