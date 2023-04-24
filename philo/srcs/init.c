/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 19:29:23 by jimpark           #+#    #+#             */
/*   Updated: 2023/04/24 18:04:31 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_info(int argc, char *argv[], t_info *info)
{
	info->argc = argc;
	info->n_philo = ft_atoi(argv[1]);
	info->die = ft_atoi(argv[2]);
	info->eat = ft_atoi(argv[3]);
	info->sleep = ft_atoi(argv[4]);
	if (info->n_philo < 1 || info->die == -1 || info->eat == -1 \
			|| info->sleep == -1)
		return (1);
	if (argc == 6)
	{
		info->count = ft_atoi(argv[5]);
		if (info->count <= 0)
			return (1);
	}
	info->full_philo = 0;
	info->finish = 0;
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
		(*philo)[i].id = i + 1;
		(*philo)[i].n_eat = 0;
		(*philo)[i].left = i;
		(*philo)[i].right = (i + 1) % info->n_philo;
		(*philo)[i].r_fork = (*philo)[(i + 1) % info->n_philo].l_fork;
		(*philo)[i].info = info;
		i++;
	}
	return (0);
}

int	init_mutex(t_philo *philo, t_info *info)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&info->m_action, NULL))
		return (1);
	if (pthread_mutex_init(&info->m_print, NULL))
		return (1);
	while (i < info->n_philo)
	{
		if (pthread_mutex_init(&philo[i].l_fork, NULL))
			return (1);
		i++;
	}
	return (0);
}
