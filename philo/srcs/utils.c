/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 20:24:13 by jimpark           #+#    #+#             */
/*   Updated: 2023/04/16 20:11:07 by jimpark          ###   ########.fr       */
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

void	print_philo_status(t_philo *philo, char *str)
{
	long long	time;

	time = get_current_time();
	printf("%lld %d %s\n", time - philo->start_time, philo->id, str);
}

long long	get_current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((long long)time.tv_sec * 1000 + (long long)time.tv_usec / 1000);
}

void	wait_action_time(int time_to_action)
{
	long long	start;
	long long	now;

	start = get_current_time();
	while (1)
	{
		usleep(1000);
		now = get_current_time();
		if ((now - start) >= (long long)time_to_action)
			break ;
	}
}


