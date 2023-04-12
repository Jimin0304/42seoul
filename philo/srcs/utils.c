/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:24:13 by jimpark           #+#    #+#             */
/*   Updated: 2023/04/12 20:47:49 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	ft_atoi(char *str)
{
	long long	result;

	result = 0;
	if (*str == '-')
		return (-1);
	else if (*str == '+')
		str++;
	if (*str == '\0')
		return (-1);
	while (('0' <= *str) && (*str <= '9'))
	{
		result = result * 10 + (*str - '0');
		str++;
	}
	if (*str != '\0')
		return (-1);
	if (result > 2147483647)
		return (-1);
	return (result);
}

int	print_err(char *error_msg)
{
	printf("Error: %s\n", error_msg);
	return(-1);
}
