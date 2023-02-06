/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 18:44:07 by jimpark           #+#    #+#             */
/*   Updated: 2023/02/06 19:00:59 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
