/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 17:03:32 by jimpark           #+#    #+#             */
/*   Updated: 2022/11/11 19:38:01 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

size_t	ft_strlcpy(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	res;

	i = 0;
	res = ft_strlen(src);
	if (dstsize == 0)
		return (res);
	while ((src[i] != '\0') && (i < dstsize - 1))
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (res);
}

size_t	ft_strlcat(char *dst, char *src, size_t dstsize)
{
	size_t	i;
	size_t	dst_len;
	size_t	src_len;

	i = 0;
	if (!dst)
		dst_len = 0;
	else
		dst_len = ft_strlen(dst);
	src_len = ft_strlen(src);
	if (dstsize > dst_len)
	{
		while ((src[i] != '\0') && (i < dstsize - dst_len - 1))
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[dst_len + i] = '\0';
		return (dst_len + src_len);
	}
	return (dstsize + src_len);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	size_t	s1_size;
	size_t	s2_size;

	if (!s1 && !s2)
		return (0);
	if (!s1)
	{
		joined = ft_strdup(s2);
		if (!joined)
			return (0);
		return (joined);
	}
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	joined = (char *)malloc(sizeof(char) * (s1_size + s2_size + 1));
	if (!joined)
		return (0);
	ft_strlcpy(joined, s1, s1_size + s2_size + 1);
	ft_strlcat(joined, s2, s1_size + s2_size + 1);
	free (s1);
	return (joined);
}

char	*ft_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)&s[i]);
		i++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (0);
}
