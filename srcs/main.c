/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 10:57:24 by mderome           #+#    #+#             */
/*   Updated: 2021/11/30 11:25:20 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_vars(t_vars *vars)
{
	free(vars->win);
	free(vars->mlx);
	free_map(vars);
}

void	init_image(void *mlx, t_vars *vars)
{
	int	img_width;
	int	img_height;

	vars->wall = mlx_xpm_file_to_image(mlx, "./images/wall_50px.xpm",
			&img_width, &img_height);
	vars->ground = mlx_xpm_file_to_image(mlx, "./images/sable_50.xpm",
			&img_width, &img_height);
	vars->chara = mlx_xpm_file_to_image(mlx, "./images/sable_pla.xpm",
			&img_width, &img_height);
	vars->collect = mlx_xpm_file_to_image(mlx, "./images/sable_coll_1.xpm",
			&img_width, &img_height);
	vars->exit2 = mlx_xpm_file_to_image(mlx, "./images/sable_doo.xpm",
			&img_width, &img_height);
}

int	close_win(t_vars *vars)
{
	mlx_destroy_image(vars->mlx, vars->wall);
	mlx_destroy_image(vars->mlx, vars->chara);
	mlx_destroy_image(vars->mlx, vars->collect);
	mlx_destroy_image(vars->mlx, vars->exit2);
	mlx_destroy_image(vars->mlx, vars->ground);
	mlx_destroy_window(vars->mlx, vars->win);
	mlx_destroy_display(vars->mlx);
	free(vars->mlx);
	free_map(vars);
	exit (EXIT_SUCCESS);
}

int	close_windows(int keycode, t_vars *vars)
{
	if (keycode == ESC)
		close_win(vars);
	else
		check_moove(keycode, vars);
	return (0);
}

int	main(int ac, char **av)
{
	t_vars	vars;

	vars.map = NULL;
	init_struct(&vars);
	if (check_map(av[ac - 1], &vars) == -1)
	{
		print_error_map(&vars);
		free_map(&vars);
		return (-1);
	}
	vars.mlx = mlx_init();
	init_image(vars.mlx, &vars);
	vars.win = mlx_new_window(vars.mlx, ((vars.x + 1) * 50),
			(vars.y * 50), "so_long");
	put_map(&vars, vars.mlx, vars.win);
	put_obj(&vars, vars.mlx, vars.win);
	mlx_hook(vars.win, 33, 131072, &close_win, &vars);
	mlx_hook(vars.win, 2, 1L << 0, close_windows, &vars);
	mlx_loop(vars.mlx);
	return (0);
}
