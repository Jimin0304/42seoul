/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:46:31 by jimpark           #+#    #+#             */
/*   Updated: 2023/02/05 21:51:53 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_info *a_info)
{
	int	tmp;

	if (a_info->size < 2)
		return ;
	tmp = a_info->top->content;
	a_info->top->content = a_info->top->next->content;
	a_info->top->next->content = tmp;
	ft_printf("sa\n");
}

void	sb(t_info *b_info)
{
	int	tmp;

	if (b_info->size < 2)
		return ;
	tmp = b_info->top->content;
	b_info->top->content = b_info->top->next->content;
	b_info->top->next->content = tmp;
	ft_printf("sb\n");
}

void	ss(t_info *a_info, t_info *b_info)
{
	int	tmp;

	if (a_info->size >= 2 && b_info->size >= 2)
	{
		tmp = a_info->top->content;
		a_info->top->content = a_info->top->next->content;
		a_info->top->next->content = tmp;
		tmp = b_info->top->content;
		b_info->top->content = b_info->top->next->content;
		b_info->top->next->content = tmp;
		ft_printf("ss\n");
	}
	else if (a_info->size >= 2)
		sa(a_info);
	else if (b_info->size >= 2)
		sb(b_info);
}
