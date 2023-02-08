/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:46:31 by jimpark           #+#    #+#             */
/*   Updated: 2023/02/06 22:11:49 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

void	checker_sa(t_info *a_info)
{
	int	tmp;

	if (a_info->size < 2)
		return ;
	tmp = a_info->top->content;
	a_info->top->content = a_info->top->next->content;
	a_info->top->next->content = tmp;
}

void	checker_sb(t_info *b_info)
{
	int	tmp;

	if (b_info->size < 2)
		return ;
	tmp = b_info->top->content;
	b_info->top->content = b_info->top->next->content;
	b_info->top->next->content = tmp;
}

void	checker_ss(t_info *a_info, t_info *b_info)
{
	checker_sa(a_info);
	checker_sb(b_info);
}
