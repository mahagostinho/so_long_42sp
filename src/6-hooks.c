/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6-hooks.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 14:57:10 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/06 19:10:54 by marcarva         ###   ########.fr       */
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
	return (0);
}

void	mlx_hooks(t_game *game)
{
	// loop para caso de não ocorrer evento
	mlx_loop_hook(game->mlx.mlx_ptr, &render_game, game);
	// evento de teclado
	mlx_hook(game->mlx.win_ptr, KeyPress, KeyPressMask, &handle_keypress, game);
	// fechar a janela no x
	mlx_hook(game->mlx.win_ptr, DestroyNotify, ButtonPressMask, &close_game, game);
}
