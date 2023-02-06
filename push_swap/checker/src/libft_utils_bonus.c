/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 21:42:56 by jimpark           #+#    #+#             */
/*   Updated: 2023/02/06 22:06:58 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	ft_atoi(char *str)
{
	long long	result;
	int			pos;

	pos = 1;
	result = 0;
	if (*str == '-')
	{
		pos = -1;
		str++;
	}
	while (('0' <= *str) && (*str <= '9'))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (*str != '\0')
		return (print_err(-1));
	result *= pos;
	if ((result > 2147483647) || (result < -2147483648))
		return (print_err(-1));
	return (result);
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
