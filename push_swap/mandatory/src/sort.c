/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 16:56:41 by jimpark           #+#    #+#             */
/*   Updated: 2023/02/05 17:43:02 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sort_three(t_info *a_info, t_info *b_info)
{
	int	first;
	int	second;
	int	third;

	first = a_info->top->content;
	second = a_info->top->next->content;
	third = a_info->top->next->next->content;
	if (first < second && second > third && third > first)
		first_third_second(a_info);
	else if (first > second && second < third && third > first)
		second_first_third(a_info);
	else if (first < second && second > third && third < first)
		second_third_first(a_info, b_info);
	else if (first > second && second < third && third < first)
		third_first_second(a_info, b_info);
	else if (first > second && second > third && third < first)
		third_second_first(a_info, b_info);
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
			sort_three(a_info, b_info);
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
	sort_below_three(a_info, b_info, a_info->size);
	if (b_info->top->content < b_info->top->next->content)
		sb(b_info);
	pa(a_info, b_info);
	pa(a_info, b_info);
}
