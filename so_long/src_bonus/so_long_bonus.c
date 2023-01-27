/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 19:56:10 by jimpark           #+#    #+#             */
/*   Updated: 2023/01/26 22:37:08 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw(char c, t_map *map, int x, int y)
{
	if (c == '0')
		mlx_put_image_to_window(map->mlx, map->win, map->img.ground, x, y);
	else if (c == '1')
		mlx_put_image_to_window(map->mlx, map->win, map->img.wall, x, y);
	else if (c == 'P' || c == 'C' || c == 'E' || c == 'X')
	{
		mlx_put_image_to_window(map->mlx, map->win, map->img.ground, x, y);
		if (c == 'P')
			mlx_put_image_to_window(map->mlx, map->win, map->img.down1, x, y);
		else if (c == 'C')
			mlx_put_image_to_window(map->mlx, map->win, map->img.coin1, x, y);
		else if (c == 'E')
			mlx_put_image_to_window(map->mlx, map->win, map->img.exit, x, y);
		else if (c == 'X')
			mlx_put_image_to_window(map->mlx, map->win, map->img.enemy1, x, y);
	}
}

void	drawmap(t_map *map)
{
	int	i;
	int	x;
	int	y;

	x = 0;
	y = 0;
	i = 0;
	while (map->str_line[i])
	{
		while (map->str_line[i] != '\n')
		{
			draw(map->str_line[i], map, x, y);
			i++;
			x += IMG_SIZE;
		}
		i++;
		x = 0;
		y += IMG_SIZE;
	}
}

int	loop_with_enemy(t_map *map)
{
	static unsigned int	count;

	count++;
	move_enemy(map, count % 50);
	change_coin(map, (count / 20) % 5);
	score(map);
	return (0);
}

int	loop_without_enemy(t_map *map)
{
	static unsigned int	cnt;

	cnt++;
	change_coin(map, (cnt / 20) % 5);
	score(map);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_map	map;
	int		cnt;

	cnt = 0;
	if (argc != 2 || check_ber(argv[1]) != 0)
		print_err("잘못된 입력입니다.");
	init(&map, argv[1]);
	check_map(&map);
	dfs_check(&map);
	drawmap(&map);
	if (make_enemy(&map, cnt) == 0)
		mlx_loop_hook(map.mlx, &loop_with_enemy, &map);
	else
		mlx_loop_hook(map.mlx, &loop_without_enemy, &map);
	mlx_hook(map.win, X_EVENT_KEY_PRESS, 0, &key_press, &map);
	mlx_hook(map.win, X_EVENT_KEY_EXIT, 0, &exit_game, &map);
	mlx_loop(map.mlx);
	return (0);
}
