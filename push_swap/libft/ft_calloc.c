/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/20 18:01:08 by jimpark           #+#    #+#             */
/*   Updated: 2022/08/10 13:41:33 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;

	if ((size != 0) && (count > SIZE_MAX / size))
		return (0);
	str = malloc(sizeof(char) * (count * size));
	if (!str)
		return (0);
	ft_bzero(str, count * size);
	return ((void *)str);
}
