/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/30 21:02:49 by jimpark           #+#    #+#             */
/*   Updated: 2023/02/06 17:28:44 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap.h"

int	get_argv_size(char **argv)
{
	int	i;
	int	size;

	i = 0;
	size = 0;
	while (argv[i])
	{
		if (ft_strlen(argv[i]) == 0)
			print_err(-1);
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
	return (arr);
}

void	set_info(t_info *info)
{
	info->arr = NULL;
	info->size = 0;
	info->top = NULL;
	info->bottom = NULL;
}

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

int	sort_arr_check(t_info *info, int *arr, int size)
{
	int	i;
	int	j;
	int	tmp;
	int	check;

	i = -1;
	check = 0;
	while (++i < size)
	{
		j = -1;
		while (++j < size - 1 - i)
		{
			if (arr[j] > arr[j + 1])
			{
				tmp = arr[j];
				arr[j] = arr[j + 1];
				arr[j + 1] = tmp;
				check++;
			}
			else if (arr[j] == arr[j + 1])
				print_err(-1);
		}
	}
	info->arr = arr;
	return (check);
}
