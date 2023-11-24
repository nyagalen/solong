/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 21:19:52 by svydrina          #+#    #+#             */
/*   Updated: 2023/11/20 15:52:05 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "mlx/mlx.h"
# include "libft/libft.h"
# include <stdlib.h>
# include <unistd.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <X11/X.h>

typedef struct s_img
{
	void	*fond;
	void	*mur;
	void	*bouffe;
	void	*sortie;
	int		width;
	int		height;
}	t_img;

typedef struct s_player
{
	void	*img;
	int		x;
	int		y;
}	t_player;

typedef struct s_game
{
	void		*mlx;
	void		*win;
	int			width;
	int			height;
	char		**map;
	char		**flood;
	int			pl_x;
	int			pl_y;
	int			ex_x;
	int			ex_y;
	int			coins;
	int			score;
	int			moves;
	t_img		img;
	t_player	player;
}	t_game;

int		check_walls(char **map);
int		all_there(char **map, t_game *game);
int		check_ber(char *path);
int		check_rectangle(char **map);
int		check_symbols(char **map);
void	init_map(t_game *game, char *file);
void	game_mlx(t_game *game);
void	validate_map(char **map, t_game *game);
void	set_size(t_game *game, int fd);
void	fill_map(t_game *game, int fd);
void	free_map(char **map);
void	assign_game(t_game *game, char c, int x, int y);
void	flood_map(t_game *game, int x, int y);
void	check_path(t_game *game);
void	free_images(t_game *game);
void	free_game(t_game *game);
void	init_images(t_game *game);
void	print_screen(t_game *game);
void	print_img(t_game *game, int y, int x, char c);
int		handle_input(int keycode, t_game *game);
int		close_window(t_game *game);
void	handle_coins(t_game *game);
void	move_up(t_game *game);
void	move_down(t_game *game);
void	move_left(t_game *game);
void	move_right(t_game *game);
void	print_moves(t_game *game);

#endif
