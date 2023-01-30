/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:46:26 by jimpark           #+#    #+#             */
/*   Updated: 2023/01/30 21:47:22 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	rra(t_info *a_info)
{
	if (a_info->bottom == NULL)
		return ;
	push_top(a_info, a_info->bottom->content);
	pop_bottom(a_info);
	ft_printf("rra\n");
}

void	rrb(t_info *b_info)
{
	if (b_info->bottom == NULL)
		return ;
	push_top(b_info, b_info->bottom->content);
	pop_bottom(b_info);
	ft_printf("rrb\n");
}

void	rrr(t_info *a_info, t_info *b_info)
{
	if (a_info->bottom)
	{
		push_top(a_info, a_info->bottom->content);
		pop_bottom(a_info);
	}
	if (b_info->bottom)
	{
		push_top(b_info, b_info->bottom->content);
		pop_bottom(b_info);
	}
	ft_printf("rrr\n");
}
