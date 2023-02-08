/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:46:16 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/08 18:33:20 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RENDER_H
# define RENDER_H

# include "so_long.h"
# include "cleaning.h"

int		render_game(t_game *game);
int		close_game(t_game *game);
void	player_wins(t_game *game);
int		handle_keypress(int keysym, t_game *game);
void	move_player(t_game *game, int new_i, int new_j);
void	mlx_hooks(t_game *game);

#endif