/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:02:10 by jimpark           #+#    #+#             */
/*   Updated: 2023/01/28 23:07:27 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../ft_printf/ft_printf.h"
# include "../libft/libft.h"

typedef struct s_node
{
	int				content;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

typedef struct s_info
{
	int				*arr;
	int				size_a;
	int				size_b;
	struct s_node	*top_a;
	struct s_node	*bottom_a;
	struct s_node	*top_b;
	struct s_node	*bottom_b;
}				t_info;

char	*print_err(int i);
int		word_count(char *s, char c);
void	free_all(char **arr, int i);
int		parse_argv(char **argv, t_info *info);
void	set_info(t_info *info);
void	push_top(t_info *info, t_node *top, t_node *bottom, int content);
void	push_bottom(t_info *info, t_node *top, t_node *bottom, int content);
void	pop_top(t_info *info, t_node *top);
void	pop_bottom(t_info *info, t_node *bottom);
int		arr_to_stack(t_info *info);
void	sa(t_info *info);
void	sb(t_info *info);
void	ss(t_info *info);
void	pa(t_info *info);
void	pb(t_info *info);
void	ra(t_info *info);
void	rb(t_info *info);
void	rr(t_info *info);
void	rra(t_info *info);
void	rrb(t_info *info);
void	rrr(t_info *info);

#endif
