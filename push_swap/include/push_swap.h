/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:02:10 by jimpark           #+#    #+#             */
/*   Updated: 2023/02/03 14:25:45 by jimpark          ###   ########.fr       */
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
int		arr_to_stack(t_info *a_info, int *arr, int size);
int		sort_arr_check(t_info *info, int *arr, int size);
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
void	first_third_second(t_info *a_info, int init);
void	second_first_third(t_info *a_info);
void	second_third_first(t_info *a_info, t_info *b_info, int init);
void	third_first_second(t_info *a_info, t_info *b_info, int init);
void	third_second_first(t_info *a_info, t_info *b_info, int init);
void	a_to_b(t_info *a_info, t_info *b_info, int r, int start);
void	b_to_a(t_info *a_info, t_info *b_info, int r, int start);
void	sort_below_five(t_info *a_info, t_info *b_info, int size);
void	sort_below_three(t_info *a_info, t_info *b_info, int size, int init);
void	sort_three(t_info *a, t_info *b, int first, int second, int third, int init);
void	reverse_rotate(t_info *a_info, t_info *b_info, int a, int b);

#endif
