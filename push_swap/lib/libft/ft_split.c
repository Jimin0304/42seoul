/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 20:11:04 by jimpark           #+#    #+#             */
/*   Updated: 2023/01/28 23:12:49 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	cmp(char s, char c)
{
	if (s == c)
		return (0);
	else
		return (-1);
}

int	word_count(char *s, char c)
{
	int	i;
	int	cnt;

	i = 0;
	cnt = 0;
	if (!s)
		return (0);
	while (s[i])
	{
		while (s[i] != '\0' && cmp(s[i], c) == 0)
			i++;
		if (s[i] != '\0' && cmp(s[i], c) != 0)
			cnt++;
		while (s[i] != '\0' && cmp(s[i], c) != 0)
			i++;
	}
	return (cnt);
}

static void	free_all(char **result, int r)
{
	int	i;

	i = 0;
	while (i <= r)
	{
		free(result[i]);
		i++;
	}
	free(result);
	return ;
}

static int	word_print(char *s, char c, int check, char **result)
{
	int	i;
	int	r;

	i = 0;
	r = 0;
	while (s[i])
	{
		while (s[i] != '\0' && cmp(s[i], c) == 0)
			i++;
		check = i;
		while (s[i] != '\0' && cmp(s[i], c) != 0)
			i++;
		if (check == i)
			break ;
		result[r] = (char *)malloc(sizeof(char) * (i - check + 1));
		if (!(result[r]))
		{
			free_all(result, r);
			return (1);
		}
		ft_strlcpy(result[r], &s[check], i - check + 1);
		r++;
	}
	result[r] = NULL;
	return (0);
}

char	**ft_split(char *s, char c)
{
	char	**result;
	int		count;

	if (!s)
		return (0);
	count = word_count(s, c);
	result = (char **)malloc(sizeof(char *) * (count + 1));
	if (!result)
		return (0);
	if (word_print(s, c, 0, result) == 1)
		return (0);
	else
		return (result);
}
