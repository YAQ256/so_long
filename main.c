/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cyacoub- <cyacoub-@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/08 18:13:30 by cyacoub-          #+#    #+#             */
/*   Updated: 2022/12/20 15:37:56 by cyacoub-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx/mlx.h"
#include <stdio.h>
#include <stdlib.h>
# define KEY_ESC        53
# define KEY_W          13
# define KEY_A          0
# define KEY_S          1
# define KEY_D          2
# define SLIME			100
/* # define slime_pos_x	100
# define slime_pos_y	100 */

typedef struct	s_vars {
	void	*mlx;
	void	*win;
	int		slime_pos_x;
	int		slime_pos_y;
}				t_vars;

typedef struct i_param {
	void	*img;
	void	*negro;
	int		img_width;
	int		img_height;
}				t_param;

/* typedef struct s_move {
	void	*up;
	void	*right;
	void	*left;
	void	*down;
}				t_move; */

/* int	keypress(int keycode, t_vars *vars)
{
	//printf("%d\n", keycode);
	return (0);
} */

int	keypress(int keycode, t_vars *vars)
{
	if (keycode == 53)
	{
		mlx_destroy_window(vars->mlx, vars->win);
		exit(0);
	}
	t_param	img;
	img.img = mlx_xpm_file_to_image (vars->mlx, "/Users/cyacoub-/Desktop/so_long/charmander.xpm", &img.img_width, &img.img_height);
	img.negro = mlx_xpm_file_to_image (vars->mlx, "/Users/cyacoub-/Desktop/so_long/negro.xpm", &img.img_width, &img.img_height);
	if (keycode == 13)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, img.negro, vars->slime_pos_x, vars->slime_pos_y);
		mlx_put_image_to_window(vars->mlx, vars->win, img.img, vars->slime_pos_x, vars->slime_pos_y - SLIME);
		vars->slime_pos_y -= SLIME;
	}
	if (keycode == 1)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, img.negro, vars->slime_pos_x, vars->slime_pos_y);
		mlx_put_image_to_window(vars->mlx, vars->win, img.img, vars->slime_pos_x, vars->slime_pos_y + SLIME);
		vars->slime_pos_y = vars->slime_pos_y + SLIME;
	}
	if (keycode == 0)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, img.negro, vars->slime_pos_x, vars->slime_pos_y);
		mlx_put_image_to_window(vars->mlx, vars->win, img.img, vars->slime_pos_x - SLIME, vars->slime_pos_y);
		vars->slime_pos_x = vars->slime_pos_x - SLIME;
	}
	if (keycode == 2)
	{
		mlx_put_image_to_window(vars->mlx, vars->win, img.negro, vars->slime_pos_x, vars->slime_pos_y);
		mlx_put_image_to_window(vars->mlx, vars->win, img.img, vars->slime_pos_x + SLIME, vars->slime_pos_y);
		vars->slime_pos_x = vars->slime_pos_x + SLIME;
	}
	return (0);
}

int	redcross(t_vars *vars)
{
	mlx_destroy_window(vars->mlx, vars->win);
	exit(0);
	return (0);
}

/* int	detectmouse(int x, int y, t_vars *vars)
{
	(void) vars;
	printf("x = %d y = %d\n", x, y);
	return (0);
} */

int	main(void)
{
	t_vars	vars;
	t_param	img;
	vars.slime_pos_x = 100;
	vars.slime_pos_y = 100;
	
	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, 1920, 1080, "Juego Pre-Alpha");
	//mlx_hook(vars.win, 4, 1L<<1, keypress, &vars);
	//mlx_hook(vars.win, 4, 1L<<1, move, &vars);
	//mlx_hook(vars.win, 6, 0, detectmouse, &vars);
	img.img = mlx_xpm_file_to_image (vars.mlx, "/Users/cyacoub-/Desktop/so_long/charmander.xpm", &img.img_width, &img.img_height);
	//mlx_loop_hook(vars.mlx, render_next_frame, up);
	mlx_put_image_to_window(vars.mlx, vars.win, img.img, 100, 100);
	mlx_hook(vars.win, 17, 0, redcross, &vars);
	mlx_key_hook(vars.win, keypress, &vars);
	//mlx_key_hook(vars.win, move, &vars);
	mlx_loop(vars.mlx);
}
