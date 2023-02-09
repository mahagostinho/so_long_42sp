/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 00:37:38 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/09 01:53:52 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/path_validation.h"

char	**duplicate_map(t_game *game)
{
	char	**copy;
	int		i;

	copy = malloc((game->map.total_lines + 1) * sizeof(char *));
	i = 0;
	while (game->map.map_grid[i] != NULL)
	{
		copy[i] = ft_strdup(game->map.map_grid[i]);
		if (copy[i] == NULL)
		{
			free_ptr_ptr(copy);
			return (NULL);
		}
		copy[i][game->map.total_columns] = '\0';
		i++;
	}
	copy[i] = NULL;
	return (copy);
}

void	player_location(t_copy *copy)
{
	int	x;
	int	y;

	y = 0;
	while (copy->map[y] != NULL)
	{
		x = 0;
		while (copy->map[y][x] != '\0')
		{
			if (copy->map[y][x] == 'P')
			{
				copy->player.i = y;
				copy->player.j = x;
				return ;
			}
			x++;
		}
		y++;
	}
}

int	is_exit_reachable(int exit, int collec)
{
	if (exit != 0)
		ft_printf("Impossible to access exit\n");
	if (collec != 0)
		ft_printf("Impossible to access collectibles\n");
	if (exit != 0 || collec != 0)
		return (1);
	return (0);
}

void	free_copy(t_copy *copy)
{
	int	i;

	i = 0;
	if (copy->map)
	{
		while (copy->map[i])
		{
			free_ptr_ptr(&copy->map[i]);
			i++;
		}
		free(copy->map);
		copy->map = NULL;
	}
}
