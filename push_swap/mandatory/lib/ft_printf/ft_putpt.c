/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putpt.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:17:41 by jimpark           #+#    #+#             */
/*   Updated: 2022/12/23 03:47:38 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putpt(void *point)
{
	int					len;
	unsigned long long	pt;
	char				*result;

	pt = (unsigned long long) point;
	len = ft_hexlen(pt);
	if (write(1, "0x", 2) == -1)
		return (-1);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (-1);
	result[len--] = '\0';
	while (len >= 0)
	{
		result[len--] = "0123456789abcdef"[pt % 16];
		pt = pt / 16;
	}
	len = ft_putstr(result) + 2;
	free (result);
	return (len);
}
