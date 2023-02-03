/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_three.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 09:00:00 by jimpark           #+#    #+#             */
/*   Updated: 2023/02/03 13:48:35 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

void	first_third_second(t_info *a_info, int init)
{
	if (init == 1)
	{
		rra(a_info);
		sa(a_info);
		return ;
	}
	ra(a_info);
	sa(a_info);
	rra(a_info);
}

void	second_first_third(t_info *a_info)
{
	sa(a_info);
}

void	second_third_first(t_info *a_info, t_info *b_info, int init)
{
	if (init == 1)
	{
		rra(a_info);
		return ;
	}
	pb(a_info, b_info);
	sa(a_info);
	pa(a_info, b_info);
	sa(a_info);
}

void	third_first_second(t_info *a_info, t_info *b_info, int init)
{
	if (init == 1)
	{
		ra(a_info);
		return ;
	}
	sa(a_info);
	pb(a_info, b_info);
	sa(a_info);
	pa(a_info, b_info);
}

void	third_second_first(t_info *a_info, t_info *b_info, int init)
{
	if (init == 1)
	{
		ra(a_info);
		sa(a_info);
		return ;
	}
	sa(a_info);
	pb(a_info, b_info);
	sa(a_info);
	pa(a_info, b_info);
	sa(a_info);
}

