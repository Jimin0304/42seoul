#include "../push_swap.h"

void	rra(t_info *info)
{
	if (info->bottom_a == NULL)
		return ;
	push_top(info, info->top_a, info->bottom_a, info->bottom_a->content);
	pop_bottom(info, info->bottom_a);
	ft_printf("rra\n");
}

void	rrb(t_info *info)
{
	if (info->bottom_b == NULL)
		return ;
	push_top(info, info->top_b, info->bottom_b, info->bottom_b->content);
	pop_bottom(info, info->bottom_b);
	ft_printf("rrb\n");
}

void	rrr(t_info *info)
{
	if (info->bottom_a)
	{
	    push_top(info, info->top_a, info->bottom_a, info->bottom_a->content);
	    pop_bottom(info, info->bottom_a);
	}
	if (info->bottom_b)
	{
		push_top(info, info->top_b, info->bottom_b, info->bottom_b->content);
	    pop_bottom(info, info->bottom_b);
	}
	ft_printf("rrr\n");
}