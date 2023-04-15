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

int	init_fork(t_info *info)
{
	int	i;

	info->fork = (int *)malloc(sizeof(int) * info->n_philo);
	if (!info->fork)
		return (1);
	i = 0;
	while (i < info->n_philo)
		info->fork[i++] = 0;
	return (0);
}

int	init_info(int argc, char *argv[], t_info *info)
{
	info = (t_info *)malloc(sizeof(t_info));
	if (!info)
		return(1);
	info->argc = argc;
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
	if (init_fork(info))
		return (1);
	info->full_philo = 0;
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
		(*philo)[i].r_fork = (*philo)[(i + 1) % info->n_philo].l_fork;
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
		if (pthread_mutex_init(&philo[i].l_fork, NULL))
			return (1);
		i++;
	}
	return (0);
}

void	wait_action_time(int time_to_action)
{
	int	start;

	start = get_current_time();
}

void	philo_eat(t_philo *philo)
{
	philo->n_eat++;
	philo->last_eat_time = get_time();
	print_philo_status(philo->id, "is eating");
	wait_action_time(philo->info.eat);
}

void	pick_up_fork(t_philo *philo)
{
	pthread_mutex_lock(&philo->l_fork);
	philo->info.fork[philo->left] = 1;
	print_philo_status(philo->id, "has taken a fork");
	pthread_mutex_lock(&philo->r_fork);
	philo->info.fork[philo->right] = 1;
	print_philo_status(philo->id, "has taken a fork");
}

void	put_down_fork(t_philo *philo)
{
	philo->info.fork[philo->right] = 0;
	pthread_mutex_unlock(&philo->r_fork);
	philo->info.fork[philo->left] = 0;
	pthread_mutex_unlock(&philo->l_fork);
}

void	*action(void *argv)
{
	t_philo *philo;
	int		flag;

	philo = (t_philo *)argv;
	if (philo->id % 2)
		usleep(philo->info.eat);
	flag = 0;
	while (!flag)
	{
		pick_up_fork(philo);
		if ((philo->info.fork[philo->left] == 1) && (philo->info.fork[philo->right] = 1))
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

time_t	get_current_time(void)
{
	time_t	time;

	gettimeofday(&time, NULL);
	return (time);
}

void	mornitoring_philo(t_philo *philo, t_info *info)
{
	while (1)
	{
		if (info->argc == 6 && info->full_philo == info->count)
			break ;
	}
}

int	start_philo(t_philo *philo, t_info *info)
{
	int	i;

	i = 0;
	while (i < info->n_philo)
	{
		philo[i].last_eat_time = get_current_time();
		if (pthread_create(&philo[i].thread, NULL, action, &philo[i]))
			return (1);
		i++;
	}
	i = 0;
	while (i < info->n_philo)
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
	if (start_philo(philo, &info));
		return (print_err("philo"));
}
