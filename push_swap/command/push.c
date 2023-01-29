#include "../push_swap.h"

void	pa(t_info *info)
{
	if (info->top_b == NULL)
		return ;
	push_top(info, info->top_a, info->bottom_a, info->top_b->content);
	pop_top(info, info->top_b);
	ft_printf("pa\n");
}

void	pb(t_info *info)
{
	if (info->top_a == NULL)
		return ;
	push_top(info, info->top_b, info->bottom_b, info->top_a->content);
	pop_top(info, info->top_a);
	ft_printf("pb\n");
}