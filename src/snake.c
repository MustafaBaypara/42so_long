/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   snake.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaypara <mbaypara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:52:30 by mbaypara          #+#    #+#             */
/*   Updated: 2024/06/19 18:24:12 by mbaypara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	update_pos(t_master *master)
{
	master->pla.last.x = master->pla.pos.x;
	master->pla.last.y = master->pla.pos.y;
}

int	game_eng(int key, t_master *m)
{
	else if (key == MV_U || key == MV_D || key == MV_L || key == MV_R)
	{
		update_positions(m, key);
		if (not_wall(m, m->pla.pos.x, m->pla.pos.y))
		{
			update_coll(m, m->pla.pos.x, m->pla.pos.y);
			refresh_map(m, m->pla.pos.x, m->pla.pos.y);
			ft_putnbr_fd(m->player_moves, 1);
			ft_putchar_fd('\n', 1);
			if (game_finished(m, m->pla.pos.x, m->pla.pos.y))
				exit_hook(m);
			update_pos(m);
		}
	}
	return (0);
}

void	start_game(t_master *m)
{
	int	width;
	int	heigth;

	width = m->map->w * IMG_W;
	heigth = m->map->h * IMG_H;
	m->mlx = mlx_init();
	m->win = mlx_new_window(m->mlx, width, heigth, "mbaypara");
	images_init(m);
	draw(m);
	mlx_hook(m->win, 17, 0, exit_hook, m);
	mlx_key_hook(m->win, game_eng, m);
	if (m->map->collect != m->col.number_of_c)
		error_msg("Error\nPath to collectables not found\n", m);
	mlx_loop(m->mlx);
}
