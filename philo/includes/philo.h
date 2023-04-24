/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 18:04:08 by jimpark           #+#    #+#             */
/*   Updated: 2023/04/24 18:03:02 by jimpark          ###   ########.fr       */
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
	int				argc;
	int				n_philo;
	int				die;
	int				eat;
	int				sleep;
	int				count;
	int				full_philo;
	int				finish;
	pthread_mutex_t	m_action;
	pthread_mutex_t	m_print;
}				t_info;

typedef struct s_philo {
	int				id;
	pthread_t		thread;
	int				n_eat;
	long long		start_time;
	long long		last_eat_time;
	int				left;
	int				right;
	pthread_mutex_t	l_fork;
	pthread_mutex_t	r_fork;
	t_info			*info;
}				t_philo;

int			ft_atoi(char *str);
int			print_err(char *error_msg);
void		print_philo_status(t_philo *philo, char *str, int color);
void		wait_action_time(int time_to_action);
long long	get_current_time(void);

int			init_info(int argc, char *argv[], t_info *info);
int			init_philo(t_philo **philo, t_info *info);
int			init_mutex(t_philo *philo, t_info *info);

void		philo_eat(t_philo *philo);
void		pick_up_fork(t_philo *philo);
void		put_down_fork(t_philo *philo);
void		philo_sleep(t_philo *philo);
void		philo_think(t_philo *philo);

int			start_philo(t_philo *philo, t_info *info);
void		*action(void *argv);
int			check_philosophers(t_philo *philo);
void		join_thread(t_philo *philo, t_info *info);

void		mornitoring_philo(t_philo *philo, t_info *info);
int			check_dead_philo(t_philo *philo, t_info *info);

#endif
