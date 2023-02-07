/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:02:40 by jimpark           #+#    #+#             */
/*   Updated: 2023/02/07 20:05:56 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	print_err(void)
{
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

void	free_nodes(t_info *info)
{
	while (info->top)
	{
		free (info->top);
		info->top = info->top->next;
	}
}

int	*make_int_arr_and_set(int size)
{
	int	*count_arr;
	int	i;

	count_arr = (int *)malloc(sizeof(int) * size);
	if (!count_arr)
		exit(1);
	i = 0;
	while (i < size)
		count_arr[i++] = 0;
	return (count_arr);
}
