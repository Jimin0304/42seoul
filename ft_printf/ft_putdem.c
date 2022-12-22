/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putdem.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 20:17:38 by jimpark           #+#    #+#             */
/*   Updated: 2022/12/23 03:47:37 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putdem(int nbr)
{
	long long	n;
	int			len;
	char		*result;

	n = (long long)nbr;
	len = ft_nbrlen(n);
	result = (char *)malloc(sizeof(char) * (len + 1));
	if (!result)
		return (-1);
	if (n < 0)
		n *= -1;
	result[len--] = '\0';
	while (len >= 0)
	{
		result[len--] = "0123456789"[n % 10];
		n = n / 10;
	}
	if (nbr < 0)
		result[0] = '-';
	len = ft_putstr(result);
	free(result);
	return (len);
}
