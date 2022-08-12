/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 20:22:01 by jimpark           #+#    #+#             */
/*   Updated: 2022/08/03 05:22:13 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	char	c;

	if (fd < 0)
		return ;
	if (n == -2147483648)
		write(fd, "-2147483648", 11);
	else
	{
		if (n > 9)
			ft_putnbr_fd(n / 10, fd);
		else if ((-9 <= n) && (n < 0))
		{
			n = -n;
			write(fd, "-", 1);
		}
		else if (-9 > n)
		{
			n = -n;
			write(fd, "-", 1);
			ft_putnbr_fd(n / 10, fd);
		}
		c = n % 10 + '0';
		write(fd, &c, 1);
	}
}
