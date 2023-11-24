/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map3.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/06 19:01:48 by svydrina          #+#    #+#             */
/*   Updated: 2023/11/06 19:19:01 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	how_many(char **map, char c, t_game *game)
{
	int	y;
	int	x;
	int	obj;

	y = 1;
	obj = 0;
	while (map[y])
	{
		x = 1;
		while (map[y][x])
		{
			if (map[y][x] == c)
			{
				obj++;
				assign_game(game, c, x, y);
			}
			x++;
		}
		y++;
	}
	return (obj);
}

int	all_there(char **map, t_game *game)
{
	int	exit;
	int	item;
	int	player;

	exit = how_many(map, 'E', game);
	item = how_many(map, 'C', game);
	player = how_many(map, 'P', game);
	return (exit == 1 && item > 0 && player == 1);
}

void	assign_game(t_game *game, char c, int x, int y)
{
	if (c == 'P')
	{
		game->pl_x = x;
		game->pl_y = y;
	}
	else if (c == 'E')
	{
		game->ex_x = x;
		game->ex_y = y;
	}
	else if (c == 'C')
		game->coins++;
}
