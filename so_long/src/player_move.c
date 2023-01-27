/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 19:05:23 by jimpark           #+#    #+#             */
/*   Updated: 2023/01/26 18:56:28 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	draw_player(char c, t_map *map, int x, int y)
{
	if (c == 'R' && x % 2 == 0)
		mlx_put_image_to_window(map->mlx, map->win, map->img.right1, \
		x * IMG_SIZE, y * IMG_SIZE);
	else if (c == 'R' && x % 2 == 1)
		mlx_put_image_to_window(map->mlx, map->win, map->img.right2, \
		x * IMG_SIZE, y * IMG_SIZE);
	else if (c == 'L' && x % 2 == 0)
		mlx_put_image_to_window(map->mlx, map->win, map->img.left1, \
		x * IMG_SIZE, y * IMG_SIZE);
	else if (c == 'L' && x % 2 == 1)
		mlx_put_image_to_window(map->mlx, map->win, map->img.left2, \
		x * IMG_SIZE, y * IMG_SIZE);
	else if (c == 'U' && y % 2 == 0)
		mlx_put_image_to_window(map->mlx, map->win, map->img.up1, \
		x * IMG_SIZE, y * IMG_SIZE);
	else if (c == 'U' && y % 2 == 1)
		mlx_put_image_to_window(map->mlx, map->win, map->img.up2, \
		x * IMG_SIZE, y * IMG_SIZE);
	else if (c == 'D' && y % 2 == 0)
		mlx_put_image_to_window(map->mlx, map->win, map->img.down1, \
		x * IMG_SIZE, y * IMG_SIZE);
	else if (c == 'D' && y % 2 == 1)
		mlx_put_image_to_window(map->mlx, map->win, map->img.down2, \
		x * IMG_SIZE, y * IMG_SIZE);
}

void	move_player(t_map *map)
{
	if (map->player.col - map->player.x == -1)
		draw_player('R', map, map->player.x, map->player.y);
	else if (map->player.col - map->player.x == 1)
		draw_player('L', map, map->player.x, map->player.y);
	else if (map->player.row - map->player.y == 1)
		draw_player('U', map, map->player.x, map->player.y);
	else if (map->player.row - map->player.y == -1)
		draw_player('D', map, map->player.x, map->player.y);
	map->player.col = map->player.x;
	map->player.row = map->player.y;
}
