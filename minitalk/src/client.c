/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:21:47 by jimpark           #+#    #+#             */
/*   Updated: 2023/02/11 22:56:32 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minitalk.h"

int	*dec_to_bin(char c)
{
	int	*result;
	int	i;

	result = (int *)malloc(sizeof(int) * 8);
	i = 7;
	while (i >= 0)
	{
		result[i] = c % 2;
		c = c / 2;
		i--;
	}
	return (result);
}

void	send_message(pid_t pid, char *msg)
{
	int	*bin;

	while (*msg)
	{
		*bin = dec_to_bin(*msg++);
		while (*bin)
		{
			if (*bin == 1)
				kill(pid, SIGUSR1);
			else if (*bin == 0)
				kill(pid, SIGUSR2);
			bin++;
		}
		msg++;
		free (bin);
	}
}

int main(int argc, char *argv[])
{
	pid_t	pid;

	if (argc < 3)
		print_err("wrong format");
	pid = ft_atoi(argv[1]);
	send_message(pid, argv[2]);
}
