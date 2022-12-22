/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/22 23:23:28 by jimpark           #+#    #+#             */
/*   Updated: 2022/12/23 03:47:40 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_nbrlen(long long n)
{
	int	i;

	i = 0;
	if (n < 0)
	{
		n *= -1;
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

int	ft_unbrlen(unsigned int n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		++i;
		n = n / 10;
	}
	return (i);
}

int	ft_hexlen(unsigned long long n)
{
	int	i;

	i = 0;
	if (n == 0)
		return (1);
	while (n > 0)
	{
		++i;
		n = n / 16;
	}
	return (i);
}
