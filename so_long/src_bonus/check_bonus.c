/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:38:49 by jimpark           #+#    #+#             */
/*   Updated: 2023/01/26 22:37:37 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

char	**set_arr(t_map	*map, char	**arr)
{
	int	i;

	arr = (char **)malloc(sizeof(char *) * map->y_size);
	if (!arr)
		print_err("malloc error");
	i = -1;
	while (++i < map->y_size)
	{
		arr[i] = (char *)malloc(sizeof(char) * map->x_size + 1);
		if (!arr[i])
		{
			print_err("malloc error");
			free_all(map->arr, i);
		}
	}
	i = 0;
	while (i < map->y_size)
	{
		ft_strlcpy(arr[i], map->str_line + \
		i * (map->x_size + 1), (map->x_size + 1));
		i++;
	}
	return (arr);
}

void	check_components(t_map *map)
{
	int			w;
	int			h;

	h = -1;
	while (++h < map->y_size)
	{
		w = -1;
		while (++w < map->x_size)
		{
			if (map->arr[h][w] == 'E')
				map->count_exit++;
			else if (map->arr[h][w] == 'C')
				map->count_collections++;
			else if (map->arr[h][w] == 'P')
			{
				map->count_start++;
				map->player.x = w;
				map->player.y = h;
				map->player.col = w;
				map->player.row = h;
			}
			else if (map->arr[h][w] != '0' && map->arr[h][w] != '1')
				print_err("맵에 허용되지 않은 문자가 있습니다.");
		}
	}
}

void	check_wall(t_map *map, char *wall, int line)
{
	int	i;

	if (line == 0 || line == map->y_size - 1)
	{
		i = 0;
		while (wall[i])
		{
			if (wall[i++] != '1')
				print_err("위아래 벽이 뚫려 있습니다.");
		}
	}
	if (wall[0] != '1' || wall[map->x_size - 1] != '1')
		print_err("옆 쪽 벽이 뚫려 있습니다.");
}

void	check_map(t_map *map)
{
	int		i;
	char	**arr;

	if (map->x_size < 3 || map->y_size < 3 || map->x_size * map->y_size < 15)
		print_err("유효하지 않은 맵입니다.");
	arr = NULL;
	map->arr = set_arr(map, arr);
	i = 0;
	while (i < map->y_size)
	{
		check_wall(map, map->arr[i], i);
		i++;
	}
	check_components(map);
	if (map->count_exit != 1)
		print_err("탈출구가 1개가 아닙니다.");
	else if (map->count_collections < 1)
		print_err("수집품이 1개 미만입니다.");
	else if (map->count_start != 1)
		print_err("시작 지점이 1개가 아닙니다.");
}

int	check_ber(char *str)
{
	int	n;

	n = ft_strlen(str);
	if (n < 5)
		return (-1);
	if (str[n - 4] != '.')
		return (-1);
	else if (str[n - 3] != 'b')
		return (-1);
	else if (str[n - 2] != 'e')
		return (-1);
	else if (str[n - 1] != 'r')
		return (-1);
	return (0);
}
