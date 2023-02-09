/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:50:37 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/09 01:11:28 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_H
# define MAP_H

# include <stdlib.h>

# define SPACE '0'
# define WALL '1'
# define COLLECTIBLE 'C'
# define EXIT 'E'
# define PLAYER 'P'
# define TILE_SIZE 32

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

typedef struct s_position
{
	int	i;
	int	j;
}	t_position;

#endif
