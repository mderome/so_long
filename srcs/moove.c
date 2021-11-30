/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moove.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 11:35:39 by mderome           #+#    #+#             */
/*   Updated: 2021/11/30 11:33:03 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	moove_up(t_vars *vars)
{
	if (vars->map[vars->pos_p_x - 1][vars->pos_p_y] != '1')
	{
		if (vars->map[vars->pos_p_x - 1][vars->pos_p_y] == 'C')
			vars->take_collect += 1;
		if (vars->map[vars->pos_p_x - 1][vars->pos_p_y] == 'E'
			&& vars->take_collect != vars->collec)
			return ;
		if (vars->map[vars->pos_p_x - 1][vars->pos_p_y] == 'E'
			&& vars->take_collect == vars->collec)
		{
			close_win(vars);
			return ;
		}
		vars->map[vars->pos_p_x - 1][vars->pos_p_y] = 'P';
		vars->map[vars->pos_p_x][vars->pos_p_y] = '0';
		vars->pos_p_x -= 1;
		vars->nb_hook += 1;
		vars->nb_to_print = ft_itoa(vars->nb_hook);
		put_moov(vars, vars->mlx, vars->win, UP);
		mlx_string_put(vars->mlx, vars->win, 0 * 50, 1 * 50, 0x0000FF00,
			vars->nb_to_print);
	}
	free(vars->nb_to_print);
	return ;
}

void	moove_down(t_vars *vars)
{
	if (vars->map[vars->pos_p_x + 1][vars->pos_p_y] != '1')
	{
		if (vars->map[vars->pos_p_x + 1][vars->pos_p_y] == 'C')
			vars->take_collect += 1;
		if (vars->map[vars->pos_p_x + 1][vars->pos_p_y] == 'E'
			&& vars->take_collect != vars->collec)
			return ;
		if (vars->map[vars->pos_p_x + 1][vars->pos_p_y] == 'E'
			&& vars->take_collect == vars->collec)
		{
			close_win(vars);
			return ;
		}
		vars->map[vars->pos_p_x + 1][vars->pos_p_y] = 'P';
		vars->map[vars->pos_p_x][vars->pos_p_y] = '0';
		vars->pos_p_x += 1;
		vars->nb_hook += 1;
		vars->nb_to_print = ft_itoa(vars->nb_hook);
		put_moov(vars, vars->mlx, vars->win, DOWN);
		mlx_string_put(vars->mlx, vars->win, 0 * 50, 1 * 50, 0x0000FF00,
			vars->nb_to_print);
	}
	free(vars->nb_to_print);
	return ;
}

void	moove_right(t_vars *vars)
{
	if (vars->map[vars->pos_p_x][vars->pos_p_y + 1] != '1')
	{
		if (vars->map[vars->pos_p_x][vars->pos_p_y + 1] == 'C')
			vars->take_collect += 1;
		if (vars->map[vars->pos_p_x][vars->pos_p_y + 1] == 'E'
			&& vars->take_collect != vars->collec)
			return ;
		else if (vars->map[vars->pos_p_x][vars->pos_p_y + 1] == 'E'
			&& vars->take_collect == vars->collec)
		{
			close_win(vars);
			return ;
		}
		vars->map[vars->pos_p_x][vars->pos_p_y + 1] = 'P';
		vars->map[vars->pos_p_x][vars->pos_p_y] = '0';
		vars->pos_p_y += 1;
		vars->nb_hook += 1;
		vars->nb_to_print = ft_itoa(vars->nb_hook);
		put_moov(vars, vars->mlx, vars->win, RIGHT);
		mlx_string_put(vars->mlx, vars->win, 0 * 50, 1 * 50, 0x0000FF00,
			vars->nb_to_print);
	}
	free(vars->nb_to_print);
	return ;
}

void	moove_left(t_vars *vars)
{
	if (vars->map[vars->pos_p_x][vars->pos_p_y - 1] != '1')
	{
		if (vars->map[vars->pos_p_x][vars->pos_p_y - 1] == 'C')
			vars->take_collect += 1;
		if (vars->map[vars->pos_p_x][vars->pos_p_y - 1] == 'E'
			&& vars->take_collect != vars->collec)
			return ;
		else if (vars->map[vars->pos_p_x][vars->pos_p_y - 1] == 'E'
			&& vars->take_collect == vars->collec)
		{
			close_win(vars);
			return ;
		}
		vars->map[vars->pos_p_x][vars->pos_p_y - 1] = 'P';
		vars->map[vars->pos_p_x][vars->pos_p_y] = '0';
		vars->pos_p_y -= 1;
		vars->nb_hook += 1;
		vars->nb_to_print = ft_itoa(vars->nb_hook);
		put_moov(vars, vars->mlx, vars->win, LEFT);
		mlx_string_put(vars->mlx, vars->win, 0 * 50, 1 * 50, 0x0000FF00,
			vars->nb_to_print);
	}
	free(vars->nb_to_print);
	return ;
}

void	check_moove(int keycode, t_vars *vars)
{
	vars->nb_to_print = NULL;
	if (keycode == UP)
		moove_up(vars);
	else if (keycode == DOWN)
		moove_down(vars);
	else if (keycode == RIGHT)
		moove_right(vars);
	else if (keycode == LEFT)
	{
		moove_left(vars);
	}
	return ;
}
