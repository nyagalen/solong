/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:42:55 by svydrina          #+#    #+#             */
/*   Updated: 2023/11/06 18:57:37 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	one_all_through(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	one_start_end(char *line)
{
	int	len;

	len = ft_strlen(line);
	return (line[0] == '1' && line[len - 1] == '1');
}

static int	map_size(char **map)
{
	int	y;

	y = 0;
	while (map[y])
		y++;
	return (y);
}

int	check_walls(char **map)
{
	int	y;
	int	size;

	size = map_size(map);
	if (size < 3)
		return (0);
	if (!one_all_through(map[0]) || !one_all_through(map[size - 1]))
		return (0);
	y = 1;
	while (y < size - 1)
	{
		if (!one_start_end(map[y]))
			return (0);
		y++;
	}
	return (1);
}
