/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 11:04:55 by mderome           #+#    #+#             */
/*   Updated: 2021/06/14 11:04:56 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*strend;

	if (!s)
		return (0);
	if (start < ft_strlen(s))
	{
		if (len > ft_strlen(s) - start)
			len = ft_strlen(s) - start;
		strend = malloc(sizeof(char) * (len + 1));
		if (!strend)
			return (NULL);
		strend[len] = '\0';
		while (len)
		{
			strend[len - 1] = s[start + len - 1];
			len--;
		}
		return (strend);
	}
	else
		return (ft_calloc(1, sizeof(char)));
}
