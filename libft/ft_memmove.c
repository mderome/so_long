/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mderome <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/14 11:01:30 by mderome           #+#    #+#             */
/*   Updated: 2021/06/14 11:01:31 by mderome          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t			i;
	unsigned char	*dest2;
	unsigned char	*src2;

	i = 0;
	src2 = (unsigned char *)src;
	dest2 = (unsigned char *)dest;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (src2 < dest2)
		while (++i <= n)
			dest2[n - i] = src2[n - i];
	else
		while (n-- > 0)
			*(dest2++) = *(src2++);
	return (dest);
}
