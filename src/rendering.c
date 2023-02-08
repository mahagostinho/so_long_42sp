/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 12:22:25 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/08 12:49:46 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	render_game(t_game *game)
{
	int	i;
	int	j;

	i = 0;
	while (i < game->map.total_lines)
	{
		j = 0;
		while (j < (int)game->map.total_columns)
		{
			put_sprite(game, i, j);
			j++;
			if (game->map.map_grid[i][j] == PLAYER)
			{
				game->player.i = i;
				game->player.j = j;
			}
		}
		i++;
	}
	return (0);
}
