/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:46:24 by jimpark           #+#    #+#             */
/*   Updated: 2023/02/06 22:11:33 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	checker_pa(t_info *a_info, t_info *b_info)
{
	if (b_info->size == 0)
		return ;
	push_top(a_info, b_info->top->content);
	pop_top(b_info);
}

void	checker_pb(t_info *a_info, t_info *b_info)
{
	if (a_info->size == 0)
		return ;
	push_top(b_info, a_info->top->content);
	pop_top(a_info);
}
