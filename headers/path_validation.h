/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_validation.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/09 00:39:50 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/09 02:25:19 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PATH_VALIDATION_H
# define PATH_VALIDATION_H

# include "../headers/render.h"
# include "../headers/map_validation.h"

char	**duplicate_map(t_game *game);
void	player_location(t_copy *copy);
int		is_exit_reachable(int exit, int collec);
int		check_path(t_copy *copy, t_game *game);
void	rewrite_path(t_copy *copy, int line, int col);
int		check_valid_path(t_game *game);

#endif