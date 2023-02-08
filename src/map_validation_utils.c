/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation_utils.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 18:21:19 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/08 12:48:43 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	check_map_characters(t_game *game)
{
	if (game->map.total_player != 1)
		map_error("The map must contain one starting position!", game);
	if (game->map.total_exit != 1)
		map_error("The map must contain one exit!", game);
	if (game->map.total_collectible == 0)
		map_error("The map must have at least one collectible!", game);
}

void	check_map_line(char *map_line, t_game *game, int i)
{
	int	j;

	j = 0;
	if (ft_strlen(map_line) != game->map.total_columns)
		map_error("The map must be rectangular!", game);
	while (map_line[j])
	{
		if (i == 0 || i == game->map.total_lines - 1)
			is_wall(map_line[j], game);
		else if (j == 0 || j == (int)game->map.total_columns - 1)
			is_wall(map_line[j], game);
		else
			is_character(map_line[j], game);
		j++;
	}
}

void	is_wall(char component, t_game *game)
{
	if (component != WALL)
		map_error("The map must be surrounded by walls!", game);
}

void	is_character(char component, t_game *game)
{
	if (component == COLLECTIBLE)
		game->map.total_collectible++;
	else if (component == PLAYER)
		game->map.total_player++;
	else if (component == EXIT)
		game->map.total_exit++;
	else if (component != WALL && component != SPACE)
		map_error("Invalid character!", game);
}
