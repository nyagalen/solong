/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:40:21 by svydrina          #+#    #+#             */
/*   Updated: 2023/11/16 17:34:19 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	static t_game	game = {0};

	if (argc != 2)
		return (ft_printf("Error\nWrong number of arguments"), 1);
	if (!check_ber(argv[1]))
		return (ft_printf("Error\nWrong file name"), 1);
	init_map(&game, argv[1]);
	print_screen(&game);
	mlx_key_hook(game.win, &handle_input, &game);
	mlx_loop(game.mlx);
	return (0);
}
