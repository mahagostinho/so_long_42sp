/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:07:33 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/03 15:25:21 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h"

size_t	ft_strlen_gnl(char *s)
{
	size_t	i;

	i = 0;
	if (s)
	{
		while (s[i])
			i++;
		return (i);
	}
	return (0);
}

char	*ft_strchr_gnl(char *s, int c)
{
	char	*find;
	int		i;

	i = 0;
	find = 0;
	if (s)
	{
		while (s[i])
		{
			if (s[i] == (char) c)
			{
				find = (s + i);
				return ((char *) s + i);
			}
			i++;
		}
		if (c == 0)
			find = (s + ft_strlen_gnl(s));
		return ((char *) find);
	}	
	return (NULL);
}

char	*ft_strjoin_gnl(char *s1, char *s2)
{
	char	*new;
	size_t	len_s1;
	size_t	len_s2;

	len_s1 = 0;
	len_s2 = 0;
	new = (char *) malloc((ft_strlen_gnl(s1) + ft_strlen_gnl(s2) + 1));
	if (!new)
		return (NULL);
	if (s1)
	{
		while (s1[len_s1])
		{
			new[len_s1] = s1[len_s1];
			len_s1++;
		}
	}
	while (s2[len_s2])
	{
		new[len_s1 + len_s2] = s2[len_s2];
		len_s2++;
	}	
	new[len_s1 + len_s2] = '\0';
	free (s1);
	return (new);
}
