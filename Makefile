# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: svydrina <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/11/10 16:59:43 by svydrina          #+#    #+#              #
#    Updated: 2023/11/16 18:47:32 by svydrina         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

SRCS = so_long.c check_map.c check_map2.c check_map3.c init_map.c sl_utils.c \
       utils2.c affichage.c events.c moves.c

OBJS = $(SRCS:.c=.o)

CC = cc -g -Wall -Werror -Wextra

INCLUDES = -I. -I/usr/include -Imlx -Ilibft

LDFLAGS = -lft -Llibft

LIBFT = libft/libft.a

MLX = mlx/libmlx_Linux.a

MLX_FLAGS = -Lmlx -lmlx -L/usr/lib/X11 -lXext -lX11

all: $(NAME)

$(NAME): $(OBJS) $(MLX) $(LIBFT)
	$(CC) -o $(NAME) $(OBJS) $(MLX_FLAGS) $(LIBFT)

$(MLX):
	make -C mlx

$(LIBFT):
	make -C libft

%.o: %.c so_long.h
	$(CC) -o $@ -c $< $(INCLUDES)

clean:
	rm -f $(OBJS)
	make -C mlx clean
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C mlx clean
	make -C libft clean

re: fclean all
	

.PHONY: all clean fclean re
