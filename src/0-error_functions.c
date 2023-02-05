/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0-error_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:00:27 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/05 19:10:25 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	error_message(char *message)
{
	ft_printf("Error\n%s\n", message);
	exit(EXIT_FAILURE);
}

void	map_error(char *message, t_game *game)
{
	free_map(game);
	ft_printf("Error\n%s\n", message);
	exit(EXIT_FAILURE);
}

void	game_error(char *message, t_game *game)
{
	ft_printf("Error\n%s\n", message);
	free_game(game);
	exit(EXIT_FAILURE);
}
