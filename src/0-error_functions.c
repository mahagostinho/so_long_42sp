/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   0-error_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:00:27 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/04 22:06:58 by marcarva         ###   ########.fr       */
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

int	game_error(char *message, t_game *game)
{
	ft_printf("Error\n%s\n", message);
	clean_game(game);
	exit(EXIT_FAILURE);
}