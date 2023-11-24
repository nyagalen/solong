/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sl_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 23:22:52 by svydrina          #+#    #+#             */
/*   Updated: 2023/11/15 19:59:10 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_map(char **map)
{
	int	y;

	y = 0;
	while (map[y])
	{
		free(map[y]);
		y++;
	}
	free(map);
}

void	free_images(t_game *game)
{
	if (game->img.fond)
		mlx_destroy_image(game->mlx, game->img.fond);
	if (game->img.mur)
		mlx_destroy_image(game->mlx, game->img.mur);
	if (game->img.bouffe)
		mlx_destroy_image(game->mlx, game->img.bouffe);
	if (game->img.sortie)
		mlx_destroy_image(game->mlx, game->img.sortie);
	if (game->player.img)
		mlx_destroy_image(game->mlx, game->player.img);
}

static char	**copy_map(t_game *game)
{
	char	**new;
	int		y;

	new = ft_calloc((game->height + 1), sizeof(char *));
	y = 0;
	while (y < game->height)
	{
		new[y] = ft_strdup(game->map[y]);
		y++;
	}
	new[y] = NULL;
	return (new);
}

void	flood_map(t_game *game, int x, int y)
{
	if (game->flood == NULL)
		game->flood = copy_map(game);
	if (game->flood[y][x] == '1' || game->flood[y][x] == 'W')
		return ;
	game->flood[y][x] = 'W';
	flood_map(game, x - 1, y);
	flood_map(game, x + 1, y);
	flood_map(game, x, y - 1);
	flood_map(game, x, y + 1);
}

void	check_path(t_game *game)
{
	int	y;
	int	x;

	y = 0;
	while (y < game->height)
	{
		x = 0;
		while (game->flood[y][x])
		{
			if (game->flood[y][x] == 'C' || game->flood[y][x] == 'E')
				return (ft_printf("Error\nPlayer's path incorrect"),
					free_map(game->map),
					free_map(game->flood), exit(1));
			x++;
		}
		y++;
	}
	free_map(game->flood);
}
