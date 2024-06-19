/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaypara <mbaypara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:52:57 by mbaypara          #+#    #+#             */
/*   Updated: 2024/05/22 11:52:59 by mbaypara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	is_valid(t_master *master, char *array)
{
	if (array[0] == '\n' && array[1] == '\n')
		error_msg("Invalid map, dont use empty line\n", master);
	else if (*array == '1' || *array == '0' || *array == 'C' || *array == 'E'
		|| *array == 'P' || (*array == '\n' && array[1] != '\0'))
		return (1);
	return (0);
}

int	check_file(char *file, char *ext)
{
	while (*file != '\0')
	{
		if (*file == '.')
		{
			while (*file == *ext && (*file != '\0' || *ext != '\0'))
			{
				file++;
				ext++;
			}
			if (*file == '\0' && *ext == '\0')
				return (1);
		}
		file++;
	}
	return (0);
}

void	parse_width_height(t_master *master)
{
	if (master->map->h < 3)
		error_msg("Invalid map height\n", master);
	if (master->map->w < 3)
		error_msg("Invalid map width\n", master);
	master->width = master->map->w;
	master->height = master->map->h;
	if (master->map->w > MAX_MAP || master->map->h > MAX_MAP)
		error_msg("Map too big for mlx\n", master);
}
