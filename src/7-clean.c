/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clean.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 15:30:25 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/06 18:37:39 by marcarva         ###   ########.fr       */
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

void clean_mlx(t_game *game)
{
	if (game->img.img_ptr != NULL)
	{
		mlx_destroy_image(game->mlx.mlx_ptr, game->img.img_ptr);
		game->img.img_ptr = NULL;
	}
	if (game->mlx.win_ptr != NULL)
	{
		mlx_destroy_window(game->mlx.mlx_ptr, game->mlx.win_ptr);
		game->mlx.win_ptr = NULL;
	}
	if (game->mlx.mlx_ptr != NULL)
	{
		mlx_destroy_display(game->mlx.mlx_ptr);
		free(game->mlx.mlx_ptr);
		game->mlx.mlx_ptr = NULL;
	}
}

void	clean_img(t_game *game)
{
	if (game->sprites.collectible.img_ptr != NULL)
		mlx_destroy_image(game->mlx.mlx_ptr, game->sprites.collectible.img_ptr);
	if (game->sprites.exit.img_ptr != NULL)
		mlx_destroy_image(game->mlx.mlx_ptr, game->sprites.exit.img_ptr);
	if (game->sprites.floor.img_ptr != NULL)
		mlx_destroy_image(game->mlx.mlx_ptr, game->sprites.floor.img_ptr);
	if (game->sprites.wall.img_ptr != NULL)
		mlx_destroy_image(game->mlx.mlx_ptr, game->sprites.wall.img_ptr);
	if (game->sprites.player.img_ptr != NULL)
		mlx_destroy_image(game->mlx.mlx_ptr, game->sprites.player.img_ptr);
}

void	free_game(t_game *game)
{
	free_map(game);
	clean_img(game);
	clean_mlx(game);
}
