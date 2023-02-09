/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 21:22:33 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/09 02:24:54 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/path_validation.h"

int	check_valid_path(t_game *game)
{
	int		has_error;
	t_copy	copy;

	has_error = 0;
	copy.map = duplicate_map(game);
	if (copy.map == NULL)
		return (1);
	player_location(&copy);
	rewrite_path(&copy, copy.player.i, copy.player.j);
	has_error += check_path(&copy, game);
	free_copy(&copy);
	if (has_error != 0)
		return (1);
	return (0);
}

int	check_path(t_copy *copy, t_game *game)
{
	int	line;
	int	col;
	int	exit;
	int	collec;

	line = 0;
	exit = 0;
	collec = 0;
	col = 0;
	while (copy->map[line] != NULL)
	{
		col = 0;
		while (col < (int)game->map.total_columns)
		{
			if (copy->map[line][col] == 'E' && exit == 0)
				exit = 1;
			if (copy->map[line][col] == 'C' && collec == 0)
				collec = 1;
			col++;
		}
		line++;
	}
	return (is_exit_reachable(exit, collec));
}

void	rewrite_path(t_copy *copy, int line, int col)
{
	if (copy->map[line][col] == 'X' || copy->map[line][col] == '1' || \
	copy->map[line][col] == 'S')
		return ;
	if (copy->map[line][col] == 'E')
	{
		copy->map[line][col] = 'S';
		return ;
	}
	else
		copy->map[line][col] = 'X';
	rewrite_path(copy, line - 1, col);
	rewrite_path(copy, line + 1, col);
	rewrite_path(copy, line, col - 1);
	rewrite_path(copy, line, col + 1);
}
