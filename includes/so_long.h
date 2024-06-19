/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaypara <mbaypara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:52:02 by mbaypara          #+#    #+#             */
/*   Updated: 2024/05/22 12:11:08 by mbaypara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdbool.h>
# include "../mlx/mlx.h"
# include "../libft/libft.h"

# define IMG_H	64
# define IMG_W	64
# define FLOOR 0
# define WALL 1
# define P 2
# define C 3
# define E 4
# define ESC 53
# define MV_U 13
# define MV_D 1
# define MV_R 2
# define MV_L 0
# define BUF_SIZE 17000
# define MAX_MAP 128

typedef struct struct_file
{
	int		fd;
	char	buffer[BUF_SIZE];
	int		index;
}		t_file;

typedef struct struct_vector
{
	int	x;
	int	y;
}		t_vector;

typedef struct parse_info
{
	int	e_exists;
	int	c_exists;
	int	p_exists;
}		t_parse_info;

typedef struct struct_map
{
	int			w;
	int			h;
	int			**map2d;
	int			collect;
	t_vector	pos_x_y;
}		t_map;

typedef struct struct_player
{
	void		*img;
	void		*img_up;
	void		*img_down;
	void		*img_left;
	void		*img_right;
	t_vector	pos;
	t_vector	last;
}		t_player;

typedef struct struct_collect
{
	void	*img;
	int		number_of_c;
}		t_collect;

typedef struct struct_master
{
	int			height;
	int			width;
	void		*mlx;
	void		*win;
	int			player_moves;
	t_player	pla;
	void		*floor;
	t_map		*map;
	t_collect	col;
	void		*cave;
	void		*wallground;
	void		*ground;
}		t_master;

void	error_msg(char *str, void *master);
void	width_map(t_master *m, char *buffer, int *counter, int *index);
void	open_file(int *fd, char *fname, int opt, t_master *master);
int		check_elem(char c, t_parse_info *info, t_master *master);
int		**alloc_map(int size, int size2);
void	update_coll(t_master *master, int x, int y);
int		not_wall(t_master *master, int x, int y);
void	update_positions(t_master *master, int key);
int		exit_hook(t_master *master);
void	images_init(t_master *master);
void	start_game(t_master *m);
int		game_finished(t_master *master, int x, int y);
void	quit_program(t_master *master);
void	draw(t_master *master);
void	put_img(t_master *master, void *img, t_map *map);
void	get_map_cordinates(t_map *map, int x, int y);
void	refresh_map(t_master *master, int newx, int newy);
int		check_file(char *file, char *ext);
void	parse_file(int fd, char *file_name,
			t_parse_info *info, t_master *master);
void	parse_width_height(t_master *master);
int		is_valid(t_master *master, char *array);

#endif
