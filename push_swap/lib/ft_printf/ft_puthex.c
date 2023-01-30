/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:17:40 by jimpark           #+#    #+#             */
/*   Updated: 2022/12/23 03:47:37 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_puthex(unsigned int hexnbr, char type)
{
	int			len;
	char		*result;

	len = ft_hexlen(hexnbr);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (-1);
	result[len--] = '\0';
	while (len >= 0)
	{
		if (type == 'x')
			result[len--] = "0123456789abcdef"[hexnbr % 16];
		if (type == 'X')
			result[len--] = "0123456789ABCDEF"[hexnbr % 16];
		hexnbr = hexnbr / 16;
	}
	len = ft_putstr(result);
	free (result);
	return (len);
}
