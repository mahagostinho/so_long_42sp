/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:00:48 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/08 17:45:21 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"
#include "../headers/input_validation.h"
#include "../headers/map_validation.h"
#include "../headers/game_startup.h"
#include "../headers/render.h"

int	main(int argc, char **argv)
{
	t_game	game;

	check_cli_input(argc, argv[1]);
	parse_map(argv[1], &game);
	game_init(&game);
	mlx_hooks(&game);
	mlx_loop(game.mlx.mlx_ptr);
}
