/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:16:06 by jimpark           #+#    #+#             */
/*   Updated: 2023/04/16 21:14:32 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*action(void *argv)
{
	t_philo *philo;

	philo = (t_philo *)argv;
	if (philo->id % 2)
		wait_action_time(philo->info.eat);
	while (1)
	{
		pick_up_fork(philo);
		philo_eat(philo);
		put_down_fork(philo);
		if (philo->info.argc == 6 && philo->n_eat == philo->info.count)
		{
			philo->info.full_philo++;
			break ;
		}
		philo_sleep(philo);
		philo_think(philo);
	}
	return (0);
}

int	check_dead_philo(t_philo *philo, t_info *info)
{
	int	i;
	long long	now;

	i = 1;
	while (i <= info->n_philo)
	{
		now = get_current_time();
		if (now - philo[i].last_eat_time >= info->die)
		{
			print_philo_status(&philo[i], "died");
			return (1);
		}
		i++;
	}
	return (0);
}

void	mornitoring_philo(t_philo *philo, t_info *info)
{
	while (1)
	{
		if (info->argc == 6 && info->full_philo == info->count)
			break ;
		if (check_dead_philo(philo, info))
			break ;
		usleep(1000);
	}
}

int	start_philo(t_philo *philo, t_info *info)
{
	int	i;
	long long time;

	time = get_current_time();
	i = 1;
	while (i <= info->n_philo)
	{
		philo[i].start_time = time;
		philo[i].last_eat_time = time;
		if (pthread_create(&philo[i].thread, NULL, action, &philo[i]))
			return (1);
		i++;
	}
	i = 1;
	while (i <= info->n_philo)
		pthread_join(philo[i++].thread, NULL);
	mornitoring_philo(philo, info);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_info	info;
	t_philo	*philo;

	if (argc != 5 && argc != 6)
		return (print_err("argc"));
	if (init_info(argc, argv, &info))
		return (print_err("argv init"));
	if (init_philo(&philo, &info))
		return (print_err("philo init"));
	if (init_mutex(philo, &info))
		return (print_err("mutex_init"));
	if (start_philo(philo, &info))
		return (print_err("philo"));
}
