/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:46:28 by jimpark           #+#    #+#             */
/*   Updated: 2023/01/30 20:46:29 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

void	ra(t_info *a_info)
{
	if (a_info->top == NULL)
		return ;
	push_bottom(a_info, a_info->top->content);
	pop_top(a_info);
	ft_printf("ra\n");
}

void	rb(t_info *b_info)
{
	if (b_info->top == NULL)
		return ;
	push_bottom(b_info, b_info->top->content);
	pop_top(b_info);
	ft_printf("rb\n");
}

void	rr(t_info *a_info, t_info *b_info)
{
	if (a_info->top)
	{
		push_bottom(a_info, a_info->top->content);
		pop_top(a_info);
	}
	if (b_info->top)
	{
		push_bottom(b_info, b_info->top->content);
		pop_top(b_info);
	}
	ft_printf("rr\n");
}
