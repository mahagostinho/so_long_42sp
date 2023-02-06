/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4-game_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/05 19:58:33 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/06 15:32:04 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	game_init(t_game *game)
{
	create_window(game);
	game->img.img_ptr = mlx_new_image(game->mlx.mlx_ptr,
			game->mlx.window_width, game->mlx.window_height);
	if (game->img.img_ptr == NULL)
		game_error("Error to create image pointer", game);
	game->img.addr = mlx_get_data_addr(game->img.img_ptr, &game->img.bpp,
			&game->img.line_len, &game->img.endian);
	load_sprites(game);
	render_game(game);
}

void	create_window(t_game *game)
{
	game->mlx.mlx_ptr = mlx_init();
	if (game->mlx.mlx_ptr == NULL)
		game_error("Error to connect to Mlx", game);
	game->mlx.window_width = game->map.total_columns * TILE_SIZE;
	game->mlx.window_height = game->map.total_lines * TILE_SIZE;
	game->mlx.win_ptr = mlx_new_window(game->mlx.mlx_ptr,
			game->mlx.window_width, game->mlx.window_height, "So_long!");
	if (game->mlx.win_ptr == NULL)
		game_error("Error to open window!", game);
}

void	load_sprites(t_game *game)
{
	convert_sprite_to_img(game, &game->sprites.collectible, COLLECTIBLE_PATH);
	convert_sprite_to_img(game, &game->sprites.exit, EXIT_PATH);
	convert_sprite_to_img(game, &game->sprites.floor, FLOOR_PATH);
	convert_sprite_to_img(game, &game->sprites.player, PLAYER_PATH);
	convert_sprite_to_img(game, &game->sprites.wall, WALL_PATH);
}

int		render_game(t_game *game)
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
		}
		i++;
	}
	return (0);
}
