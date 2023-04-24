/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 17:36:32 by jimpark           #+#    #+#             */
/*   Updated: 2023/04/24 18:05:37 by jimpark          ###   ########.fr       */
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

void	*action(void *argv)
{
	t_philo	*philo;

	philo = (t_philo *)argv;
	if (philo->info->n_philo == 1)
		return (NULL);
	if (philo->id % 2)
		wait_action_time(philo->info->eat);
	while (1)
	{
		if (check_philosophers(philo))
			break ;
		pick_up_fork(philo);
		philo_eat(philo);
		put_down_fork(philo);
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
