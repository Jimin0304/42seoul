/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:02:49 by jimpark           #+#    #+#             */
/*   Updated: 2023/01/30 21:02:50 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_argv_size(char **argv)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (argv[i])
	{
		if (ft_strchr(argv[i], 32) != 0)
			size += word_count(argv[i], (char)32);
		else
			size += 1;
		i++;
	}
	return (size);
}

int	*parse_argv(char **argv, int *arr)
{
	int		i;
	int		j;
	int		k;
	char	**tmp;

	i = 0;
	k = 0;
	while (argv[++i])
	{
		j = 0;
		if (ft_strchr(argv[i], 32) != 0)
		{
			tmp = ft_split(argv[i], 32);
			while (tmp[j])
				arr[k++] = ft_atoi(tmp[j++]);
			free_all(tmp, j - 1);
		}
		else
			arr[k++] = ft_atoi(argv[i]);
	}
	arr[k] = '\0';
	return (arr);
}

void	set_info(t_info *info)
{
	info->arr = NULL;
	info->size = 0;
	info->top = NULL;
	info->bottom = NULL;
}

int	arr_to_stack(t_info *a_info, int *arr)
{
	int		i;
	t_node	*newnode;

	i = 0;
	newnode = (t_node *)malloc(sizeof(t_node));
	if (!newnode)
		print_err(-1);
	a_info->top = init_deque(newnode, arr[i]);
	a_info->bottom = a_info->top;
	while (arr[++i])
		push_bottom(a_info, arr[i]);
	return (0);
}
