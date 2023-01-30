/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:01:33 by jimpark           #+#    #+#             */
/*   Updated: 2023/01/30 21:33:02 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	sort_arr_check(t_info *info, int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;
	int	check;

	i = -1;
	check = 0;
	while (++i < size)
	{
		j = -1;
		while (++j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				check++;
			}
			else if (arr[j] == arr[j + 1])
				print_err(-1);
		}
	}
	info->arr = arr;
	return (check);
}

int	main(int argc, char *argv[])
{
	t_info	a_info;
	t_info	b_info;
	int		arr_size;
	int		*arr;

	if (argc < 2)
		print_err(-1);
	set_info(&a_info);
	set_info(&b_info);
	arr_size = get_argv_size(argv) - 1;
	arr = (int *)malloc(sizeof(int) * (arr_size + 1));
	if (!arr)
		print_err(-1);
	arr = parse_argv(argv, arr);
	if (arr_size < 2)
		print_err(1);
	arr_to_stack(&a_info, arr);
	if (sort_arr_check(&a_info, arr, arr_size) == 0)
		print_err (1);
}
