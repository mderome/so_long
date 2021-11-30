/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/08 09:22:42 by mderome           #+#    #+#             */
/*   Updated: 2021/11/29 11:26:34 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_len_tab(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map && vars->map[i])
		i++;
	return (i);
}

void	free_map(t_vars *vars)
{
	int	i;

	i = 0;
	while (vars->map && vars->map[i])
	{
		free(vars->map[i]);
		i++;
	}
	free(vars->map);
}

void	stock_map(char *file, t_vars *vars)
{
	int		fd;
	char	tmp[50001];
	int		ret;

	fd = open(file, O_RDONLY);
	ret = read(fd, tmp, 50000);
	tmp[ret] = '\0';
	vars->map = ft_split(tmp, '\n');
	close(fd);
}

int	check_file(char *file)
{
	int	i;
	int	j;

	i = 1;
	j = 1;
	while (ft_strncmp(file + j, "/.", 2) != 0)
		j++;
	while (file[i] && file[i] != '.')
		i++;
	if (ft_strlen(file + j) == 5 || ft_strncmp(file + i, ".ber", 5) != 0)
		return (-1);
	return (0);
}

int	check_map(char *file, t_vars *vars)
{
	if (access(file, F_OK | R_OK))
	{
		ft_putstr_fd("Error\nMap not found.\n", 2);
		return (-1);
	}
	if (check_file(file) != 0)
	{
		ft_putstr_fd("Error\nWrong map format.\n", 2);
		return (-1);
	}
	stock_map(file, vars);
	if (vars->map == NULL)
		return (-1);
	vars->y = ft_len_tab(vars);
	if (parsing_map(vars) < 0)
		return (-1);
	return (0);
}
