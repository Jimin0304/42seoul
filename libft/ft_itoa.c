/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:19:34 by jimpark           #+#    #+#             */
/*   Updated: 2022/08/03 21:49:53 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	itoa_numlen(long long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n = -n;
		++i;
	}
	else if (n == 0)
		return (1);
	while (n > 0)
	{
		++i;
		n = n / 10;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	long long	nbr;
	int			num_len;
	int			neg;
	char		*res;

	nbr = (long long)n;
	num_len = itoa_numlen(nbr);
	neg = 0;
	res = (char *)malloc(sizeof(char) * (num_len + 1));
	if (!res)
		return (0);
	if (nbr < 0)
	{
		neg = 1;
		nbr = -nbr;
	}
	res[num_len--] = '\0';
	while (num_len >= 0)
	{
		res[num_len--] = "0123456789"[nbr % 10];
		nbr = nbr / 10;
	}
	if (neg == 1)
		res[0] = '-';
	return (res);
}
