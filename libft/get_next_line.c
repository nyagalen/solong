/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 21:01:31 by svydrina          #+#    #+#             */
/*   Updated: 2023/11/11 00:25:27 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*before_n(char *str)
{
	int		i;
	int		new_i;
	char	*new;

	i = 0;
	new_i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	new = malloc(i + 1);
	if (!new)
		return (NULL);
	while (new_i < i)
	{
		new[new_i] = str[new_i];
		new_i++;
	}
	new[new_i] = '\0';
	return (new);
}

static char	*after_n(char *str)
{
	int		i;
	char	*new;
	int		a;

	i = 0;
	if (!str)
		return (NULL);
	while (str[i] && str[i] != '\n')
		i++;
	if (str[i] == '\0' || ft_strlen_gnl(str) == i + 1)
	{
		free(str);
		return (NULL);
	}
	i += (str[i] == '\n');
	new = malloc(ft_strlen_gnl(str) - i + 1);
	if (!new)
		return (NULL);
	a = 0;
	while (str[i])
		new[a++] = str[i++];
	new[a] = '\0';
	free(str);
	return (new);
}

char	*get_next_line(int fd)
{
	int			num_bytes;
	char		*buff;
	static char	*rest;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	num_bytes = 1;
	buff = malloc(BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	while (!(ft_strchr_gnl(rest, '\n')) && num_bytes != 0)
	{
		num_bytes = read(fd, buff, BUFFER_SIZE);
		if (num_bytes == -1 || (!rest && num_bytes == 0))
		{
			free(buff);
			return (NULL);
		}
		buff[num_bytes] = '\0';
		rest = ft_strjoin_gnl(rest, buff);
	}
	free(buff);
	buff = before_n(rest);
	rest = after_n(rest);
	return (buff);
}
