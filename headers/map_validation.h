/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:31:06 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/08 18:39:33 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_VALIDATION_H
# define MAP_VALIDATION_H

# include <fcntl.h>
# include "so_long.h"
# include "error_handling.h"
# include "../libs/libft/headers/libft.h"

void	parse_map(char *map_file, t_game *game);
void	init_map_variables(t_game *game);
void	read_map(char *map_file, t_game *game);
void	check_map(t_game *game);
void	check_map_characters(t_game *game);
void	check_map_line(char *map_line, t_game *game, int i);
void	is_wall(char component, t_game *game);
void	is_character(char component, t_game *game);

#endif
