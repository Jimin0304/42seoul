/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:04:08 by jimpark           #+#    #+#             */
/*   Updated: 2023/04/12 22:14:27 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <pthread.h>

typedef struct s_info {
	int	n_philo;
	int	die;
	int	eat;
	int	sleep;
	int	count;
}				t_info;

typedef struct s_philo {
	int		id;
	int		n_eat;
	time_t	last_eat_time;
	int		left;
	int		right;
}				t_philo;

int	ft_atoi(char *str);
int	print_err(char *error_msg);

#endif
