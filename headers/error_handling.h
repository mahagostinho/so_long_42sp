/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:03:00 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/08 18:13:35 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERROR_HANDLING_H
# define ERROR_HANDLING_H

# include "so_long.h"
# include "../libs/libft/headers/libft.h"
# include "cleaning.h"

void	error_message(char *message);
void	map_error(char *message, t_game *game);
void	game_error(char *message, t_game *game);

#endif