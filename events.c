/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 16:46:22 by svydrina          #+#    #+#             */
/*   Updated: 2023/11/16 19:07:58 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_input(int keycode, t_game *game)
{
	
	if (keycode == XK_Escape)
		free_game(game);
	if (keycode == XK_Up || keycode == XK_w)
		move_up(game);
	if (keycode == XK_Down || keycode == XK_s)
		move_down(game);
	if (keycode == XK_Left || keycode == XK_a)
		move_left(game);
	if (keycode == XK_Right || keycode == XK_d)
		move_right(game);
	return (0);
}

int	close_window(t_game *game)
{
	free_game(game);
	return (0);
}

void	handle_coins(t_game *game)
{
	game->score++;
	if (game->coins == game->score)
		mlx_put_image_to_window(game->mlx, game->win, game->img.sortie,
			game->ex_x * 100, game->ex_y * 100);
}
