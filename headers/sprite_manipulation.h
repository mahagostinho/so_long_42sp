/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_manipulation.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 17:52:14 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/08 18:15:11 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITE_MANIPULATION_H
# define SPRITE_MANIPULATION_H

# include "../libs/libft/headers/libft.h"
# include "so_long.h"
# include "error_handling.h"

void	load_sprites(t_game *game);
void	convert_sprite_to_img(t_game *game, t_img *sprite, char *path);
void	put_sprite(t_game *game, int i, int j);

#endif