/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5-sprites.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:49:09 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/07 14:21:13 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	convert_sprite_to_img(t_game *game, t_img *sprite, char *path)
{
	sprite->width = TILE_SIZE;
	sprite->height = TILE_SIZE;
	sprite->img_ptr = mlx_xpm_file_to_image(game->mlx.mlx_ptr, path,
			&sprite->width, &sprite->height);
	if (sprite->img_ptr == NULL)
		game_error(ft_strjoin("Error to load sprite: ", path), game);
	sprite->addr = mlx_get_data_addr(sprite->img_ptr, &sprite->bpp,
			&sprite->line_len, &sprite->endian);
}

void	put_sprite(t_game *game, int i, int j)
{
	char	character;

	character = game->map.map_grid[i][j];
	if (character == WALL)
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
			game->sprites.wall.img_ptr, j * TILE_SIZE, i * TILE_SIZE);
	if (character == SPACE)
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
			game->sprites.floor.img_ptr, j * TILE_SIZE, i * TILE_SIZE);
	if (character == PLAYER)
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
			game->sprites.player.img_ptr, j * TILE_SIZE, i * TILE_SIZE);
	if (character == COLLECTIBLE)
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
			game->sprites.collectible.img_ptr, j * TILE_SIZE, i * TILE_SIZE);
	if (character == EXIT)
		mlx_put_image_to_window(game->mlx.mlx_ptr, game->mlx.win_ptr,
			game->sprites.exit.img_ptr, j * TILE_SIZE, i * TILE_SIZE);
}
