/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   action.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:30:27 by jimpark           #+#    #+#             */
/*   Updated: 2023/04/17 20:08:57 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	philo_eat(t_philo *philo)
{
	philo->n_eat++;
	pthread_mutex_lock(&philo->m_time);
	philo->last_eat_time = get_current_time();
	pthread_mutex_unlock(&philo->m_time);
	print_philo_status(philo, "is eating", 5);
	wait_action_time(philo->info->eat);
}

void	pick_up_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork);
	print_philo_status(philo, "has taken a fork", 3);
	pthread_mutex_lock(&philo->r_fork);
	print_philo_status(philo, "has taken a fork", 3);
}

void	put_down_fork(t_philo *philo)
{
	pthread_mutex_unlock(&philo->r_fork);
	pthread_mutex_unlock(&philo->l_fork);
}

void	philo_sleep(t_philo *philo)
{
	print_philo_status(philo, "is sleeping", 6);
	wait_action_time(philo->info->sleep);
}

void	philo_think(t_philo *philo)
{
	print_philo_status(philo, "is thinking", 2);
}
