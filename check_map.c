/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 18:12:28 by svydrina          #+#    #+#             */
/*   Updated: 2023/11/06 18:42:35 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	check_ber(char *path)
{
	int	len;

	len = ft_strlen(path);
	return (len > 4 && path[len - 1] == 'r' && path[len - 2] == 'e'
		&& path[len - 3] == 'b' && path[len - 4] == '.');
}

int	check_rectangle(char **map)
{
	int	len;
	int	i;

	len = ft_strlen(map[0]);
	i = 1;
	while (map[i])
	{
		if (ft_strlen(map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

static int	right_symb(char c)
{
	return (c == '0' || c == '1' || c == 'E'
		|| c == 'P' || c == 'C');
}

int	check_symbols(char **map)
{
	int	y;
	int	x;

	y = 0;
	while (map[y])
	{
		x = 0;
		while (map[y][x])
		{
			if (!right_symb(map[y][x]))
				return (0);
			x++;
		}
		y++;
	}
	return (1);
}
