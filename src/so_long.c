/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:00:48 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/06 14:52:33 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h" 

int	main(int argc, char **argv)
{
	t_game	game;

	check_input(argc, argv[1]);
	parse_map(argv[1], &game);
	game_init(&game);
	mlx_hooks(&game);
	mlx_loop(game.mlx.mlx_ptr);
}
