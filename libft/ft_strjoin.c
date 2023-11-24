/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: svydrina <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 19:20:54 by svydrina          #+#    #+#             */
/*   Updated: 2023/11/11 00:44:03 by svydrina         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	size_t	i;
	char	*new;

	len = (size_t)ft_strlen(s1) + (size_t)ft_strlen(s2);
	i = 0;
	new = malloc(len + 1);
	if (!new)
		return (NULL);
	while ((int)i < ft_strlen(s1))
	{
		new[i] = s1[i];
		i++;
	}
	while (i < len)
	{
		new[i] = s2[(int)i - ft_strlen(s1)];
		i++;
	}
	new[i] = '\0';
	return (new);
}
