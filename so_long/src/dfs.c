/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dfs.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 20:08:22 by jimpark           #+#    #+#             */
/*   Updated: 2023/01/26 18:21:51 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	dfs(t_map *map, int x, int y)
{
	const int	add_x[4] = {0, 0, -1, 1};
	const int	add_y[4] = {-1, 1, 0, 0};
	int			move_x;
	int			move_y;
	int			i;

	map->check.visited[y][x] = '1';
	i = 0;
	if (map->arr[y][x] == 'C')
		map->check.count_collections--;
	if (map->arr[y][x] == 'E')
	{
		map->check.exit = 1;
		return ;
	}
	while (i < 4)
	{
		move_x = x + add_x[i];
		move_y = y + add_y[i];
		if (map->arr[move_y][move_x] != '1' \
		&& map->check.visited[move_y][move_x] == '0')
			dfs(map, move_x, move_y);
		i++;
	}
}

void	dfs_check(t_map *map)
{
	int		i;
	int		j;
	char	**visited;

	map->check.count_collections = map->count_collections;
	map->check.x = map->player.x;
	map->check.y = map->player.y;
	map->check.exit = 0;
	visited = NULL;
	map->check.visited = set_arr(map, visited);
	i = -1;
	while (++i < map->y_size)
	{
		j = -1;
		while (++j < map->x_size)
			map->check.visited[i][j] = '0';
	}
	dfs(map, map->check.x, map->check.y);
	if (!map->check.exit || map->check.count_collections)
		print_err("유효하지 않은 맵입니다.");
	free_all (map->check.visited, map->y_size - 1);
}
