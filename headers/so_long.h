/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 10:06:43 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/03 17:15:31 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

/* ***************** HEADERS *************************** */
# include "libs.h"

/* ***************** FUNCTIONS ************************** */
void	check_input(int argc, char *map_file);
void	error_message(char *message);
int		check_map_format(char *map_format);


#endif