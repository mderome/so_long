/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/10 17:04:02 by mderome           #+#    #+#             */
/*   Updated: 2021/11/29 10:31:12 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_fl_line(t_vars *vars, int pos)
{
	int	i;

	i = 0;
	while (vars->map[pos][i] && vars->map[pos][i] != '\n')
	{
		if (vars->map[pos][i] != '1')
			return (-1);
		i++;
	}
	return (0);
}

int	check_o_line(t_vars *vars, int pos)
{
	int	i;

	i = 0;
	while (vars->map[pos][i] && vars->map[pos][i] != '\n')
	{
		if (vars->map[pos][0] != '1')
			return (-1);
		else
		{
			check_obj(vars, pos, i);
			if (vars->map[pos][i + 1] == '\0' ||
				vars->map[pos][i + 1] == '\n')
			{
				if (vars->map[pos][i] != '1')
					return (-2);
			}
			else
				if (vars->map[pos][0] != '1' && vars->map[pos][i] != '0')
					return (-3);
		}
		i++;
	}
	vars->x = i - 1;
	return (0);
}

void	check_line(t_vars *vars)
{
	int	i;
	int	len_max;

	i = 0;
	len_max = ft_len_tab(vars);
	while (i < len_max)
	{
		if (i == 0 || i == (len_max - 1))
		{
			if (check_fl_line(vars, i) < 0)
				vars->fail_wall += 1;
		}
		else
		{
			if (check_o_line(vars, i) < 0)
			{
				vars->fail_wall += 1;
			}
		}
		i++;
	}
}

void	init_struct(t_vars *vars)
{
	vars->collec = 0;
	vars->exit = 0;
	vars->player = 0;
	vars->fail = 0;
	vars->fail_wall = 0;
	vars->take_collect = 0;
	vars->nb_hook = 0;
	vars->nb_to_print = NULL;
}

int	parsing_map(t_vars *vars)
{
	check_line(vars);
	if (check_check(vars) < 0)
	{
		return (-1);
	}
	return (0);
}
