/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:08:40 by jimpark           #+#    #+#             */
/*   Updated: 2023/01/26 22:40:36 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	free_all(char **arr, int i)
{
	int	j;

	j = 0;
	while (j <= i)
		free(arr[j++]);
	free(arr);
}

char	*print_err(char *error)
{
	ft_printf("Error\n");
	ft_printf("%s\n", error);
	exit(1);
}

void	success_game(t_map *map)
{
	ft_printf("move : %d\n", ++map->player.move);
	ft_printf("Congratuations! Success the game!\n");
	exit(0);
}

int	exit_game(void)
{
	ft_printf("bye bye !\n");
	exit(0);
	return (0);
}
