/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   make_enemy_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 19:42:52 by jimpark           #+#    #+#             */
/*   Updated: 2023/01/26 22:37:20 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	make_enemy(t_map *map, int cnt)
{
	int	check;
	int	x;
	int	y;

	check = 0;
	while (check != 1 && cnt < 3)
	{
		x = rand() % map->x_size;
		y = rand() % map->y_size;
		if (map->arr[y][x] == '0')
		{
			if (map->arr[y - 1][x] == '0' || map->arr[y + 1][x] == '0' \
			|| map->arr[y][x - 1] == '0' || map->arr[y][x + 1] == '0')
			{
				check = 1;
				map->enemy.x = x;
				map->enemy.y = y;
				draw('X', map, x * IMG_SIZE, y * IMG_SIZE);
				return (0);
			}
			cnt++;
		}
	}
	return (-1);
}

void	draw_enemy(char c, t_map *map, int x, int y)
{
	if (c == '0')
		mlx_put_image_to_window(map->mlx, map->win, \
		map->img.ground, x * IMG_SIZE, y * IMG_SIZE);
	if (c == 'X' && x % 2 == 1)
		mlx_put_image_to_window(map->mlx, map->win, \
		map->img.enemy1, x * IMG_SIZE, y * IMG_SIZE);
	if (c == 'X' && x % 2 == 0)
		mlx_put_image_to_window(map->mlx, map->win, \
		map->img.enemy2, x * IMG_SIZE, y * IMG_SIZE);
}

void	check_road(t_map *map, char c, int random)
{
	if (c == '0' || c == 'P')
	{
		if (random == 0)
		{
			map->enemy.y += 1;
			draw_enemy('0', map, map->enemy.x, map->enemy.y - 1);
		}
		else if (random == 1)
		{
			map->enemy.y -= 1;
			draw_enemy('0', map, map->enemy.x, map->enemy.y + 1);
		}
		else if (random == 2)
		{
			map->enemy.x += 1;
			draw_enemy('0', map, map->enemy.x - 1, map->enemy.y);
		}
		else if (random == 3)
		{
			map->enemy.x -= 1;
			draw_enemy('0', map, (map->enemy.x + 1), map->enemy.y);
		}
		draw_enemy('X', map, map->enemy.x, map->enemy.y);
	}
}

void	move_enemy(t_map *map, int count)
{
	int	random;

	if ((map->player.x == map->enemy.x) && (map->player.y == map->enemy.y))
	{
		ft_printf("you die !");
		exit(0);
	}
	if (count == 0)
	{
		random = rand() % 4;
		if (random == 0)
			check_road(map, map->arr[map->enemy.y + 1][map->enemy.x], random);
		else if (random == 1)
			check_road(map, map->arr[map->enemy.y - 1][map->enemy.x], random);
		else if (random == 2)
			check_road(map, map->arr[map->enemy.y][map->enemy.x + 1], random);
		else if (random == 3)
			check_road(map, map->arr[map->enemy.y][map->enemy.x - 1], random);
	}
}
