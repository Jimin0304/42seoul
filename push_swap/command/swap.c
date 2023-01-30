/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:46:31 by jimpark           #+#    #+#             */
/*   Updated: 2023/01/30 21:47:29 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	sa(t_info *a_info)
{
	int	tmp;

	if (a_info->top == NULL)
		return ;
	tmp = a_info->top->content;
	a_info->top->content = a_info->top->next->content;
	a_info->top->next->content = tmp;
	ft_printf("sa\n");
}

void	sb(t_info *b_info)
{
	int	tmp;

	if (b_info->top == NULL)
		return ;
	tmp = b_info->top->content;
	b_info->top->content = b_info->top->next->content;
	b_info->top->next->content = tmp;
	ft_printf("sb\n");
}

void	ss(t_info *a_info, t_info *b_info)
{
	int	tmp;

	if (a_info->top)
	{
		tmp = a_info->top->content;
		a_info->top->content = a_info->top->next->content;
		a_info->top->next->content = tmp;
	}
	if (b_info->top)
	{
		tmp = b_info->top->content;
		b_info->top->content = b_info->top->next->content;
		b_info->top->next->content = tmp;
	}
	ft_printf("ss\n");
}
