/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1-input.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:00:14 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/04 17:00:17 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

int	check_map_format(char *map_format)
{
	if (ft_strncmp(map_format, ".ber", 4) == 0)
		return (0);
	return (1);
}

void	check_input(int argc, char *map_file)
{
	int	file_descriptor;

	if (argc == 1)
		error_message("Missing map file (*.ber).");
	if (argc > 2)
		error_message("Too many arguments!");
	if (argc == 2 && check_map_format(&map_file[ft_strlen(map_file) - 4]))
		error_message("Invalid map format. The map must be .ber extension.");
	file_descriptor = open(map_file, O_RDONLY);
	if (file_descriptor == -1)
	{
		close(file_descriptor);
		error_message("Wrong file path/name or non-existent file.");
	}
}
