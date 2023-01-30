/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 19:15:37 by jimpark           #+#    #+#             */
/*   Updated: 2023/01/30 16:26:37 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char *s1, char *set)
{
	int		start;
	int		end;
	char	*newstr;

	if (!s1)
		return (0);
	if (!set)
		return (ft_strdup(s1));
	start = 0;
	end = ft_strlen(s1) - 1;
	while (ft_strchr(set, s1[start]) != 0 && s1[start] != '\0')
		++start;
	while (ft_strchr(set, s1[end]) != 0 && start < end)
		--end;
	newstr = (char *)malloc(sizeof(char) * (end - start + 2));
	if (!newstr)
		return (0);
	ft_strlcpy(newstr, &s1[start], end - start + 2);
	return (newstr);
}
