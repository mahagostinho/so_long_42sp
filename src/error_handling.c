/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:00:27 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/08 16:05:30 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/error_handling.h"

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
