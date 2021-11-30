/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 12:08:25 by mderome           #+#    #+#             */
/*   Updated: 2021/10/12 13:20:13 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	is_end_line(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (i);
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

int	find_next_line(char *s)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == '\n')
		i++;
	return (i);
}

char	*ft_strjoin_gnl(char *s1, char *s2, int ret)
{
	char	*res;
	int		length;
	int		i;
	int		j;

	if (!s1 && !s2)
		return (NULL);
	s2[ret] = '\0';
	length = ft_strlen(s1) + ft_strlen(s2) + 1;
	res = malloc(sizeof(char) * length);
	if (!res)
		return (NULL);
	i = 0;
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = -1;
	while (s2 && s2[++j])
		res[i + j] = s2[j];
	res[i + j] = '\0';
	free(s1);
	return (res);
}
