/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:46:28 by jimpark           #+#    #+#             */
/*   Updated: 2023/02/06 22:11:45 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	checker_ra(t_info *a_info)
{
	if (a_info->size < 2)
		return ;
	push_bottom(a_info, a_info->top->content);
	pop_top(a_info);
}

void	checker_rb(t_info *b_info)
{
	if (b_info->size < 2)
		return ;
	push_bottom(b_info, b_info->top->content);
	pop_top(b_info);
}

void	checker_rr(t_info *a_info, t_info *b_info)
{
	checker_ra(a_info);
	checker_rb(b_info);
}
