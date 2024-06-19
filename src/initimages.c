/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initimages.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaypara <mbaypara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:52:34 by mbaypara          #+#    #+#             */
/*   Updated: 2024/06/19 18:24:34 by mbaypara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

static void	xmp_to_image(t_master *master, void **image, char *xpm_path)
{
	int	width;
	int	height;

	*image = mlx_xpm_file_to_image(master->mlx, xpm_path, \
		&width, &height);
	if (!*image)
	{
		ft_putstr_fd("Error\nImage not found\n", 2);
	}
}

void	images_init(t_master *master)
{
	xmp_to_image(master, &(master->pla.img_up), "pictures/SnakeUp.XPM");
	xmp_to_image(master, &(master->pla.img_down), "pictures/SnakeDown.XPM");
	xmp_to_image(master, &(master->pla.img_left), "pictures/SnakeLeft.XPM");
	xmp_to_image(master, &(master->pla.img_right), "pictures/SnakeRight.XPM");
	xmp_to_image(master, &(master->wallground), "pictures/SnakeWall.XPM");
	xmp_to_image(master, &(master->ground), "pictures/SnakeGround.XPM");
	master->pla.img = master->pla.img_down;
}
