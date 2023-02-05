/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_functions.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marcarva <marcarva@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/03 16:29:39 by marcarva          #+#    #+#             */
/*   Updated: 2023/02/03 17:21:57 by marcarva         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../headers/so_long.h"

void	error_message(char *message)
{
	ft_printf("Error\n%s\n", message);
	exit(EXIT_FAILURE);
}
