/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaning.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:11:09 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/08 18:33:34 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLEANING_H
# define CLEANING_H

# include "so_long.h"
# include <stdlib.h>
# include "../libs/libft/headers/libft.h"

void	free_ptr_ptr(char **ptr);
void	free_map(t_game *game);
void	free_game(t_game *game);
void	clean_mlx(t_game *game);
void	clean_img(t_game *game);

#endif