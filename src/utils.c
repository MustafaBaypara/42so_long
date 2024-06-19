/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaypara <mbaypara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:52:25 by mbaypara          #+#    #+#             */
/*   Updated: 2024/05/22 11:52:27 by mbaypara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	not_wall(t_master *master, int x, int y)
{
	return (x < master->width && y < master->height \
		&& master->map->map2d[y][x] != WALL && (master->map->map2d[y][x] != E \
			|| master->col.number_of_c <= 0));
}

void	update_coll(t_master *master, int x, int y)
{
	if (master->map->map2d[y][x] == C && master->col.number_of_c != 0)
	{
		master->col.number_of_c--;
		master->map->map2d[y][x] = 0;
	}
	master->player_moves++;
}

void	refresh_map(t_master *master, int newx, int newy)
{
	void	*img;

	img = master->floor;
	get_map_cordinates(master->map, master->pla.last.x, master->pla.last.y);
	put_img(master, img, master->map);
	img = master->floor;
	get_map_cordinates(master->map, newx, newy);
	put_img(master, img, master->map);
	img = master->pla.img;
	get_map_cordinates(master->map, newx, newy);
	put_img(master, img, master->map);
}
