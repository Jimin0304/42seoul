#include "../push_swap.h"

void	ra(t_info *info)
{
	if (info->top_a == NULL)
		return ;
	push_bottom(info, info->top_a, info->bottom_a, info->top_a->content);
	pop_top(info, info->top_a);
	ft_printf("ra\n");
}

void	rb(t_info *info)
{
	if (info->top_b == NULL)
		return ;
	push_bottom(info, info->top_b, info->bottom_b, info->top_b->content);
	pop_top(info, info->top_b);
	ft_printf("rb\n");
}

void	rr(t_info *info)
{
	if (info->top_a)
	{
		push_bottom(info, info->top_a, info->bottom_a, info->top_a->content);
		pop_top(info, info->top_a);
	}
	if (info->top_b)
	{
		push_bottom(info, info->top_b, info->bottom_b, info->top_b->content);
		pop_top(info, info->top_b);
	}
	ft_printf("rr\n");
}