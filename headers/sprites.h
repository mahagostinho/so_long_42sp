/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:46:08 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/08 17:48:55 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SPRITES_H
# define SPRITES_H

# define WALL_PATH			"assets/sprites/wall.xpm"
# define FLOOR_PATH			"assets/sprites/floor.xpm"
# define COLLECTIBLE_PATH	"assets/sprites/collectible.xpm"
# define PLAYER_PATH		"assets/sprites/player.xpm"
# define EXIT_PATH			"assets/sprites/exit.xpm"

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

#endif