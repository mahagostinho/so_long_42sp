/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_moves.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/07 14:48:55 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/08 12:54:45 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	move_player(t_game *game, int new_i, int new_j)
{
	int	i;
	int	j;

	i = game->player.i;
	j = game->player.j;
	if (game->map.map_grid[new_i][new_j] == EXIT &&
		game->map.total_collectible == 0)
	{
		game->map.map_grid[new_i][new_j] = PLAYER;
		player_wins(game);
	}
	else if (game->map.map_grid[new_i][new_j] == SPACE ||
		game->map.map_grid[new_i][new_j] == COLLECTIBLE)
	{
		game->map.map_grid[i][j] = SPACE;
		if (game->map.map_grid[new_i][new_j] == COLLECTIBLE)
			game->map.total_collectible--;
		game->map.map_grid[new_i][new_j] = PLAYER;
		game->player.i = new_i;
		game->player.j = new_j;
		game->moves++;
		ft_printf("Movements: %d\n", game->moves);
		render_game(game);
	}
}
