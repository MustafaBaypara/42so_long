/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaypara <mbaypara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:52:15 by mbaypara          #+#    #+#             */
/*   Updated: 2024/06/19 18:24:45 by mbaypara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	quit_program(t_master *master)
{
	int	i;

	i = -1;
	free(master->map->map2d);
	free(master->map);
	exit(0);
}

int	game_finished(t_master *master, int x, int y)
{
	if (master->map->map2d[y][x] == E && master->col.number_of_c <= 0)
		return (1);
	else
		return (0);
}

int	exit_hook(t_master *master)
{
	if (master->floor)
		mlx_destroy_image(master->mlx, master->floor);
	if (master->cave)
		mlx_destroy_image(master->mlx, master->cave);
	if (master->col.img)
		mlx_destroy_image(master->mlx, master->col.img);
	if (master->wallground)
		mlx_destroy_image(master->mlx, master->wallground);
	if (master->pla.img_left)
		mlx_destroy_image(master->mlx, master->pla.img_left);
	if (master->pla.img_right)
		mlx_destroy_image(master->mlx, master->pla.img_right);
	if (master->pla.img_up)
		mlx_destroy_image(master->mlx, master->pla.img_up);
	if (master->pla.img_down)
		mlx_destroy_image(master->mlx, master->pla.img_down);
	if (master->ground)
		mlx_destroy_image(master->mlx, master->ground);
	mlx_destroy_window(master->mlx, master->win);
	quit_program(master);
	return (1);
}

void	error_msg(char *str, void *master)
{
	ft_putstr_fd(str, 2);
	if (master)
		quit_program(master);
	exit(0);
}
