/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:01:33 by jimpark           #+#    #+#             */
/*   Updated: 2023/02/01 16:38:15 by jimpark          ###   ########.fr       */
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

void	reverse_rotate(t_info *a_info, t_info *b_info, int a, int b)
{
	while (a-- & b--)
		rrr(a_info, b_info);
	while (a--)
		rra(a_info);
	while (b--)
		rrb(b_info);
}

void	b_to_a(t_info *a_info, t_info *b_info, int r, int start, int size)
{
	int	pivot1;
	int	pivot2;

	if (size < 3)
	{
		sort_below_three(a_info, b_info);
		pa(a_info, b_info);
		pa(a_info, b_info);
		pa(a_info, b_info);
		return ;
	}

}

void	a_to_b(t_info *a_info, t_info *b_info, int r, int start, int size)
{
	int	pivot1;
	int	pivot2;

	if (size < 3)
	{
		sort_below_three(a_info, b_info);
		return ;
	}
	pivot1 = a_info->arr[(start + size) / 3];
	pivot2 = a_info->arr[(start + size) / 3 * 2];
	while (r--)
	{
		if (a_info->top->content > pivot2)
			ra(a_info);
		else
		{
			pb(a_info, b_info);
			if (b_info->top->content >= pivot1)
				rb(b_info);
		}
	}
	reverse_rotate(a_info, b_info, a_info->ra_count, b_info->rb_count);
	a_to_b(a_info, b_info, a_info->ra_count, pivot2, a_info->size);
	b_to_a(a_info, b_info, b_info->rb_count, pivot2, b_info->size);
	b_to_a(a_info, b_info, b_info->pb_count - b_info->rb_count, pivot2, b_info->size);
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
	a_to_b(&a_info, &b_info, arr_size, 0, arr_size);
}
