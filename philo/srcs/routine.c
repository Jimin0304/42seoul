/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:36:32 by jimpark           #+#    #+#             */
/*   Updated: 2023/05/02 18:02:50 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	join_thread(t_philo *philo, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n_philo)
		pthread_join(philo[i++].thread, NULL);
}

int	check_philosophers(t_philo *philo)
{
	int	ret;

	ret = 0;
	pthread_mutex_lock(&philo->info->m_action);
	if (philo->info->finish)
		ret = 1;
	else if ((philo->info->argc == 6) && (philo->n_eat == philo->info->count))
	{
		philo->info->full_philo++;
		ret = 1;
	}
	pthread_mutex_unlock(&philo->info->m_action);
	return (ret);
}

void	one_philo_action(t_philo *philo)
{
	check_dead_philo(philo, philo->info);
	pthread_mutex_lock(&philo->l_fork);
	print_philo_status(philo, "has taken a fork", 3);
	pthread_mutex_lock(&philo->info->m_action);
	philo->last_eat_time = get_current_time();
	pthread_mutex_unlock(&philo->info->m_action);
	wait_action_time(philo->info->eat);
	pthread_mutex_unlock(&philo->l_fork);
}

void	*action(void *argv)
{
	t_philo	*philo;

	philo = (t_philo *)argv;
	if (philo->info->n_philo == 1)
	{
		one_philo_action(philo);
		return (NULL);
	}
	if (philo->id % 2 == 0)
		wait_action_time(philo->info->eat / 10);
	while (1)
	{
		if (check_philosophers(philo))
			break ;
		philo_eat(philo);
		if (check_philosophers(philo))
			break ;
		philo_sleep(philo);
		if (check_philosophers(philo))
			break ;
		philo_think(philo);
	}
	return (NULL);
}

int	start_philo(t_philo *philo, t_info *info)
{
	int			i;
	long long	time;

	time = get_current_time();
	i = 0;
	while (i < info->n_philo)
	{
		philo[i].start_time = time;
		philo[i].last_eat_time = time;
		if (pthread_create(&philo[i].thread, NULL, action, &philo[i]))
			return (1);
		i++;
	}
	mornitoring_philo(philo, info);
	join_thread(philo, info);
	return (0);
}
