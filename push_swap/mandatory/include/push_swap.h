/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 22:02:10 by jimpark           #+#    #+#             */
/*   Updated: 2023/02/08 18:49:29 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../lib/ft_printf/ft_printf.h"
# include "../lib/libft/libft.h"
# include "struct.h"
# include "command.h"
# include "../../bonus/include/push_swap_bonus.h"

int		print_err(void);
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
void	first_third_second(t_info *a_info);
void	second_first_third(t_info *a_info);
void	second_third_first(t_info *a_info, t_info *b_info);
void	third_first_second(t_info *a_info, t_info *b_info);
void	third_second_first(t_info *a_info, t_info *b_info);
void	a_to_b(t_info *a_info, t_info *b_info, int r, int start);
void	b_to_a(t_info *a_info, t_info *b_info, int r, int start);
void	sort_below_five(t_info *a_info, t_info *b_info, int size);
void	sort_below_three(t_info *a_info, t_info *b_info, int size);
void	sort_three(t_info *a_info, t_info *b_info);
void	reverse_rotate(t_info *a_info, t_info *b_info, int a, int b);
int		*make_int_arr_and_set(int size);
int		*a_to_b_action(t_info *a_info, t_info *b_info, int r, int start);
int		*b_to_a_action(t_info *a_info, t_info *b_info, int r, int start);
void	free_nodes(t_info *info);

#endif
