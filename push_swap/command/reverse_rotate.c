/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:46:26 by jimpark           #+#    #+#             */
/*   Updated: 2023/02/05 21:51:28 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra(t_info *a_info)
{
	if (a_info->size < 2)
		return ;
	push_top(a_info, a_info->bottom->content);
	pop_bottom(a_info);
	ft_printf("rra\n");
}

void	rrb(t_info *b_info)
{
	if (b_info->size < 2)
		return ;
	push_top(b_info, b_info->bottom->content);
	pop_bottom(b_info);
	ft_printf("rrb\n");
}

void	rrr(t_info *a_info, t_info *b_info)
{
	if (a_info->size >= 2 && b_info->size >= 2)
	{
		push_top(a_info, a_info->bottom->content);
		pop_bottom(a_info);
		push_top(b_info, b_info->bottom->content);
		pop_bottom(b_info);
		ft_printf("rrr\n");
	}
	else if (a_info->size >= 2)
		rra(a_info);
	else if (b_info->size >= 2)
		rrb(b_info);
}
