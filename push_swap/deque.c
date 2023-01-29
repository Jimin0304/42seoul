#include "push_swap.h"

t_node	*init_deque(t_node *newnode, int content)
{
	newnode->prev = NULL;
	newnode->next = NULL;
	newnode->content = content;
	return (newnode);
}

void	push_top(t_info *info, t_node *top, t_node *bottom, int content)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	if (!newnode)
		print_err(-1);
	if (top == NULL)
	{
		top = init_deque(&newnode, content);
		bottom = top;
	}
	else
	{
		top->prev = newnode;
		newnode->next = top;
		newnode->prev = NULL;
		newnode->content = content;
		while (top->next)
			top = top->next;
		bottom = top;
		top = newnode;
	}	
}

void	push_bottom(t_info *info, t_node* top, t_node *bottom, int content)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	if (!newnode)
		print_err(-1);
	if (bottom == NULL)
	{
		bottom = init_deque(&newnode, content);
		top = bottom;
	}
	else
	{
		bottom->next = newnode;
		newnode->prev = bottom;
		newnode->next = NULL;
		newnode->content = content;
		while (bottom->prev)
			bottom = bottom->prev;
		top = bottom;
		bottom = newnode;
	}
}

void	pop_top(t_info *info, t_node *top)
{
	t_node	*tmp;

	if (top->next)
	{
		tmp = top;
		top = tmp->next;
		tmp->next = NULL;
		top->prev = NULL;
		free(tmp);
	}
	else
	{
		free(top);
		top = NULL;
	}
}

void	pop_bottom(t_info *info, t_node *bottom)
{
	t_node	*tmp;

	if (bottom->prev)
	{
		tmp = bottom;
		bottom = tmp->prev;
		tmp->prev = NULL;
		bottom->next = NULL;
		free (tmp);
	}
	else
	{
		free (bottom);
		bottom = NULL;
	}
}
