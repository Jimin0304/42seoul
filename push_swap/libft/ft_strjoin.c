/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 18:44:07 by jimpark           #+#    #+#             */
/*   Updated: 2023/01/30 16:43:20 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char *s1, char *s2)
{
	char	*joined;
	size_t	s1_size;
	size_t	s2_size;

	if (!s1 || !s2)
		return (0);
	s1_size = ft_strlen(s1);
	s2_size = ft_strlen(s2);
	joined = (char *)malloc(sizeof(char) * (s1_size + s2_size + 1));
	if (!joined)
		return (0);
	ft_strlcpy(joined, s1, s1_size + s2_size + 1);
	ft_strlcat(joined, s2, s1_size + s2_size + 1);
	return (joined);
}
