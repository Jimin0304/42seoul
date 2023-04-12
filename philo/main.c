/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:16:06 by jimpark           #+#    #+#             */
/*   Updated: 2023/04/12 22:15:20 by jimpark          ###   ########.fr       */
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
		i++;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_info	info;
	t_philo	*philo;

	if (argc != 5 && argc != 6)
		return (print_err("argc"));
	if (init_info(argc, argv, &info))
		return (print_err("argv"));
	if (init_philo(&philo, &info))
		return (print_err("philo"));
}
