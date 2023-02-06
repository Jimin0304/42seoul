/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:10:43 by jimpark           #+#    #+#             */
/*   Updated: 2023/02/06 22:32:56 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	arr_to_stack(t_info *a_info, int *arr, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		push_bottom(a_info, arr[i]);
		i++;
	}
	return (0);
}

void	sort_nodes(t_info *a_info, t_info *b_info, char *str)
{
	if (ft_strncmp(str, "pa", 2) == 0)
		checker_pa(a_info, b_info);
	else if (ft_strncmp(str, "pb", 2) == 0)
		checker_pb(a_info, b_info);
	else if (ft_strncmp(str, "sa", 2) == 0)
		checker_sa(a_info);
	else if (ft_strncmp(str, "sb", 2) == 0)
		checker_sb(b_info);
	else if (ft_strncmp(str, "ss", 2) == 0)
		checker_ss(a_info, b_info);
	else if (ft_strncmp(str, "ra", 2) == 0)
		checker_ra(a_info);
	else if (ft_strncmp(str, "rb", 2) == 0)
		checker_rb(b_info);
	else if (ft_strncmp(str, "rr", 2) == 0)
		checker_rr(a_info, b_info);
	else if (ft_strncmp(str, "rra", 3) == 0)
		checker_rra(a_info);
	else if (ft_strncmp(str, "rrb", 3) == 0)
		checker_rrb(b_info);
	else if (ft_strncmp(str, "rrr", 3) == 0)
		checker_rrr(a_info, b_info);
	else
		print_err(-1);
}

void	run_commands(t_info *a_info, t_info *b_info)
{
	char	*str;

	while (1)
	{
		str = get_next_line(0);
		if (!str)
			break ;
		sort_nodes(a_info, b_info, str);
		free(str);
	}
}

int	check_sort(t_info *a_info, t_info *b_info)
{
	if (b_info->size != 0)
		return (-1);
	while (a_info->top->next)
	{
		if (a_info->top->content > a_info->top->next->content)
			return (-1);
		a_info->top = a_info->top->next;
	}
	return (0);
}

int	main(int argc, char *argv[])
{
	t_info	a_info;
	t_info	b_info;
	int		arr_size;
	int		*arr;

	if (argc < 2)
		print_err(1);
	set_info(&a_info);
	set_info(&b_info);
	arr_size = get_argv_size(argv) - 1;
	arr = (int *)malloc(sizeof(int) * arr_size);
	if (!arr)
		print_err(-1);
	arr = parse_argv(argv, arr);
	arr_to_stack(&a_info, arr, arr_size);
	run_commands(&a_info, &b_info);
	if (check_sort(&a_info, &b_info) == -1)
		write(1, "KO\n", 3);
	else
		write(1, "OK\n", 3);
}
