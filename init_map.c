/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 17:09:52 by svydrina          #+#    #+#             */
/*   Updated: 2023/11/16 18:08:35 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	init_map(t_game *game, char *file)
{
	char	*line;
	int		fd;

	if (!check_ber(file))
		return (ft_printf("Error\nWrong file name"), exit(1));
	fd = open(file, O_RDONLY);
	if (fd < 0 || read(fd, &line, 0) < 0)
		return (ft_printf("Error\nInvalid file"), exit(1));
	set_size(game, fd);
	fd = open(file, O_RDONLY);
	fill_map(game, fd);
	close(fd);
	validate_map(game->map, game);
	flood_map(game, game->pl_x, game->pl_y);
	check_path(game);
	game_mlx(game);
	init_images(game);
}

void	game_mlx(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
	{
		free_map(game->map);
		ft_printf("Error\nMlx_init failed");
		mlx_destroy_display(game->mlx);
		exit(1);
	}
	game->win = mlx_new_window(game->mlx, game->width * 100,
			game->height * 100, "Welcome to so_long");
	if (!game->win)
	{
		free_map(game->map);
		ft_printf("Error\nFailed to create window");
		mlx_destroy_window(game->mlx, game->win);
		mlx_destroy_display(game->mlx);
		exit(1);
	}
}

void	validate_map(char **map, t_game *game)
{
	char	*error;

	error = NULL;
	if (!check_rectangle(map))
		error = ft_strdup("Error\nMap should be rectangular");
	else if (!check_walls(map))
		error = ft_strdup("Error\nMap should have proper walls");
	else if (!check_symbols(map))
		error = ft_strdup("Error\nWrong symbols in the map");
	else if (!all_there(map, game))
		error = ft_strdup("Error\nWrong nuber of objects");
	if (error != NULL)
	{
		ft_printf(error);
		free(error);
		free_map(map);
		exit(1);
	}
}

void	set_size(t_game *game, int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (game->height == 0 && !line)
			return (ft_printf("Error\nFile shouldn't be empty"),
				close(fd), exit(1));
		if (!line)
			break ;
		if (game->height == 0)
			game->width = ft_strlen(line);
		game->height++;
		free(line);
	}
	close(fd);
	if (game->height < 3 || game->height > 10
		|| game->width < 3 || game->width > 20)
		return (ft_printf("Error\nWrong map size"), exit(1));
}

void	fill_map(t_game *game, int fd)
{
	char	*line;
	int		i;

	i = 0;
	game->map = ft_calloc(sizeof(char *), game->height + 1);
	if (!game->map)
		return (ft_printf("Error\nMalloc error"), exit(1));
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		game->map[i] = ft_strdup(line);
		if (!game->map[i])
		{
			free(line);
			return (ft_printf("Error\nMalloc error"),
				free_map(game->map), exit(1));
		}
		free(line);
		i++;
	}
	game->map[i] = NULL;
}
