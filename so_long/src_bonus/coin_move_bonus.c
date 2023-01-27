/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   coin_move_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 18:16:50 by jimpark           #+#    #+#             */
/*   Updated: 2023/01/26 22:37:34 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_coin(int i, t_map *map, int x, int y)
{
	if (i == 1)
		mlx_put_image_to_window(map->mlx, map->win, map->img.coin1, x, y);
	else if (i == 2)
		mlx_put_image_to_window(map->mlx, map->win, map->img.coin2, x, y);
	else if (i == 3)
		mlx_put_image_to_window(map->mlx, map->win, map->img.coin3, x, y);
	else if (i == 4)
		mlx_put_image_to_window(map->mlx, map->win, map->img.coin4, x, y);
}

void	change_coin(t_map *map, int count)
{
	int	x;
	int	y;

	y = -1;
	while (++y < map->y_size)
	{
		x = -1;
		while (++x < map->x_size)
		{
			if (map->arr[y][x] == 'C')
			{
				if (count != 0)
					draw('0', map, x * IMG_SIZE, y * IMG_SIZE);
				if (count == 1)
					draw_coin(2, map, x * IMG_SIZE, y * IMG_SIZE);
				else if (count == 2)
					draw_coin(3, map, x * IMG_SIZE, y * IMG_SIZE);
				else if (count == 3)
					draw_coin(4, map, x * IMG_SIZE, y * IMG_SIZE);
				else if (count == 4)
					draw_coin(1, map, x * IMG_SIZE, y * IMG_SIZE);
			}
		}
	}
}
