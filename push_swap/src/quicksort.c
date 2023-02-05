/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:21:31 by jimpark           #+#    #+#             */
/*   Updated: 2023/02/05 17:21:42 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	reverse_rotate(t_info *a_info, t_info *b_info, int a, int b)
{
	while (a > 0 && b > 0)
	{
		a--;
		b--;
		rrr(a_info, b_info);
	}
	while (a > 0)
	{
		a--;
		rra(a_info);
	}
	while (b > 0)
	{
		b--;
		rrb(b_info);
	}
}

int	*b_to_a_action(t_info *a_info, t_info *b_info, int r, int start)
{
	int	*count_arr;
	int	tmp;

	count_arr = make_int_arr_and_set(3);
	tmp = r / 3;
	while (r-- > 0)
	{
		if (b_info->top->content < a_info->arr[start + tmp])
		{
			rb(b_info);
			count_arr[0]++;
		}
		else
		{
			pa(a_info, b_info);
			count_arr[1]++;
			if (a_info->top->content < a_info->arr[start + tmp * 2])
			{
				ra(a_info);
				count_arr[2]++;
			}
		}
	}
	return (count_arr);
}

void	b_to_a(t_info *a_info, t_info *b_info, int r, int start)
{
	int	ra_count;
	int	rb_count;
	int	pa_count;
	int	*count_arr;

	if (r < 4)
	{
		pa_count = 0;
		while (r-- > 0)
		{
			pa(a_info, b_info);
			pa_count++;
		}
		sort_below_three(a_info, b_info, pa_count);
		return ;
	}
	count_arr = b_to_a_action(a_info, b_info, r, start);
	rb_count = count_arr[0];
	pa_count = count_arr[1];
	ra_count = count_arr[2];
	a_to_b(a_info, b_info, pa_count - ra_count, start + r / 3 * 2);
	reverse_rotate(a_info, b_info, ra_count, rb_count);
	a_to_b(a_info, b_info, ra_count, start + r / 3);
	b_to_a(a_info, b_info, rb_count, start);
	free (count_arr);
}

int	*a_to_b_action(t_info *a_info, t_info *b_info, int r, int start)
{
	int	*count_arr;
	int	tmp;

	count_arr = make_int_arr_and_set(3);
	tmp = r / 3;
	while (r-- > 0)
	{
		if (a_info->top->content > a_info->arr[start + tmp * 2])
		{
			ra(a_info);
			count_arr[0]++;
		}
		else
		{
			pb(a_info, b_info);
			count_arr[1]++;
			if (b_info->top->content > a_info->arr[start + tmp])
			{
				rb(b_info);
				count_arr[2]++;
			}
		}
	}
	return (count_arr);
}

void	a_to_b(t_info *a_info, t_info *b_info, int r, int start)
{
	int	ra_count;
	int	rb_count;
	int	pb_count;
	int	*count_arr;

	if (r < 4)
	{
		sort_below_three(a_info, b_info, r);
		return ;
	}
	count_arr = a_to_b_action(a_info, b_info, r, start);
	ra_count = count_arr[0];
	pb_count = count_arr[1];
	rb_count = count_arr[2];
	reverse_rotate(a_info, b_info, ra_count, rb_count);
	a_to_b(a_info, b_info, ra_count, start + r / 3 * 2);
	b_to_a(a_info, b_info, rb_count, start + r / 3);
	b_to_a(a_info, b_info, pb_count - rb_count, start);
	free (count_arr);
}
