/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reverse_rotate_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:46:26 by jimpark           #+#    #+#             */
/*   Updated: 2023/02/06 22:11:41 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	checker_rra(t_info *a_info)
{
	if (a_info->size < 2)
		return ;
	push_top(a_info, a_info->bottom->content);
	pop_bottom(a_info);
}

void	checker_rrb(t_info *b_info)
{
	if (b_info->size < 2)
		return ;
	push_top(b_info, b_info->bottom->content);
	pop_bottom(b_info);
}

void	checker_rrr(t_info *a_info, t_info *b_info)
{
	checker_rra(a_info);
	checker_rrb(b_info);
}
