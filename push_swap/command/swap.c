#include "../push_swap.h"

void	sa(t_info *info)
{
	int	tmp;

	if (info->top_a == NULL)
		return ;
	tmp = info->top_a->content;
	info->top_a->content = info->top_a->next->content;
	info->top_a->next->content = tmp;
	ft_printf("sa\n");
}

void	sb(t_info *info)
{
	int	tmp;

	if (info->top_b == NULL)
		return ;
	tmp = info->top_b->content;
	info->top_b->content = info->top_b->next->content;
	info->top_b->next->content = tmp;
	ft_printf("sb\n");
}

void	ss(t_info *info)
{
	int	tmp;

	if (info->top_a)
	{
		tmp = info->top_a->content;
		info->top_a->content = info->top_a->next->content;
		info->top_a->next->content = tmp;
	}
	if (info->top_b)
	{
		tmp = info->top_b->content;
		info->top_b->content = info->top_b->next->content;
		info->top_b->next->content = tmp;
	}
	ft_printf("ss\n");
}