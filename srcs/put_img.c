/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_img.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 09:35:59 by mderome           #+#    #+#             */
/*   Updated: 2021/11/30 11:50:17 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_moov(t_vars *vars, void *mlx, void *mlx_win, int moove)
{
	mlx_put_image_to_window(mlx, mlx_win, vars->chara,
		vars->pos_p_y * 50, vars->pos_p_x * 50);
	mlx_put_image_to_window(mlx, mlx_win, vars->wall,
		0 * 50, 0 * 50);
	if (moove == UP)
	{
		mlx_put_image_to_window(mlx, mlx_win, vars->ground,
			vars->pos_p_y * 50, (vars->pos_p_x + 1) * 50);
	}
	else if (moove == DOWN)
	{
		mlx_put_image_to_window(mlx, mlx_win, vars->ground,
			vars->pos_p_y * 50, (vars->pos_p_x - 1) * 50);
	}
	else if (moove == RIGHT)
	{
		mlx_put_image_to_window(mlx, mlx_win, vars->ground,
			(vars->pos_p_y - 1) * 50, vars->pos_p_x * 50);
	}
	else if (moove == LEFT)
	{
		mlx_put_image_to_window(mlx, mlx_win, vars->ground,
			(vars->pos_p_y + 1) * 50, vars->pos_p_x * 50);
	}
}

void	put_map(t_vars *vars, void *mlx, void *mlx_win)
{
	int	i;
	int	j;

	j = 0;
	while (j < vars->y)
	{
		i = 0;
		while (i <= vars->x)
		{
			if (vars->map[j][i] == '1')
			{
				mlx_put_image_to_window(mlx, mlx_win, vars->wall,
					i * 50, j * 50);
			}
			else
				mlx_put_image_to_window(mlx, mlx_win, vars->ground,
					i * 50, j * 50);
			i++;
		}
		j++;
	}
}

void	put_obj(t_vars *vars, void *mlx, void *mlx_win)
{
	int	i;
	int	j;

	j = 0;
	while (j < vars->y)
	{
		i = 0;
		while (i <= vars->x)
		{
			if (vars->map[j][i] == 'C')
				mlx_put_image_to_window(mlx, mlx_win, vars->collect,
					i * 50, j * 50);
			else if (vars->map[j][i] == 'P')
			{
				mlx_put_image_to_window(mlx, mlx_win, vars->chara,
					i * 50, j * 50);
			}
			else if (vars->map[j][i] == 'E')
				mlx_put_image_to_window(mlx, mlx_win, vars->exit2,
					i * 50, j * 50);
			i++;
		}
		j++;
	}
}
