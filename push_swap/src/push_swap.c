/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:01:33 by jimpark           #+#    #+#             */
/*   Updated: 2023/02/02 20:03:38 by jimpark          ###   ########.fr       */
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

void	sort_below_three(t_info *a_info, int size)
{
	if (size == 1)
		return ;
	else if (size == 2)
	{
		if (a_info->top->content < a_info->top->next->content)
			return ;
		sa(a_info);
	}
	else
	{
		if (a_info->top->content < a_info->top->next->content && \
		a_info->top->next->content < a_info->top->next->next->content)
			return ;
		while (size--)
		{
			if ()

		}
	}
}

void	b_to_a(t_info *a_info, t_info *b_info, int r, int start)
{
	int	pivot1;
	int	pivot2;

	set_count_info(a_info, b_info);
	if (r < 4)
	{
		while (r--)
			pa(a_info, b_info);
		sort_below_three(a_info, b_info->pa_count);
		return ;
	}
	pivot1 = a_info->arr[start + (r / 3)];
	pivot2 = a_info->arr[start + (r / 3 * 2)];
	while (r--)
	{
		if (b_info->top->content <= pivot1)
			rb(b_info);
		else
		{
			pa(a_info, b_info);
			if (a_info->top->content <= pivot2)
				ra(a_info);
		}
	}
	a_to_b(a_info, b_info, b_info->pa_count - a_info->ra_count, pivot2);
	reverse_rotate(a_info, b_info, a_info->ra_count, b_info->rb_count);
	a_to_b(a_info, b_info, a_info->ra_count, pivot2);
	b_to_a(a_info, b_info, b_info->rb_count, pivot1);
}

void	a_to_b(t_info *a_info, t_info *b_info, int r, int start)
{
	int	pivot1;
	int	pivot2;

	set_count_info(a_info, b_info);
	if (r < 4)
	{
		sort_below_three(a_info, r);
		return ;
	}
	pivot1 = a_info->arr[start + (r / 3)];
	pivot2 = a_info->arr[start + (r / 3 * 2)];
	while (r--)
	{
		if (a_info->top->content >= pivot2)
			ra(a_info);
		else
		{
			pb(a_info, b_info);
			if (b_info->top->content >= pivot1)
				rb(b_info);
		}
	}
	reverse_rotate(a_info, b_info, a_info->ra_count, b_info->rb_count);
	a_to_b(a_info, b_info, a_info->ra_count, pivot2);
	b_to_a(a_info, b_info, b_info->rb_count, pivot1);
	b_to_a(a_info, b_info, a_info->pb_count - b_info->rb_count, pivot1);
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
	a_to_b(&a_info, &b_info, arr_size, 0);
}
