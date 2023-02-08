/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input_validation.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:20:49 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/08 18:34:38 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_VALIDATION_H
# define INPUT_VALIDATION_H

# include "../libs/libft/headers/libft.h"
# include "error_handling.h"
# include <fcntl.h>

void	check_cli_input(int argc, char *map_file);
int		check_map_format(char *map_format);

#endif