/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   affichage.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 14:58:08 by svydrina          #+#    #+#             */
/*   Updated: 2023/11/21 15:46:18 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_screen(t_game *game)
{
	int		y;
	int		x;
	char	*counter;

	y = 0;
	counter = "Moves : ";
	while (y < game->height)
	{
		x = 0;
		while (game->map[y][x])
		{
			print_img(game, y, x, game->map[y][x]);
			x++;
		}
		y++;
	}
	mlx_string_put(game->mlx, game->win, 10, 25, 0xFFFFFF, counter);
	mlx_hook(game->win, 17, 0, close_window, game);
}

void	print_img(t_game *game, int y, int x, char c)
{
	if (c == 'P')
	{
		game->player.x = x * 100;
		game->player.y = y * 100;
		mlx_put_image_to_window(game->mlx, game->win, game->player.img,
			game->player.x, game->player.y);
	}
	if (c == '1')
		mlx_put_image_to_window(game->mlx, game->win, game->img.mur,
			x * 100, y * 100);
	if (c == '0' || c == 'E')
		mlx_put_image_to_window(game->mlx, game->win, game->img.fond,
			x * 100, y * 100);
	if (c == 'C')
		mlx_put_image_to_window(game->mlx, game->win, game->img.bouffe,
			x * 100, y * 100);
}
