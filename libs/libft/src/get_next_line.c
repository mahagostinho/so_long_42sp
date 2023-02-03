/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/18 11:07:11 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/03 15:26:07 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/get_next_line.h" 

char	*get_next_line(int fd)
{
	static char	*save;
	char		*line;

	line = "";
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	save = ft_read_line(fd, save);
	if (!ft_strlen_gnl(save))
	{
		free(save);
		return (NULL);
	}
	else
	{
		line = ft_get_line(save);
		save = ft_update(save);
	}
	return (line);
}

char	*ft_read_line(int fd, char *save)
{
	char	*buffer;
	int		reader;

	buffer = malloc(BUFFER_SIZE + 1);
	if (!buffer)
		return (NULL);
	while (!ft_strchr_gnl(save, '\n'))
	{
		reader = read (fd, buffer, BUFFER_SIZE);
		if (reader <= 0)
		{
			free (buffer);
			return (save);
		}
		buffer[reader] = '\0';
		save = ft_strjoin_gnl(save, buffer);
		if (!save)
		{
			free (buffer);
			return (NULL);
		}		
	}
	free (buffer);
	return (save);
}

char	*ft_get_line(char *save)
{
	char	*line;
	int		i;

	i = 0;
	if (!save)
		return (NULL);
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	if (save[i] == '\n')
		i++;
	line = malloc(i + 1);
	if (!line)
		return (NULL);
	i = 0;
	while (save[i] != '\n' && save[i] != '\0')
	{
		line[i] = save[i];
		i++;
	}
	if (save[i] == '\n')
		line[i++] = '\n';
	line[i] = '\0';
	return (line);
}

char	*ft_update(char *save)
{
	char	*update_save;
	size_t	i;
	size_t	j;

	i = 0;
	if (!save)
		return (NULL);
	while (save[i] != '\n' && save[i] != '\0')
		i++;
	if (save[i] == '\n')
		i++;
	update_save = malloc(ft_strlen_gnl(save) - i + 1);
	if (!update_save)
		return (NULL);
	j = 0;
	while (save[i + j])
	{
		update_save[j] = save[i + j];
		j++;
	}			
	update_save[j] = '\0';
	free (save);
	return (update_save);
}
