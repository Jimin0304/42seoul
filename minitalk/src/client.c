/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/11 16:21:47 by jimpark           #+#    #+#             */
/*   Updated: 2023/02/16 14:07:42 by jimpark          ###   ########.fr       */
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

void	send_message(pid_t pid, char *msg, int size)
{
	int	*bin;
	int	i;

	while (size--)
	{
		bin = dec_to_bin(*msg++);
		i = -1;
		while (++i < 8)
		{
			if (bin[i] == 1)
				kill(pid, SIGUSR1);
			else if (bin[i] == 0)
				kill(pid, SIGUSR2);
			usleep(20);
		}
		free (bin);
	}
}

int	main(int argc, char *argv[])
{
	pid_t	pid;
	int		i;

	if (argc < 3)
		print_err("wrong format");
	pid = ft_atoi(argv[1]);
	if (pid <= 100 || pid >= 99999)
		print_err("wrong PID");
	i = 2;
	while (argv[i])
	{
		send_message(pid, argv[i], ft_strlen(argv[i]));
		send_message(pid, "\n", ft_strlen("\n"));
		i++;
	}
}
