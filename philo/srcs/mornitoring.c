/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mornitoring.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:33:20 by jimpark           #+#    #+#             */
/*   Updated: 2023/05/02 22:13:18 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	check_dead_philo(t_philo *philo, t_info *info)
{
	int			i;
	long long	now;

	i = 0;
	while (i < info->n_philo)
	{
		pthread_mutex_lock(&info->m_action);
		now = get_current_time();
		if (now - philo[i].last_eat_time >= (long long)info->die)
		{
			printf("\033[0;3%dm%lld %d died\033[0m\n", 1, \
				now - philo[i].start_time, philo[i].id);
			info->finish = 1;
			pthread_mutex_unlock(&info->m_action);
			return (1);
		}
		pthread_mutex_unlock(&info->m_action);
		i++;
	}
	return (0);
}

void	mornitoring_philo(t_philo *philo, t_info *info)
{
	while (1)
	{
		if (check_dead_philo(philo, info))
			break ;
		pthread_mutex_lock(&info->m_action);
		if ((info->argc == 6) && (info->full_philo == info->n_philo))
		{
			info->finish = 1;
			pthread_mutex_unlock(&info->m_action);
			break ;
		}
		pthread_mutex_unlock(&info->m_action);
		usleep(10);
	}
}
