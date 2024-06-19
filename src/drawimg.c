/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawimg.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaypara <mbaypara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:52:11 by mbaypara          #+#    #+#             */
/*   Updated: 2024/05/22 12:04:15 by mbaypara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	add_last_position(t_player *player, int x, int y)
{
	player->last.x = x;
	player->last.y = y;
}

static void	*gg_norm3(t_master *m, t_vector vec, void *my_img, int option)
{
	void	*img;

	put_img(m, m->ground, m->map);
	img = my_img;
	if (option == P)
		add_last_position(&m->pla, vec.x, vec.y);
	return (img);
}

void	draw(t_master *m)
{
	t_vector	vec;
	void		*img;

	vec.y = -1;
	while (++vec.y < m->map->h)
	{
		vec.x = -1;
		while (++vec.x < m->map->w)
		{
			get_map_cordinates(m->map, vec.x, vec.y);
			if (m->map->map2d[vec.y][vec.x] == WALL)
				img = m->wallground;
			else if (m->map->map2d[vec.y][vec.x] == FLOOR)
				img = m->ground;
			else if (m->map->map2d[vec.y][vec.x] == C)
				img = gg_norm3(m, vec, m->col.img, C);
			if (m->map->map2d[vec.y][vec.x] == P)
				img = gg_norm3(m, vec, m->pla.img, P);
			else if (m->map->map2d[vec.y][vec.x] == E)
				img = gg_norm3(m, vec, m->cave, E);
			put_img(m, img, m->map);
		}
	}
}
