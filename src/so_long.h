/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/15 19:02:24 by cyacoub-          #+#    #+#             */
/*   Updated: 2023/02/23 19:50:47 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include "../libft/libft.h"

# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>

# define KEY_ESC			53
# define KEY_W				13
# define KEY_A				0
# define KEY_S				1
# define KEY_D				2
# define ARROW_UP			126
# define ARROW_DOWN			125
# define ARROW_LEFT			123
# define ARROW_RIGHT		124
# define DESTROY_NOTIFY		17

# define PLAYER				32
# define EXIT_ERROR			1

typedef struct s_player
{
	void	*player_right;
	void	*player_right_1;
	int		player_right_1_flg;
	void	*player_left;
	void	*player_left_1;
	int		player_left_1_flg;
	void	*player_back;
	int		steps;
	int		steps_flg;
}				t_player;

typedef struct s_map
{
	char	*line;
	int		height;
	int		width;
	void	*cell;
	void	*wall;
	void	*potion_img;
	int		potion;
	int		all_potion;
	void	*exit;
	char	**copymap;
}				t_map;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			img_height;
	int			img_width;
	t_player	player;
	t_map		map;
}				t_game;

void	player_xpm(t_game *game);
void	map_xpm(t_game *game);
void	sprites_xpm(t_game *game);
void	read_map(t_game *game, char *str);
void	write_map_w(t_game *game);
void	write_map_a(t_game *game);
void	write_map_s(t_game *game);
void	write_map_d(t_game *game);
void	end_game(t_game *game);
void	move_w(t_game *game);
int		redcross(t_game *game);
int		press_key(int key_code, t_game *game);
int		t_win_steps(t_game *game);
void	check_map(t_game *game);
void	check_map2(t_game *game);
void	put_rocks_exit(t_game *game, int j, int i, int k);
void	put_potions(t_game *game, int j, int i);
void	put_player_back(t_game *game, int j, int i);
void	put_player_right(t_game *game, int j, int i);
void	put_player_left(t_game *game, int j, int i);
void	put_error_message(char *str);
int		search_route_exit(t_game *game);
void	put_invalid_path(void);
void	check_rectangular(char *line, t_game *game);
void	check_unrecognized(char *line);
int		check_ber(char *str);
void	xpm_error(void);
void	win_game(t_game *game);
void	lost_game(t_game *game);
void	check_nmax_elements_utis(int e, int p);

//===SETTINGS 	COLORS===/
//===Color font code===/
# define BLACK   "\x1B[30m"
# define RED     "\x1b[31m"
# define GREEN   "\x1b[32m"
# define YELLOW  "\x1b[33m"
# define BLUE    "\x1b[34m"
# define MAGENTA "\x1b[35m"
# define CYAN    "\x1b[36m"
# define WHITE   "\x1B[37m"
# define ORANGE  "\x1B[38;2;255;128;0m"
# define ROSE    "\x1B[38;2;255;151;203m"
# define LBLUE   "\x1B[38;2;53;149;240m"
# define LGREEN  "\x1B[38;2;17;245;120m"
# define GRAY    "\x1B[38;2;176;174;174m"
# define RESET   "\x1b[0m"
//===Color background code===/
# define BG_BLACK   "\x1B[40m"
# define BG_RED     "\x1B[41m"
# define BG_GREEN   "\x1B[42m"
# define BG_YELLOW  "\x1B[43m"
# define BG_BLUE    "\x1B[44m"
# define BG_MAGENTA "\x1B[45m"
# define BG_CYAN    "\x1B[46m"
# define BG_WHITE   "\x1B[47m"
# define BG_ORANGE  "\x1B[48;2;255;128;0m"
# define BG_LBLUE   "\x1B[48;2;53;149;240m"
# define BG_LGREEN  "\x1B[48;2;17;245;120m"
# define BG_GRAY    "\x1B[48;2;176;174;174m"
# define BG_ROSE    "\x1B[48;2;255;151;203m"

#endif