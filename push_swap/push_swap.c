/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:01:33 by jimpark           #+#    #+#             */
/*   Updated: 2023/01/28 23:15:03 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	parse_argv(char *argv, t_info *info)
{
	ft_split
}

int	main(int argc, char *argv[])
{
	t_info	info;
	int		i;
	int		j;

	if (argc < 2)
		print_err();
	i = 0;
	while (argv[i])
	{
		j = 0;
		if (ft_strchr(argv[i][0], '"') != 0 || \
		ft_strchr(argv[i][ft_strlen(argv[i]) - 1], '"') != 0)
			parse_argv(argv[i], &info);
		ft_atoi(argv[i]);
		i++;
	}
}
