/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2-map.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 17:00:01 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/04 22:26:39 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

//void	check_map(t_game *game);

void	read_map(char *map_file, t_game *game)
{
	int		fd;
	char	*aux;
	int		gnl;

	fd = open(map_file, O_RDONLY);
	gnl = 1;
	while (gnl == 1)
	{
		gnl = get_next_line(fd, &aux);
		if (gnl == -1)
			error_message("Problems to read the file.");
		if (gnl == 0 || gnl == 1)
		{
			game->map.total_lines++;
			if (game->map.total_lines == 1)
				game->map.total_columns = ft_strlen(aux);
			gnl_strjoin(&(game->map.map_vector), aux);
			if (game->map.map_vector == NULL)
				map_error("Memory allocation error", game);
		}
		free_ptr_ptr(&aux);
	}
	ft_printf("%s", game->map.map_vector); //apagar depois ************************************
	free_ptr_ptr(&aux);
	close(fd);
}

void	init_map_variables(t_game *game)
{
	game->map.total_lines = 0;
	game->map.total_columns = 0;
	game->map.map_vector = ft_strdup("");
	if (game->map.map_vector == NULL)
	{
		free(game->map.map_vector);
		error_message("Memory allocation error!");
	}
	game->map.map_grid = NULL;
	game->map.total_collectible = 0;
	game->map.total_exit = 0;
	game->map.total_player = 0;
}

void	parse_map(char *map_file, t_game *game)
{
	init_map_variables(game);
	read_map(map_file, game);
	game->map.map_grid = ft_split(game->map.map_vector, '\n');
	if (game->map.map_grid == NULL)
		game_error("Error to create map matrix", game);
	/*
	ft_printf(game->map.map_grid[0]);
	free(game->map.map_vector);
	free(game->map.map_grid[0]);
	free(game->map.map_grid[1]);
	free(game->map.map_grid[2]);
	free(game->map.map_grid[3]);
	free(game->map.map_grid[4]);
	*/
	check_map(game)
}
