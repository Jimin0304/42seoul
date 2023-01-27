/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 16:08:32 by jimpark           #+#    #+#             */
/*   Updated: 2023/01/26 18:55:30 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	move_up(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y - 1;
	if (map->arr[y][x] == '1')
		return ;
	else if (map->arr[y][x] == '0' || map->arr[y][x] == 'C')
	{
		map->player.y = y;
		if (map->arr[y][x] == 'C')
		{
			map->count_collections--;
			draw('0', map, x * IMG_SIZE, y * IMG_SIZE);
		}
		draw('0', map, x * IMG_SIZE, (y + 1) * IMG_SIZE);
		move_player(map);
		map->arr[y][x] = 'P';
		map->arr[y + 1][x] = '0';
		ft_printf("move : %d\n", ++map->player.move);
	}
	else if (map->arr[y][x] == 'E' && map->count_collections == 0)
		success_game(map);
}

void	move_down(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x;
	y = map->player.y + 1;
	if (map->arr[y][x] == '1')
		return ;
	else if (map->arr[y][x] == '0' || map->arr[y][x] == 'C')
	{
		map->player.y = y;
		if (map->arr[y][x] == 'C')
		{
			map->count_collections--;
			draw('0', map, x * IMG_SIZE, y * IMG_SIZE);
		}
		draw('0', map, x * IMG_SIZE, (y - 1) * IMG_SIZE);
		move_player(map);
		map->arr[y][x] = 'P';
		map->arr[y - 1][x] = '0';
		ft_printf("move : %d\n", ++map->player.move);
	}
	else if (map->arr[y][x] == 'E' && map->count_collections == 0)
		success_game(map);
}

void	move_right(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x + 1;
	y = map->player.y;
	if (map->arr[y][x] == '1')
		return ;
	else if (map->arr[y][x] == '0' || map->arr[y][x] == 'C')
	{
		map->player.x = x;
		if (map->arr[y][x] == 'C')
		{
			map->count_collections--;
			draw('0', map, x * IMG_SIZE, y * IMG_SIZE);
		}
		draw('0', map, (x - 1) * IMG_SIZE, y * IMG_SIZE);
		move_player(map);
		map->arr[y][x] = 'P';
		map->arr[y][x - 1] = '0';
		ft_printf("move : %d\n", ++map->player.move);
	}
	else if (map->arr[y][x] == 'E' && map->count_collections == 0)
		success_game(map);
}

void	move_left(t_map *map)
{
	int	x;
	int	y;

	x = map->player.x - 1;
	y = map->player.y;
	if (map->arr[y][x] == '1')
		return ;
	else if (map->arr[y][x] == '0' || map->arr[y][x] == 'C')
	{
		map->player.x = x;
		if (map->arr[y][x] == 'C')
		{
			map->count_collections--;
			draw('0', map, x * IMG_SIZE, y * IMG_SIZE);
		}
		draw('0', map, (x + 1) * IMG_SIZE, y * IMG_SIZE);
		move_player(map);
		map->arr[y][x] = 'P';
		map->arr[y][x + 1] = '0';
		ft_printf("move : %d\n", ++map->player.move);
	}
	else if (map->arr[y][x] == 'E' && map->count_collections == 0)
		success_game(map);
}

int	key_press(int key_code, t_map *map)
{
	if (key_code == KEY_W)
		move_up(map);
	else if (key_code == KEY_S)
		move_down(map);
	else if (key_code == KEY_A)
		move_left(map);
	else if (key_code == KEY_D)
		move_right(map);
	else if (key_code == KEY_ESC)
		exit_game();
	return (0);
}
