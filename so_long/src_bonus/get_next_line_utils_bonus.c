/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:08:27 by jimpark           #+#    #+#             */
/*   Updated: 2023/01/26 22:37:26 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/get_next_line.h"

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0')
		i++;
	return (i);
}

int	ft_strlcpy(char *dst, char *src, int dstsize)
{
	int	i;
	int	res;

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

int	ft_strlcat(char *dst, char *src, int dstsize)
{
	int	i;
	int	dst_len;
	int	src_len;

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
	int		s1_size;
	int		s2_size;

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
