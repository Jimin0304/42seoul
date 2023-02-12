/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:21:42 by jimpark           #+#    #+#             */
/*   Updated: 2023/02/12 18:19:51 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

void	sig_handler(int sig)
{
	static char	bit;
	static int	index;

	if (sig == SIGUSR1)
	{
		bit |= 1;
		if (index < 7)
			bit <<= 1;
	}
	else if (sig == SIGUSR2)
	{
		bit |= 0;
		if (index < 7)
			bit <<= 1;
	}
	index++;
	if (index == 8)
	{
		ft_printf("%c", bit);
		bit = 0;
		index = 0;
	}
}

int	main(void)
{
	pid_t	pid;

	pid = getpid();
	ft_printf("server PID : %d\n", pid);
	signal(SIGUSR1, sig_handler);
	signal(SIGUSR2, sig_handler);
	while (1)
		pause();
}
