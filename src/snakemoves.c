/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaypara <mbaypara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:52:44 by mbaypara          #+#    #+#             */
/*   Updated: 2024/05/22 11:52:45 by mbaypara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	put_img(t_master *master, void *img, t_map *map)
{
	mlx_put_image_to_window(master->mlx, master->win, img, \
		map->pos_x_y.x, map->pos_x_y.y);
}

void	get_map_cordinates(t_map *map, int x, int y)
{
	map->pos_x_y.x = IMG_W * x;
	map->pos_x_y.y = IMG_H * y;
}

void	add_position(t_player *player, int x, int y)
{
	player->pos.x = x;
	player->pos.y = y;
}

void	update_positions(t_master *m, int key)
{
	if (key == MV_U)
	{
		add_position(&m->pla, m->pla.last.x, m->pla.last.y - 1);
		m->pla.img = m->pla.img_up;
	}
	else if (key == MV_D)
	{
		add_position(&m->pla, m->pla.last.x, m->pla.last.y + 1);
		m->pla.img = m->pla.img_down;
	}
	else if (key == MV_L)
	{
		add_position(&m->pla, m->pla.last.x - 1, m->pla.last.y);
		m->pla.img = m->pla.img_left;
	}
	else if (key == MV_R)
	{
		add_position(&m->pla, m->pla.last.x + 1, m->pla.last.y);
		m->pla.img = m->pla.img_right;
	}
}
