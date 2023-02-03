/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   quicksort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 14:21:31 by jimpark           #+#    #+#             */
/*   Updated: 2023/02/03 18:08:06 by jimpark          ###   ########.fr       */
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

void	sort_three(t_info *a, t_info *b, int first, int second, int third)
{
	if (first < second && second > third && third > first)
		first_third_second(a);
	else if (first > second && second < third && third > first)
		second_first_third(a);
	else if (first < second && second > third && third < first)
		second_third_first(a, b);
	else if (first > second && second < third && third < first)
		third_first_second(a, b);
	else if (first > second && second > third && third < first)
		third_second_first(a, b);
}

void	sort_below_three(t_info *a_info, t_info *b_info, int size)
{
	int	first;
	int	second;
	int	third;

	if (size == 1)
		return ;
	else
	{
		first = a_info->top->content;
		second = a_info->top->next->content;
		if (size == 2)
		{
			if (first < second)
				return ;
			sa(a_info);
		}
		else
		{
			third = a_info->top->next->next->content;
			if (first < second && second < third && third > first)
				return ;
			sort_three(a_info, b_info, first, second, third);
		}
	}
}

void	sort_below_five(t_info *a_info, t_info *b_info, int size)
{
	int	pivot;

	pivot = a_info->arr[size / 2];
	while (size-- > 0)
	{
		if (a_info->top->content < pivot)
			pb(a_info, b_info);
		else
			ra(a_info);
	}
	if (a_info->size == 2)
	{
		if (a_info->top->content > a_info->top->next->content)
			sa(a_info);
	}
	else
		sort_below_three(a_info, b_info, 3);
	if (b_info->size == 1)
		pa(a_info, b_info);
	else
	{
		if (b_info->top->content < b_info->top->next->content)
			sb(b_info);
		pa(a_info, b_info);
		pa(a_info, b_info);
	}
}

void	b_to_a(t_info *a_info, t_info *b_info, int r, int start)
{
	int	ra_count;
	int	rb_count;
	int	pa_count;
	int	tmp;

	ra_count = 0;
	rb_count = 0;
	pa_count = 0;
	if (r < 4)
	{
		while (r-- > 0)
		{
			pa(a_info, b_info);
			pa_count++;
		}
		sort_below_three(a_info, b_info, pa_count);
		return ;
	}
	tmp = r / 3;
	while (r-- > 0)
	{
		if (b_info->top->content < a_info->arr[start + tmp])
		{
			rb(b_info);
			rb_count++;
		}
		else
		{
			pa(a_info, b_info);
			pa_count++;
			if (a_info->top->content < a_info->arr[start + tmp * 2])
			{
				ra(a_info);
				ra_count++;
			}
		}
	}
	a_to_b(a_info, b_info, pa_count - ra_count, start + tmp * 2);
	reverse_rotate(a_info, b_info, ra_count, rb_count);
	a_to_b(a_info, b_info, ra_count, start + tmp);
	b_to_a(a_info, b_info, rb_count, start);
}

void	a_to_b(t_info *a_info, t_info *b_info, int r, int start)
{
	int	ra_count;
	int	rb_count;
	int	pb_count;
	int tmp;

	ra_count = 0;
	rb_count = 0;
	pb_count = 0;
	if (r < 4)
	{
		sort_below_three(a_info, b_info, r);
		return ;
	}
	tmp = r / 3;
	while (r-- > 0)
	{
		if (a_info->top->content > a_info->arr[start + tmp * 2])
		{
			ra(a_info);
			ra_count++;
		}
		else
		{
			pb(a_info, b_info);
			pb_count++;
			if (b_info->top->content > a_info->arr[start + tmp])
			{
				rb(b_info);
				rb_count++;
			}
		}
	}
	reverse_rotate(a_info, b_info, ra_count, rb_count);
	a_to_b(a_info, b_info, ra_count, start + tmp * 2);
	b_to_a(a_info, b_info, rb_count, start + tmp);
	b_to_a(a_info, b_info, pb_count - rb_count, start);
}
