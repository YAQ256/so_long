/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/22 14:51:25 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/02/22 15:40:37 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_nmax_elements_utis(int e, int p, int m)
{
	if (e > 1 || m > 1 || p > 1)
	{
		ft_putstr_fd(RED"Error:\n"RESET, 1);
		ft_putstr_fd(RED"-------------------------\n"RESET, 1);
		ft_putstr_fd(RED"There can only be:\n"RESET, 1);
		ft_putstr_fd(RED"-1 Exit\n-1 starting point\n-1 monster\n"RESET, 1);
		put_error_message("-------------------------\n");
	}
}
