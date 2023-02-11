/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   write_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:20:44 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/02/11 16:34:48 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	write_map_w(t_game *game)
{
	int i;
	int j;
	int k;

	i = 0;
	j = 0;
	while (game->map.height)
	{
		k = 0;
		while (game->map.width)
		{
			k++;
			j++;1
		}
		i++;
	}
}