/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_error.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:50:10 by marvin            #+#    #+#             */
/*   Updated: 2023/12/18 15:50:10 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_error(t_game *s_game, char *msg)
{
	ft_printf(RED"Error\n"RESET"%s\n", msg);
	ft_close_game(s_game);
	return (0);
}

int	ft_file_error(t_game *s_game)
{
	free(s_game);
	ft_printf(RED"Error\n"RESET"%s\n",
		"The map file doesn't exist or it's not .ber !\n");
	ft_printf(GREY"CLOSED\n"RESET);
	exit (EXIT_FAILURE);
	return (0);
}

int	ft_check_error(t_game *s_game, char *msg)
{
	ft_free_map(s_game);
	free(s_game);
	ft_printf(RED"Error\n"RESET"%s\n", msg);
	ft_printf(GREY"CLOSED\n"RESET);
	exit (EXIT_FAILURE);
	return (0);
}
