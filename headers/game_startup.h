/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_startup.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:44:14 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/08 18:13:46 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GAME_STARTUP_H
# define GAME_STARTUP_H

# include "so_long.h"
# include "error_handling.h"
# include "map_validation.h"

void	create_window(t_game *game);
void	game_init(t_game *game);

#endif