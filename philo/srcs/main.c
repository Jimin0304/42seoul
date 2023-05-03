/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:16:06 by jimpark           #+#    #+#             */
/*   Updated: 2023/05/03 20:33:08 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

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
	free (philo);
}
