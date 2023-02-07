/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 22:10:43 by jimpark           #+#    #+#             */
/*   Updated: 2023/02/07 20:43:40 by jimpark          ###   ########.fr       */
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
	if (!(ft_strcmp(str, "sa\n")))
		checker_sa(a_info);
	else if (!(ft_strcmp(str, "sb\n")))
		checker_sb(b_info);
	else if (!(ft_strcmp(str, "ss\n")))
		checker_ss(a_info, b_info);
	else if (!(ft_strcmp(str, "rr\n")))
		checker_rr(a_info, b_info);
	else if (!(ft_strcmp(str, "ra\n")))
		checker_ra(a_info);
	else if (!(ft_strcmp(str, "rb\n")))
		checker_rb(b_info);
	else if (!(ft_strcmp(str, "rrr\n")))
		checker_rrr(a_info, b_info);
	else if (!(ft_strcmp(str, "rra\n")))
		checker_rra(a_info);
	else if (!(ft_strcmp(str, "rrb\n")))
		checker_rrb(b_info);
	else if (!(ft_strcmp(str, "pa\n")))
		checker_pa(a_info, b_info);
	else if (!(ft_strcmp(str, "pb\n")))
		checker_pb(a_info, b_info);
	else
		print_err_b(str);
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
		free (str);
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
// #include <stdio.h>
int	main(int argc, char *argv[])
{
	t_info	a_info;
	t_info	b_info;
	int		arr_size;
	int		*arr;

	if (argc < 2)
		exit(1);
	set_info(&a_info);
	set_info(&b_info);
	arr_size = get_argv_size(argv) - 1;
	arr = (int *)malloc(sizeof(int) * arr_size);
	if (!arr)
		return (0);
	arr = parse_argv(argv, arr);
	arr_to_stack(&a_info, arr, arr_size);
	check_duplicate(arr, arr_size);
	run_commands(&a_info, &b_info);
	if (check_sort(&a_info, &b_info) == -1)
	{
		// while(a_info.top)
		// {
		// 	printf("%d\n", a_info.top->content);
		// 	a_info.top = a_info.top->next;
		// }
		write(1, "KO\n", 3);
	}
	else
		write(1, "OK\n", 3);

}
