/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:02:40 by jimpark           #+#    #+#             */
/*   Updated: 2023/02/05 20:49:25 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	print_err(int i)
{
	if (i == -1)
		ft_printf("Error\n");
	exit(1);
}

void	free_all(char **arr, int i)
{
	int	j;

	j = 0;
	while (j <= i)
		free(arr[j++]);
	free(arr);
}

int	*make_int_arr_and_set(int size)
{
	int	*count_arr;
	int	i;

	count_arr = (int *)malloc(sizeof(int) * size);
	if (!count_arr)
		print_err(-1);
	i = 0;
	while (i < size)
		count_arr[i++] = 0;
	return (count_arr);
}
