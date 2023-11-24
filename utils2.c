/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/15 19:38:27 by svydrina          #+#    #+#             */
/*   Updated: 2023/11/17 15:56:34 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_game(t_game *game)
{
	free_map(game->map);
	free_images(game);
	mlx_clear_window(game->mlx, game->win);
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	exit(0);
}

void	init_images(t_game *game)
{
	game->img.fond = mlx_xpm_file_to_image(game->mlx, "./assets/Fond.xpm",
			&(game->img.width), &(game->img.height));
	game->img.mur = mlx_xpm_file_to_image(game->mlx, "./assets/blue_sq.xpm",
			&(game->img.width), &(game->img.height));
	game->img.bouffe = mlx_xpm_file_to_image(game->mlx, "./assets/Bouffe.xpm",
			&(game->img.width), &(game->img.height));
	game->img.sortie = mlx_xpm_file_to_image(game->mlx, "./assets/bang.xpm",
			&(game->img.width), &(game->img.height));
	game->player.img = mlx_xpm_file_to_image(game->mlx,
			"./assets/Pac_Droite.xpm",
			&(game->img.width), &(game->img.height));
	if (!game->player.img || !game->img.fond || !game->img.mur
		|| !game->img.bouffe || !game->img.sortie)
		return (ft_printf("Error\nFailed to load images"), free_game(game),
			exit(1));
}	
