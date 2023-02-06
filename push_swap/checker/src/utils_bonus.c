/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 17:57:13 by jimpark           #+#    #+#             */
/*   Updated: 2023/02/06 22:11:07 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/push_swap_bonus.h"

int	print_err(int i)
{
	if (i == -1)
		write(1, "Error\n", 6);
	exit(1);
}

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

void	set_info(t_info *info)
{
	info->arr = NULL;
	info->size = 0;
	info->top = NULL;
	info->bottom = NULL;
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


void	free_all(char **arr, int i)
{
	int	j;

	j = 0;
	while (j <= i)
		free(arr[j++]);
	free(arr);
}
