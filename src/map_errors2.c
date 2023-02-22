/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_errors2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 15:29:57 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/02/22 15:40:29 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_unrecognized(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != 'E' && line[i] != 'C' && line[i] != 'P'
			&& line[i] != '0' && line[i] != '1' && line[i] != 'M')
		{
			ft_putstr_fd(RED"-------------------------\n"RESET, 1);
			ft_putstr_fd(RED"Error:\n"RESET, 1);
			ft_putstr_fd(RED"The map has unrecognized elements\n"RESET, 1);
			put_error_message("-------------------------\n");
		}
		i++;
	}
}

void	check_rectangular(char *line, t_game *game)
{
	if (game->map.width * game->map.height != ft_strlen(line))
	{
		ft_putstr_fd(RED"-------------------------\n"RESET, 1);
		ft_putstr_fd(RED"Error:\n"RESET, 1);
		ft_putstr_fd(RED"Map is not rectangular\n"RESET, 1);
		put_error_message("-------------------------\n");
		exit(EXIT_ERROR);
	}
}

void	put_error_message(char *str)
{
	ft_putstr_fd(RED, 1);
	ft_putstr_fd(str, 1);
	ft_putstr_fd(RESET, 1);
	exit(EXIT_ERROR);
}

void	put_invalid_path(void)
{
	ft_putstr_fd(RED"-------------------------\n"RESET, 1);
	ft_putstr_fd(RED"Error: Invalid path\n"RESET, 1);
	put_error_message("-------------------------\n");
	exit(EXIT_ERROR);
}

int	check_ber(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '.')
			if (str[i + 1] == 'b')
				if (str[i + 2] == 'e')
					if (str[i + 3] == 'r')
						if (str[i + 4] == '\0')
							return (1);
		i++;
	}
	ft_putstr_fd(RED"Erro:\n"RESET, 1);
	ft_putstr_fd(RED"-------------------------\n"RESET, 1);
	ft_putstr_fd(RED"The file must be .ber\n"RESET, 1);
	put_error_message("-------------------------\n");
	return (0);
}
