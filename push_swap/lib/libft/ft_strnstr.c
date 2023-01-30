/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/19 18:50:27 by jimpark           #+#    #+#             */
/*   Updated: 2023/01/30 16:43:49 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(char *haystack, char *needle, size_t len)
{
	size_t	h;
	size_t	n;
	size_t	check;

	h = 0;
	if (!haystack && needle && !len)
		return (0);
	if (!(*needle))
		return ((char *)haystack);
	while (haystack[h] != '\0' && h < len)
	{
		n = 0;
		check = h;
		while (haystack[h] == needle[n] && needle[n] && haystack[h] && h < len)
		{
			h++;
			n++;
		}
		if (needle[n] == '\0')
			return ((char *)&haystack[check]);
		h = check;
		h++;
	}
	return (0);
}
