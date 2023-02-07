/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6-hooks.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:57:10 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/07 15:48:00 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	close_game(t_game *game)
{
	free_game(game);
	ft_printf("Closed\n");
	exit(EXIT_FAILURE);
}

int	handle_keypress(int keysym, t_game *game)
{
	if (keysym == XK_Escape)
		close_game(game);
	if (keysym == XK_d || keysym == XK_Right)
		move_player(game, game->player.i, game->player.j + 1);
	if (keysym == XK_a || keysym == XK_Left)
		move_player(game, game->player.i, game->player.j - 1);
	if (keysym == XK_w || keysym == XK_Up)
		move_player(game, game->player.i - 1, game->player.j);
	if (keysym == XK_s || keysym == XK_Down)
		move_player(game, game->player.i + 1, game->player.j);
	return (0);
}

void	mlx_hooks(t_game *game)
{
	mlx_hook(game->mlx.win_ptr, KeyPress, KeyPressMask, &handle_keypress, game);
	mlx_hook(game->mlx.win_ptr, DestroyNotify, ButtonPressMask,
		&close_game, game);
	mlx_loop_hook(game->mlx.mlx_ptr, &render_game, game);
}
