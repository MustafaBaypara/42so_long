/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaypara <mbaypara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:52:39 by mbaypara          #+#    #+#             */
/*   Updated: 2024/05/26 14:06:56 by mbaypara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_master(t_master *master)
{
	master->mlx = NULL;
	master->win = NULL;
	master->player_moves = 0;
	master->height = 0;
	master->width = 0;
}

void	init_map(t_map **map)
{
	*map = malloc(sizeof(t_map) + 1);
	if (!*map)
		error_msg("Error\nMalloc failed\n", 0);
	(*map)->h = 1;
	(*map)->w = 0;
	(*map)->collect = 0;
	(*map)->pos_x_y.x = 0;
	(*map)->pos_x_y.y = 0;
	(*map)->map2d = NULL;
}

void	init_parse_info(t_parse_info *info)
{
	info->c_exists = 0;
	info->e_exists = 0;
	info->p_exists = 0;
}

int	main(int ac, char **av)
{
	int				fd;
	t_master		master;
	t_parse_info	info;

	if (ac != 2)
		error_msg("Error\nInvalid number of arguments\n", 0);
	if (!check_file(av[1], ".ber"))
		error_msg("Error\nInvalid file extension\n", 0);
	init_map(&master.map);
	init_master(&master);
	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		error_msg("Error\nInvalid file\n", &master);
	init_parse_info(&info);
	parse_file(fd, av[1], &info, &master);
	master.col.number_of_c = info.c_exists;
	close(fd);
	start_game(&master);
	quit_program(&master);
	return (0);
}
