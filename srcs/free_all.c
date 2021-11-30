/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 10:04:45 by mderome           #+#    #+#             */
/*   Updated: 2021/11/29 09:39:10 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_image(t_vars *vars)
{
	free(vars->ground);
	free(vars->chara);
	free(vars->collect);
	free(vars->wall);
	free(vars->exit2);
}
