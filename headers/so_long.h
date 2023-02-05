/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:06:43 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/04 22:08:42 by marcarva         ###   ########.fr       */
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
# define VALID_CHAR '01CEP'

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

typedef struct s_game
{
	t_map	map;
}	t_game;

/* ***************** FUNCTIONS ************************** */
void	check_input(int argc, char *map_file);
void	error_message(char *message);
void	free_ptr_ptr(char **ptr);
void	free_map(t_game *game);
void	map_error(char *message, t_game *game);
int		game_error(char *message, t_game *game);

int		check_map_format(char *map_format);
void	parse_map(char *map_file, t_game *game);
void	init_map_variables(t_game *game);
void	read_map(char *map_file, t_game *game);

void	clean_game(t_game *game);
//void	check_map(t_game *game);
#endif
