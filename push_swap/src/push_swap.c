/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:01:33 by jimpark           #+#    #+#             */
/*   Updated: 2023/02/05 17:26:39 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	*init_a_to_b(t_info *a_info, t_info *b_info, int r, int start)
{
	int	*count_arr;
	int	tmp;

	count_arr = make_int_arr_and_set(3);
	tmp = r / 3;
	while (r-- > 0)
	{
		if (a_info->top->content >= a_info->arr[start + tmp * 2])
		{
			ra(a_info);
			count_arr[0]++;
		}
		else
		{
			pb(a_info, b_info);
			count_arr[1]++;
			if (b_info->top->content < a_info->arr[start + tmp])
			{
				rb(b_info);
				count_arr[2]++;
			}
		}
	}
	return (count_arr);
}

void	quicksort(t_info *a_info, t_info *b_info, int r, int start)
{
	int	ra_count;
	int	rb_count;
	int	pb_count;
	int	*count_arr;

	count_arr = init_a_to_b(a_info, b_info, r, start);
	ra_count = count_arr[0];
	pb_count = count_arr[1];
	rb_count = count_arr[2];
	a_to_b(a_info, b_info, ra_count, start + r / 3 * 2);
	b_to_a(a_info, b_info, rb_count, start + r / 3);
	b_to_a(a_info, b_info, pb_count - rb_count, start);
}

int	main(int argc, char *argv[])
{
	t_info	a_info;
	t_info	b_info;
	int		arr_size;
	int		*arr;

	if (argc < 2)
		print_err(1);
	set_info(&a_info);
	set_info(&b_info);
	arr_size = get_argv_size(argv) - 1;
	arr = (int *)malloc(sizeof(int) * (arr_size + 1));
	if (!arr)
		print_err(-1);
	arr = parse_argv(argv, arr);
	if (arr_size < 2)
		print_err(1);
	arr_to_stack(&a_info, arr, arr_size);
	if (sort_arr_check(&a_info, arr, arr_size) == 0)
		print_err (1);
	if (arr_size <= 3)
		sort_below_three(&a_info, &b_info, arr_size);
	else if (arr_size < 6)
		sort_below_five(&a_info, &b_info, arr_size);
	else
		quicksort(&a_info, &b_info, arr_size, 0);
}
