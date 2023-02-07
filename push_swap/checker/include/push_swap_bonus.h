/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:29:13 by jimpark           #+#    #+#             */
/*   Updated: 2023/02/07 20:41:31 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../../include/struct.h"
# include "../../lib/ft_printf/ft_printf.h"
# include "../../lib/libft/libft.h"
# include "gnl_bonus.h"

int	print_err_b(char *str);
void	checker_pa(t_info *a_info, t_info *b_info);
void	checker_pb(t_info *a_info, t_info *b_info);
void	checker_rra(t_info *a_info);
void	checker_rrb(t_info *b_info);
void	checker_rrr(t_info *a_info, t_info *b_info);
void	checker_ra(t_info *a_info);
void	checker_rb(t_info *b_info);
void	checker_rr(t_info *a_info, t_info *b_info);
void	checker_sa(t_info *a_info);
void	checker_sb(t_info *b_info);
void	checker_ss(t_info *a_info, t_info *b_info);
int		arr_to_stack(t_info *a_info, int *arr, int size);
int		get_argv_size(char **argv);
void	set_info(t_info *info);
int		*parse_argv(char **argv, int *arr);
void	free_all(char **arr, int i);
void	push_top(t_info *info, int content);
void	push_bottom(t_info *info, int content);
void	pop_top(t_info *info);
void	pop_bottom(t_info *info);
int 	word_count(char *s, char c);
void	check_duplicate(int *arr, int size);
int		ft_strcmp(char *s1, char *s2);

#endif
