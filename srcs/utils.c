/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 09:29:44 by mderome           #+#    #+#             */
/*   Updated: 2021/11/29 09:39:55 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_obj(t_vars *vars, int pos_x, int pos_y)
{
	if (vars->map[pos_x][pos_y] == 'P')
	{
		vars->player += 1;
		vars->pos_p_x = pos_x;
		vars->pos_p_y = pos_y;
	}
	else if (vars->map[pos_x][pos_y] == 'C')
		vars->collec += 1;
	else if (vars->map[pos_x][pos_y] == 'E')
		vars->exit += 1;
}
