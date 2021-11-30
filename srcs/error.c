/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/29 09:20:15 by mderome           #+#    #+#             */
/*   Updated: 2021/11/29 10:47:29 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_check(t_vars *vars)
{
	if (vars->fail_wall != 0)
	{
		vars->fail = 10;
		return (-1);
	}
	else if (vars->exit != 1)
	{
		vars->fail = 11;
		return (-2);
	}
	else if (vars->player != 1)
	{
		vars->fail = 12;
		return (-3);
	}
	else if (vars->collec < 1)
	{
		vars->fail = 13;
		return (-4);
	}
	return (0);
}

void	print_error_map(t_vars *vars)
{
	if (vars->fail == 10)
	{
		ft_putstr_fd("Error\nWrong map format : ", 2);
		ft_putstr_fd("map not close.\n", 2);
	}
	if (vars->fail == 11)
	{
		ft_putstr_fd("Error\nWrong map format : ", 2);
		ft_putstr_fd("need one exit.\n", 2);
	}
	if (vars->fail == 12)
	{
		ft_putstr_fd("Error\nWrong map format : ", 2);
		ft_putstr_fd("we need one players.\n", 2);
	}
	if (vars->fail == 13)
	{
		ft_putstr_fd("Error\nWrong map format : ", 2);
		ft_putstr_fd("not found collectible.\n", 2);
	}
}
