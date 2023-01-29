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
		size += 1;
		i++;
	}
	return (size);
}

int	parse_argv(char **argv, t_info *info)
{
	int		i;
	int		j;
	int		k;
	int		size;
	char	**tmp;

	size = get_argv_size(argv);
	info->arr = (int *)malloc(sizeof(int) * (size + 1));
	if (!info->arr)
		print_err(-1);
	i = -1;
	k = 0;
	while (argv[++i])
	{
		j = 0;
		if (ft_strchr(argv[i], 32) != 0)
		{
			tmp = ft_split(argv[i], 32);
			while (tmp[j])
				info->arr[k++] = ft_atoi(tmp[j]);
			free_all(tmp, j - 1);
		}
		else
			info->arr[k++] = ft_atoi(argv[i]);
	}
	info->arr[k] = '\0';
	return (0);
}

void	set_info(t_info *info)
{
	info->arr = NULL;
	info->size_a = 0;
	info->size_b = 0;
	info->top_a = NULL;
	info->bottom_a = NULL;
	info->top_b = NULL;
	info->bottom_b = NULL;
}

int	arr_to_stack(t_info *info)
{
	int	i;

	while (info->arr[i])
	{
		push_bottom(info, info->bottom_a, info->arr[i]);
		i++;
	}
	return (0);
}