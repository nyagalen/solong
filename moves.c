/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/16 18:12:48 by svydrina          #+#    #+#             */
/*   Updated: 2023/11/20 16:04:50 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	print_moves(t_game *game)
{
	char	*moves;

	moves = ft_itoa(game->moves);
	if (!moves)
		return (ft_printf("Error\nMemory allocation failed"),
			free_game(game));
	mlx_string_put(game->mlx, game->win, 60, 25, 0x0000FE, moves);
	free(moves);
	game->moves++;
	moves = ft_itoa(game->moves);
	mlx_string_put(game->mlx, game->win, 60, 25, 0xFFFFFF, moves);
	free(moves);
	ft_printf("moves : %d\n", game->moves);
}

void	move_up(t_game *game)
{
	if (game->map[game->pl_y - 1][game->pl_x] == '1')
		return ;
	if (game->map[game->pl_y - 1][game->pl_x] == 'E' &&
			game->score == game->coins)
		free_game(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.fond,
		game->pl_x * 100, game->pl_y * 100);
	mlx_destroy_image(game->mlx, game->player.img);
	game->player.img = mlx_xpm_file_to_image(game->mlx,
			"./assets/Pac_Haut.xpm",
			&game->img.width, &game->img.height);
	if (!game->player.img)
		return (ft_printf("Error\nFailed to load image"), free_game(game));
	game->pl_y--;
	mlx_put_image_to_window(game->mlx, game->win, game->player.img,
		game->pl_x * 100, game->pl_y * 100);
	if (game->map[game->pl_y][game->pl_x] == 'C')
	{
		game->map[game->pl_y][game->pl_x] = '0';
		handle_coins(game);
	}
	print_moves(game);
}

void	move_down(t_game *game)
{
	if (game->map[game->pl_y + 1][game->pl_x] == '1')
		return ;
	if (game->map[game->pl_y + 1][game->pl_x] == 'E' &&
			game->score == game->coins)
		free_game(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.fond,
		game->pl_x * 100, game->pl_y * 100);
	mlx_destroy_image(game->mlx, game->player.img);
	game->player.img = mlx_xpm_file_to_image(game->mlx, "./assets/Pac_bas.xpm",
			&game->img.width, &game->img.height);
	if (!game->player.img)
		return (ft_printf("Error\nFailed to load image"), free_game(game));
	game->pl_y++;
	mlx_put_image_to_window(game->mlx, game->win, game->player.img,
		game->pl_x * 100, game->pl_y * 100);
	if (game->map[game->pl_y][game->pl_x] == 'C')
	{
		game->map[game->pl_y][game->pl_x] = '0';
		handle_coins(game);
	}
	print_moves(game);
}

void	move_left(t_game *game)
{
	if (game->map[game->pl_y][game->pl_x - 1] == '1')
		return ;
	if (game->map[game->pl_y][game->pl_x - 1] == 'E' &&
			game->score == game->coins)
		free_game(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.fond,
		game->pl_x * 100, game->pl_y * 100);
	mlx_destroy_image(game->mlx, game->player.img);
	game->player.img = mlx_xpm_file_to_image(game->mlx,
			"./assets/Pac_Gauche.xpm",
			&game->img.width, &game->img.height);
	if (!game->player.img)
		return (ft_printf("Error\nFailed to load image"), free_game(game));
	game->pl_x--;
	mlx_put_image_to_window(game->mlx, game->win, game->player.img,
		game->pl_x * 100, game->pl_y * 100);
	if (game->map[game->pl_y][game->pl_x] == 'C')
	{
		game->map[game->pl_y][game->pl_x] = '0';
		handle_coins(game);
	}
	print_moves(game);
}

void	move_right(t_game *game)
{
	if (game->map[game->pl_y][game->pl_x + 1] == '1')
		return ;
	if (game->map[game->pl_y][game->pl_x + 1] == 'E' &&
			game->coins == game->score)
		free_game(game);
	mlx_put_image_to_window(game->mlx, game->win, game->img.fond,
		game->pl_x * 100, game->pl_y * 100);
	mlx_destroy_image(game->mlx, game->player.img);
	game->player.img = mlx_xpm_file_to_image(game->mlx,
			"./assets/Pac_Droite.xpm",
			&game->img.width, &game->img.height);
	if (!game->player.img)
		return (ft_printf("Error\nFailed to load image"), free_game(game));
	game->pl_x++;
	mlx_put_image_to_window(game->mlx, game->win, game->player.img,
		game->pl_x * 100, game->pl_y * 100);
	if (game->map[game->pl_y][game->pl_x] == 'C')
	{
		game->map[game->pl_y][game->pl_x] = '0';
		handle_coins(game);
	}
	print_moves(game);
}
