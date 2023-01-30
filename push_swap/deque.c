/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deque.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 20:46:38 by jimpark           #+#    #+#             */
/*   Updated: 2023/01/30 20:46:39 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*init_deque(t_node *newnode, int content)
{
	newnode->prev = NULL;
	newnode->next = NULL;
	newnode->content = content;
	return (newnode);
}

void	push_top(t_info *info, int content)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	if (!newnode)
		print_err(-1);
	if (info->top == NULL)
	{
		info->top = init_deque(newnode, content);
		info->bottom = info->top;
	}
	else
	{
		newnode->next = info->top;
		info->top->prev = newnode;
		newnode->prev = NULL;
		newnode->content = content;
		while (info->top->next)
			info->top = info->top->next;
		info->bottom = info->top;
		info->top = newnode;
	}
}

void	push_bottom(t_info *info, int content)
{
	t_node	*newnode;

	newnode = (t_node *)malloc(sizeof(t_node));
	if (!newnode)
		print_err(-1);
	if (info->bottom == NULL)
	{
		info->bottom = init_deque(newnode, content);
		info->top = info->bottom;
	}
	else
	{
		newnode->prev = info->bottom;
		info->bottom->next = newnode;
		newnode->next = NULL;
		newnode->content = content;
		while (info->bottom->prev)
			info->bottom = info->bottom->prev;
		info->top = info->bottom;
		info->bottom = newnode;
	}
}

void	pop_top(t_info *info)
{
	t_node	*tmp;

	if (info->top->next)
	{
		tmp = info->top;
		info->top = tmp->next;
		tmp->next = NULL;
		info->top->prev = NULL;
		free(tmp);
	}
	else
	{
		free(info->top);
		info->top = NULL;
	}
}

void	pop_bottom(t_info *info)
{
	t_node	*tmp;

	if (info->bottom->prev)
	{
		tmp = info->bottom;
		info->bottom = tmp->prev;
		tmp->prev = NULL;
		info->bottom->next = NULL;
		free (tmp);
	}
	else
	{
		free (info->bottom);
		info->bottom = NULL;
	}
}
