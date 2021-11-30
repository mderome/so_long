/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <mderome@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/22 12:09:05 by mderome           #+#    #+#             */
/*   Updated: 2021/10/12 13:14:52 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*get_line(char *s)
{
	char	*res;
	int		i;

	if (!s)
		return (NULL);
	i = find_next_line(s);
	if (i == 0)
		return (NULL);
	res = malloc(sizeof(char) * (i + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		res[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		res[i] = s[i];
		i++;
	}
	res[i] = '\0';
	return (res);
}

char	*get_save(char *s)
{
	char	*res;
	int		i;
	int		j;

	i = 0;
	while (s[i] && s[i] != '\n')
		i++;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	res = malloc(sizeof(char) * (ft_strlen(s) - i + 1));
	if (!res)
		return (NULL);
	i++;
	j = 0;
	while (s && s[i])
		res[j++] = s[i++];
	res[j] = '\0';
	free(s);
	return (res);
}

char	*get_next_line(int fd)
{
	char		*buffer;
	static char	*save[256];
	char		*line;
	int			ret;

	if (fd < 0 || fd > 256 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!buffer)
		return (NULL);
	ret = 1;
	while (!is_end_line(save[fd]) && ret != 0)
	{
		ret = read(fd, buffer, BUFFER_SIZE);
		if (ret < 0)
		{
			free(buffer);
			return (NULL);
		}
		save[fd] = ft_strjoin_gnl(save[fd], buffer, ret);
	}
	free(buffer);
	line = get_line(save[fd]);
	save[fd] = get_save(save[fd]);
	return (line);
}
