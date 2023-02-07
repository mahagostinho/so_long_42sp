/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:06:43 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/07 16:23:49 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* **************** HEADERS ************************** */
# include "libs.h"

/* **************** MACROS *************************** */
/* MAP */
# define SPACE '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define TILE_SIZE 32

/* SPRITE'S PATH */
# define WALL_PATH			"assets/sprites/wall.xpm"
# define FLOOR_PATH			"assets/sprites/floor.xpm"
# define COLLECTIBLE_PATH	"assets/sprites/collectible.xpm"
# define PLAYER_PATH		"assets/sprites/player.xpm"
# define EXIT_PATH			"assets/sprites/exit.xpm"

/* **************** STRUCTS ************************** */

typedef struct s_map
{
	char	**map_grid;
	char	*map_vector;
	int		total_lines;
	size_t	total_columns;
	int		total_exit;
	int		total_player;
	int		total_collectible;
}	t_map;

typedef struct s_img
{
	void	*img_ptr;
	char	*addr;
	int		bpp;
	int		line_len;
	int		endian;
	int		width;
	int		height;
}	t_img;

typedef struct s_sprites
{
	t_img	wall;
	t_img	floor;
	t_img	collectible;
	t_img	player;
	t_img	exit;
}	t_sprites;

typedef struct s_mlx
{
	int		window_width;
	int		window_height;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

typedef struct s_position
{
	int	i;
	int	j;
}	t_position;

typedef struct s_game
{
	t_map		map;
	t_mlx		mlx;
	t_img		img;
	t_sprites	sprites;
	int			moves;
	t_position	player;
}	t_game;

/* ***************** FUNCTIONS ************************** */

void	check_input(int argc, char *map_file);
int		check_map_format(char *map_format);
void	error_message(char *message);
void	map_error(char *message, t_game *game);
void	game_error(char *message, t_game *game);
void	free_ptr_ptr(char **ptr);
void	free_map(t_game *game);
void	free_game(t_game *game);
void	init_map_variables(t_game *game);
void	read_map(char *map_file, t_game *game);
void	check_map_characters(t_game *game);
void	check_map_line(char *map_line, t_game *game, int i);
void	check_map(t_game *game);
void	parse_map(char *map_file, t_game *game);
void	create_window(t_game *game);
void	convert_sprite_to_img(t_game *game, t_img *sprite, char *path);
void	load_sprites(t_game *game);
int		render_game(t_game *game);
void	put_sprite(t_game *game, int i, int j);
void	mlx_hooks(t_game *game);
void	game_init(t_game *game);
void	move_player(t_game *game, int new_i, int new_j);
void	print_movements(t_game *game);
#endif
