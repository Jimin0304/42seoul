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

int	sort_arr_check(int *arr, int size)
{
	int	i;
	int	j;
	int	*tmp;
	int	check;

	i = -1;
	j = -1;
	check = 0;
	while (++i < size - 1)
	{
		while (++j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				check++;
				free (tmp);
			}
			else if (arr[j] == arr[j + 1])
				print_err(-1);
		}
	}
	return (check);
}

void	check_arr(t_info *info)
{

}

int	main(int argc, char *argv[])
{
	t_info	info;
	int		*arr_argv;
	int		arr_size;

	if (argc < 2)
		print_err(-1);
	set_info(&info);
	parse_argv(argv, &arr_argv);
	arr_size = ft_strlen(arr_argv);
	if (arr_size < 2)
		print_err(1);
	arr_to_stack(&info, &arr_argv);
	if (sort_arr_check(info.arr, arr_size) == 0)
		print_err (1);
}
