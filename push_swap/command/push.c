/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:46:24 by jimpark           #+#    #+#             */
/*   Updated: 2023/02/03 10:32:15 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	pa(t_info *a_info, t_info *b_info)
{
	if (b_info->top == NULL)
		return ;
	push_top(a_info, b_info->top->content);
	pop_top(b_info);
	ft_printf("pa\n");
}

void	pb(t_info *a_info, t_info *b_info)
{
	if (a_info->top == NULL)
		return ;
	push_top(b_info, a_info->top->content);
	pop_top(a_info);
	ft_printf("pb\n");
}
