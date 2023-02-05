/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:33:53 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/04 22:24:28 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	free_ptr_ptr(char **ptr)
{
	if (ptr == NULL && !(*ptr))
		return ;
	if (*ptr)
		free(*ptr);
	*ptr = NULL;
}

void	free_map(t_game *game)
{
	int	i;

	i = 0;
	if (game->map.map_vector)
		free_ptr_ptr(&game->map.map_vector);
	if (game->map.map_grid)
	{
		while (game->map.map_grid[i])
		{
			free_ptr_ptr(&game->map.map_grid[i]);
			i++;
		}
		free(game->map.map_grid);
		game->map.map_grid = NULL;
	}
}

/*
void clean_malloc(void **ptr)
{
	int i;

	i = 0;
	if (ptr == NULL && !(*ptr))
		return;
	else
	{
		while (ptr[i])
		{
			free(ptr[i]);
			ptr[i] = NULL;
			i++;
		}
		free(ptr);
		ptr = NULL;
	}
}


void clean_mlx(t_game *sl)
{
	if (sl->mlx.win != NULL)
		mlx_destroy_window(sl->mlx.mlx, sl->mlx.win);
	sl->mlx.win = NULL;
	if (sl->mlx.mlx != NULL)
		mlx_destroy_display(sl->mlx.mlx);
	free(sl->mlx.mlx);
	sl->mlx.mlx = NULL;
}
*/
void clean_game(t_game *game)
{
	free_map(game);
	/*
	if (game->items != NULL)
		clean_malloc((void **)game->items);
	if (game->mlx.mlx != NULL)
	{
		clean_imgs(game);
		clean_mlx(game);
	}
	*/
}
