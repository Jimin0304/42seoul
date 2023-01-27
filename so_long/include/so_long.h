/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jimpark <jimpark@student.42seoul.kr>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 21:16:08 by jimpark           #+#    #+#             */
/*   Updated: 2023/01/26 22:30:55 by jimpark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../mlx/mlx.h"
# include <fcntl.h>
# include "get_next_line.h"
# include "../ft_printf/ft_printf.h"

# define IMG_SIZE			64
# define X_EVENT_KEY_PRESS	2
# define X_EVENT_KEY_EXIT	17

# define KEY_W		13
# define KEY_A		0
# define KEY_S		1
# define KEY_D		2
# define KEY_ESC	53

typedef struct s_player{
	int	x;
	int	y;
	int	row;
	int	col;
	int	move;
}				t_player;

typedef struct s_enemy{
	int	x;
	int	y;
}				t_enemy;

typedef struct s_image{
	void	*wall;
	void	*coin1;
	void	*coin2;
	void	*coin3;
	void	*coin4;
	void	*exit;
	void	*ground;
	void	*left1;
	void	*left2;
	void	*right1;
	void	*right2;
	void	*up1;
	void	*up2;
	void	*down1;
	void	*down2;
	void	*enemy1;
	void	*enemy2;
}				t_image;

typedef struct s_check{
	char	**visited;
	int		x;
	int		y;
	int		count_collections;
	int		exit;
}				t_check;

typedef struct s_map{
	void		*mlx;
	void		*win;
	char		**arr;
	int			fd;
	int			count_exit;
	int			count_start;
	int			count_collections;
	int			x_size;
	int			y_size;
	int			width;
	int			height;
	char		*str_line;
	t_player	player;
	t_image		img;
	t_check		check;
	t_enemy		enemy;
}				t_map;

void	init(t_map *map, char *map_name);
void	check_map(t_map *map);
void	free_all(char **arr, int i);
char	*print_err(char *error);
int		key_press(int key_code, t_map *map);
void	draw(char c, t_map *map, int x, int y);
void	success_game(t_map *map);
int		exit_game(void);
char	**set_arr(t_map *map, char **arr);
void	dfs_check(t_map *map);
void	move_player(t_map *map);
void	move_enemy(t_map *map, int count);
int		make_enemy(t_map *map, int cnt);
void	change_coin(t_map *map, int count);
int		score(t_map *map);
int		loop_with_enemy(t_map *map);
int		loop_without_enemy(t_map *map);
int		check_ber(char *str);

#endif
