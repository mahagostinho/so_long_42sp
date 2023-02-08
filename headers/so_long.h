/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:06:43 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/08 18:12:57 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libs/minilibx/mlx.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include "map.h"
# include "sprites.h"

typedef struct s_mlx
{
	int		window_width;
	int		window_height;
	void	*mlx_ptr;
	void	*win_ptr;
}	t_mlx;

typedef struct s_game
{
	t_map		map;
	t_mlx		mlx;
	t_img		img;
	t_sprites	sprites;
	int			moves;
	t_position	player;
}	t_game;

#endif