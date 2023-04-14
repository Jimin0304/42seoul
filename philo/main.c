/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:16:06 by jimpark           #+#    #+#             */
/*   Updated: 2023/04/14 21:08:41 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/philo.h"

int	init_info(int argc, char *argv[], t_info *info)
{
	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return(1);
	info->n_philo = ft_atoi(argv[1]);
	info->die = ft_atoi(argv[2]);
	info->eat = ft_atoi(argv[3]);
	info->sleep = ft_atoi(argv[4]);
	if (info->n_philo < 2 || info->die == -1 || info->eat == -1 \
			|| info->sleep == -1)
		return (1);
	if (argc == 6)
	{
		info->count = ft_atoi(argv[5]);
		if (info->count <= 0)
			return(1);
	}
	return (0);
}

int	init_philo(t_philo **philo, t_info *info)
{
	int	i;

	*philo = (t_philo *)malloc(sizeof(t_philo) * info->n_philo);
	if (!(*philo))
		return (1);
	i = 0;
	while (i < info->n_philo)
	{
		(*philo)[i].id = i;
		(*philo)[i].n_eat = 0;
		(*philo)[i].left = i;
		(*philo)[i].right = (i + 1) % info->n_philo;
		(*philo)[i].info = *info;
		i++;
	}
	return (0);
}

int	init_mutex(t_philo *philo, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n_philo)
	{
		if (pthread_mutex_init(&philo[i].fork, NULL))
			return (1);
		i++;
	}
	return (0);
}

void	*action(void *argv)
{
	t_philo *philo;

	philo = (t_philo *)argv;
	if (philo->id % 2)
		usleep(philo->info.eat);
	while (1)
	{
		philo_eat(philo);
		philo_sleep(philo);
		philo_think(philo);
	}
	return (0);
}

int	start_philo(t_philo *philo, t_info *info)
{
	int	i;
	time_t time;

	i = 0;
	while (i < info->n_philo)
	{
		philo[i].last_eat_time = gettimeofday(&time, NULL);
		pthread_create(&philo[i].thread, NULL, action, &philo[i]);
		i++;
	}
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
	if (start_philo(philo, &info));
		return (print_err("philo"));
}
