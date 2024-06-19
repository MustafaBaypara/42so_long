/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaypara <mbaypara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:52:52 by mbaypara          #+#    #+#             */
/*   Updated: 2024/05/22 11:52:54 by mbaypara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	while_to_map(t_master *master, t_file *f, int fd)
{
	close(fd);
	if (f->buffer[f->index] != '1')
		error_msg("Invalid map, should start with 1\n", master);
}

void	starter(t_file *f, int *i, int i2)
{
	f->index = 0;
	f->buffer[BUF_SIZE - 1] = 0;
	*i = i2;
}

void	get_array(t_master *master, char *fname, t_parse_info *info)
{
	t_file	f;
	int		x;
	int		i;
	size_t	readed;

	open_file(&f.fd, fname, 0, master);
	master->map->map2d = alloc_map(master->map->h, master->map->w);
	starter(&f, &i, -1);
	readed = read(f.fd, &f.buffer, BUF_SIZE - 2);
	if (readed > 0)
	{
		while_to_map(master, &f, f.fd);
		while (++i < (*master->map).h)
		{
			x = -1;
			while (++x < master->map->w && f.buffer[f.index] != '\n')
				master->map->map2d[i][x] = check_elem(f.buffer[f.index++],
						info, master);
			f.index++;
		}
	}
	else
		error_msg("Error reading file\n", master);
}

int	validate_array(t_master *master, int width, int height, t_parse_info info)
{
	int	i;

	i = -1;
	while (++i < width)
	{
		if (master->map->map2d[0][i] != 1)
			error_msg("Top wall not initialized\n", master);
		if (master->map->map2d[height - 1][i] != 1)
			error_msg("Bottom wall not initialized\n", master);
	}
	i = -1;
	while (++i < height)
	{
		if (master->map->map2d[i][0] != 1)
			error_msg("Left wall not initialized\n", master);
		if (master->map->map2d[i][width - 1] != 1)
			error_msg("Rigth wall not initialized\n", master);
	}
	if (info.c_exists == 0 || info.e_exists != 1 || info.p_exists != 1)
		error_msg("NOT A COLECT OR EXIT OR NO OR MORE THAN ONE PLAYER\n",
			master);
	return (1);
}

void	parse_file(int fd, char *file_name, t_parse_info *info,
		t_master *master)
{
	t_file		f;
	int			counter;
	size_t		readed;

	starter(&f, &counter, 0);
	readed = read(fd, &f.buffer, BUF_SIZE - 2);
	f.buffer[readed] = 0;
	if (readed > 0 && readed < BUF_SIZE)
	{
		while_to_map(master, &f, fd);
		while (is_valid(master, &f.buffer[f.index]))
		{
			if (counter == 0)
				width_map(master, f.buffer, &counter, &f.index);
			if (f.buffer[f.index++] == '\n')
				master->map->h++;
		}
		parse_width_height(master);
	}
	else
		error_msg("Error reading file or too much input for mlx\n", master);
	get_array(master, file_name, info);
	if (!validate_array(master, master->width, master->height, *info))
		error_msg("Something wrong with the map\n", master);
}
