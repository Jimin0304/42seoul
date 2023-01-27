/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:37:32 by jimpark           #+#    #+#             */
/*   Updated: 2023/01/26 22:37:24 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

void	set_map(t_map *map, t_image *img)
{
	int		w;
	int		h;

	img->wall = mlx_xpm_file_to_image(map->mlx, "./textures/w.xpm", &w, &h);
	img->coin1 = mlx_xpm_file_to_image(map->mlx, "./textures/c1.xpm", &w, &h);
	img->coin2 = mlx_xpm_file_to_image(map->mlx, "./textures/c2.xpm", &w, &h);
	img->coin3 = mlx_xpm_file_to_image(map->mlx, "./textures/c3.xpm", &w, &h);
	img->coin4 = mlx_xpm_file_to_image(map->mlx, "./textures/c4.xpm", &w, &h);
	img->exit = mlx_xpm_file_to_image(map->mlx, "./textures/p.xpm", &w, &h);
	img->ground = mlx_xpm_file_to_image(map->mlx, "./textures/g.xpm", &w, &h);
	img->left1 = mlx_xpm_file_to_image(map->mlx, "./textures/l1.xpm", &w, &h);
	img->left2 = mlx_xpm_file_to_image(map->mlx, "./textures/l3.xpm", &w, &h);
	img->right1 = mlx_xpm_file_to_image(map->mlx, "./textures/r1.xpm", &w, &h);
	img->right2 = mlx_xpm_file_to_image(map->mlx, "./textures/r3.xpm", &w, &h);
	img->up1 = mlx_xpm_file_to_image(map->mlx, "./textures/b1.xpm", &w, &h);
	img->up2 = mlx_xpm_file_to_image(map->mlx, "./textures/b2.xpm", &w, &h);
	img->down1 = mlx_xpm_file_to_image(map->mlx, "./textures/f1.xpm", &w, &h);
	img->down2 = mlx_xpm_file_to_image(map->mlx, "./textures/f2.xpm", &w, &h);
	img->enemy1 = mlx_xpm_file_to_image(map->mlx, "./textures/e1.xpm", &w, &h);
	img->enemy2 = mlx_xpm_file_to_image(map->mlx, "./textures/e2.xpm", &w, &h);
}

void	map_read(t_map *map, char *map_name)
{
	char	*line;

	map->fd = open(map_name, O_RDONLY);
	if (map->fd < 0)
		print_err("잘못된 fd 입니다.");
	line = get_next_line(map->fd);
	if (!line)
		print_err("맵이 존재하지 않습니다.");
	map->x_size = ft_strlen(line) - 1;
	map->y_size = 0;
	map->str_line = ft_strdup(line);
	free(line);
	while (line)
	{
		map->y_size++;
		line = get_next_line(map->fd);
		if ((line != 0) && (map->x_size != ft_strlen(line) - 1))
			print_err("맵의 줄 길이가 다릅니다.");
		if (line)
			map->str_line = ft_strjoin(map->str_line, line);
		free(line);
	}
	close(map->fd);
}

void	init(t_map *map, char *map_name)
{
	map->count_exit = 0;
	map->count_start = 0;
	map->count_collections = 0;
	map->player.move = 0;
	map_read(map, map_name);
	map->mlx = mlx_init();
	if (!map->mlx)
		print_err("MLX INIT ERROR");
	set_map(map, &map->img);
	map->win = mlx_new_window(map->mlx, \
	map->x_size * IMG_SIZE, map->y_size * IMG_SIZE, "jimpark");
	if (!map->win)
		print_err("MLX WINDOW OPEN ERROR");
}
