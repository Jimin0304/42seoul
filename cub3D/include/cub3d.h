/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: huipark <huipark@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/24 18:18:12 by huipark           #+#    #+#             */
/*   Updated: 2023/06/25 14:14:28 by huipark          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "get_next_line.h"
# include "../mlx/mlx.h"
# include "../Libft/libft.h"
# include <stdio.h>
# include <fcntl.h>
# include <stdlib.h>
# include <math.h>

# define HEIGHT 1080
# define WIDTH 1920

# define SIZE 64

# define X_EVENT_KEY_PRESS			2
# define X_EVENT_KEY_RELEASE		3
# define X_EVENT_KEY_EXIT			17 //exit key code

# define KEY_ESC			53
# define KEY_Q			12
# define KEY_W			13
# define KEY_E			14
# define KEY_R			15
# define KEY_A			0
# define KEY_S			1
# define KEY_D			2
# define KEY_LEFT_ARROW 123
# define KEY_RIGHT_ARROW 124

typedef struct s_ray
{
	double	dir_x;
	double	dir_y;
	double	camera_x;
	double	side_dist_x;
	double	side_dist_y;
	double	perp_wall_dist;
	double	delta_dist_x;
	double	delta_dist_y;
	double	wall_x;
	double	step;
	double	tex_pos;
	int		tex_x;
	int		tex_y;
	int		map_x;
	int		map_y;
	int		hit;
	int		side;
	int		x;
	int		step_x;
	int		step_y;
	int		line_height;
	int		draw_start;
	int		draw_end;
	int		tex_num;
}				t_ray;

typedef struct s_img
{
	void	*img;
	int		*data;

	int		size_l;
	int		bpp;
	int		endian;
	int		img_width;
	int		img_height;

	char	*no;
	char	*so;
	char	*we;
	char	*ea;
	char	*f;
	char	*c;
}				t_img;

typedef struct s_rgb
{
	int	r;
	int	g;
	int	b;
	int	rgb;
}				t_rgb;

typedef struct s_map
{
	char	**map;
	char	**int_map;
	int		**buf;
	int		**texture;
	int		re_buf;
	int		map_height;
	int		max_width;
}				t_map;

typedef struct s_playsr
{
	double		x;
	double		y;
	double		dir_x;
	double		dir_y;
	double		plane_x;
	double		plane_y;
	double		move_speed;
	double		rot_speed;
	char		player_direction;
}				t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	t_img		img;
	t_map		map_info;
	t_player	player;
	t_rgb		f_rgb;
	t_rgb		c_rgb;
}				t_game;

//main.c
int		main_loop(t_game *game);

//utils.c
void	error(char *msg, char *msg2);
void	*wrap_malloc(size_t s);
int		exit_game(void);
int		check_format(char *str);

//parse.c
void	check_texture(t_game *game, char *line);
void	texture_parsing(t_game *game, char **map);
void	parse_map(t_game *game);

//init.c
void	nullify_struct_members(t_game *game);
void	init(t_game *game, char *argv);
void	init_rgb(t_game *game);

//init_utils.c
int		check_map_error(char c);
int		check_invalid_map(int i, int j, int prev_line_len, t_game *game);
void	check_player_position(char **map, int x, int y);
void	find_player_direction(t_player *player, char c, int i, int j);
void	init_player_direction(t_player *player, char c);

//key_press_utils.c
int		key_press(int key, t_game *game);
void	press_w(t_game *game);
void	press_s(t_game *game);
void	press_a(t_game *game);
void	press_d(t_game *game);
void	press_right(t_player *player);
void	press_left(t_player *player);

//draw.c
void	carc(t_game *game);
void	draw(t_game *game);

//raycasting.c
void	calculate_side_distances(t_game *game, t_ray *info);
void	find_wall_collision(t_game *game, t_ray *info);
void	calculate_drawing(t_ray *info);
void	calculate_wall_texture(t_game *game, t_ray *info);
void	draw_texture(t_game *game, t_ray *info);

//init_map.c
void	init_int_map(t_game *game);
void	init_game_map(t_game *game);

//init_texture.c
void	init_texture(t_game *game);

//init_rgb.c
void	init_rgb(t_game *game);

#endif
