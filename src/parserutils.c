/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mbaypara <mbaypara@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/22 11:52:48 by mbaypara          #+#    #+#             */
/*   Updated: 2024/05/22 11:52:50 by mbaypara         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	open_file(int *fd, char *fname, int opt, t_master *master)
{
	if (opt == 0)
		*fd = open(fname, O_RDONLY);
	if (*fd < 3)
		error_msg("Error reading file\n", master);
}

void	width_map(t_master *m, char *buffer, int *counter, int *index)
{
	int	i;
	int	j;

	i = *index;
	while (buffer[i] != '\n')
	{
		m->map->w++;
		i++;
	}
	*counter = 1;
	*index = i;
	i = *index;
	i++;
	while (buffer[i] != 0 && buffer[i] != '\n')
	{
		j = 0;
		while (buffer[i + j] != '\n' && buffer[i + j] != 0)
			j++;
		if (j != m->map->w)
			error_msg("Invalid map length\n", m);
		if (buffer[i + j] == 0)
			break ;
		i += j + 1;
	}
}

int	check_elem(char c, t_parse_info *info, t_master *master)
{
	if (c == '1')
		return (1);
	else if (c == '0')
		return (0);
	else if (c == 'P')
	{
		info->p_exists++;
		return (2);
	}
	else if (c == 'C')
	{
		info->c_exists++;
		return (3);
	}
	else if (c == 'E')
	{
		info->e_exists++;
		return (4);
	}
	error_msg("Invalid char at map\n", master);
	return (-1);
}

int	**alloc_map(int size, int size2)
{
	int	i;
	int	**map2d;

	map2d = (int **)malloc(sizeof(int *) * size);
	if (!map2d)
		return (0);
	i = -1;
	while (++i < size)
	{
		map2d[i] = malloc(sizeof(int) * size2);
		if (!map2d[i])
			return (0);
	}
	return (map2d);
}
