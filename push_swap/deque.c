#include "push_swap.h"

t_node	*init_deque(t_node *newnode, int content)
{
	newnode->prev = NULL;
	newnode->next = NULL;
	newnode->content = content;
	return (newnode);
}

void	push_top(t_info *info, t_node *top, int content)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	if (!newnode)
		print_err(-1);
	if (top == NULL)
		top = init_deque(&newnode, content);
	else
	{
		top->prev = newnode;
		newnode->next = top;
		newnode->prev = NULL;
		newnode->content = content;
		top = newnode;
	}
}

void	push_bottom(t_info *info, t_node *bottom, int content)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	if (!newnode)
		print_err(-1);
	if (bottom == NULL)
		bottom = init_deque(&newnode, content);
	else
	{
		bottom->next = newnode;
		newnode->prev = bottom;
		newnode->next = NULL;
		newnode->content = content;
		bottom = newnode;
	}
}

void	pop_top(t_info *info, t_node *top)
{
	t_node	*next_top;
	t_node	*tmp;

	if (top == NULL)
		return ;
	tmp = top;
	next_top = top->next;
	next_top->prev = NULL;
	top->next = NULL;
	top = next_top;
	free(tmp);
}

void	pop_bottom(t_info *info, t_node *bottom)
{
	t_node	*prev_bottom;
	t_node	*tmp;

	if (bottom == NULL)
		return ;
	tmp = bottom;
	prev_bottom = bottom->prev;
	prev_bottom->next = NULL;
	bottom->prev = NULL;
	bottom = prev_bottom;
	free(tmp);
}
