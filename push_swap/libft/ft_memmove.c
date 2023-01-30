/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 13:29:20 by jimpark           #+#    #+#             */
/*   Updated: 2023/01/30 21:12:54 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, void *src, size_t len)
{
	size_t			i;
	unsigned char	*d;
	unsigned char	*s;

	i = 0;
	if (!dst && !src)
		return (0);
	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (dst <= src)
	{
		while (i < len)
		{
			d[i] = s[i];
			i++;
		}
	}
	else
	{
		i = i + len;
		while (i--)
			d[i] = s[i];
	}
	return (dst);
}
