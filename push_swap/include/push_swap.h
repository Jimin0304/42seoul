/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:02:10 by jimpark           #+#    #+#             */
/*   Updated: 2023/02/01 16:30:12 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/ft_printf/ft_printf.h"
# include "../lib/libft/libft.h"

typedef struct s_node
{
	int				content;
	struct s_node	*prev;
	struct s_node	*next;
}				t_node;

typedef struct s_info
{
	int				*arr;
	int				size;
	int				pa_count;
	int				pb_count;
	int				ra_count;
	int				rb_count;
	struct s_node	*top;
	struct s_node	*bottom;
}				t_info;

int		print_err(int i);
int		word_count(char *s, char c);
void	free_all(char **arr, int i);
int		get_argv_size(char **argv);
int		*parse_argv(char **argv, int *arr);
void	set_info(t_info *info);
void	push_top(t_info *info, int content);
void	push_bottom(t_info *info, int content);
void	pop_top(t_info *info);
void	pop_bottom(t_info *info);
int		arr_to_stack(t_info *info, int *arr);
t_node	*init_deque(t_node *newnode, int content);
void	sa(t_info *a_info);
void	sb(t_info *b_info);
void	ss(t_info *a_info, t_info *b_info);
void	pa(t_info *a_info, t_info *b_info);
void	pb(t_info *a_info, t_info *b_info);
void	ra(t_info *a_info);
void	rb(t_info *b_info);
void	rr(t_info *a_info, t_info *b_info);
void	rra(t_info *a_info);
void	rrb(t_info *b_info);
void	rrr(t_info *a_info, t_info *b_info);
void	set_count_info(t_info *a_info, t_info *b_info);

#endif
