/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/14 18:42:20 by marvin            #+#    #+#             */
/*   Updated: 2023/12/14 18:42:20 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_file(const char *str)
{
	int	i;

	i = 0;
	while (str[i] != '.' && str[i] != '\0')
		i++;
	if (str[i] == '.')
	{
		if (ft_strcmp(&str[i], ".ber") == 0)
			return (1);
	}
	return (0);
}

static int	check_map_border(t_game *s_game)
{
	int	i;

	i = 0;
	while (i < s_game->width)
	{
		if (s_game->map[0][i] != '1')
			return (0);
		if (s_game->map[s_game->height - 1][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < s_game->height - 1)
	{
		if (s_game->map[i][0] != '1')
			return (0);
		if (s_game->map[i][s_game->width - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	check_char(char c, char *lst_char)
{
	int	i;

	i = 0;
	while (lst_char[i])
	{
		if (c == lst_char[i])
			return (1);
		i++;
	}
	return (0);
}

static int	check_lines(t_game *s_game)
{
	int	x;
	int	y;
	int	len_x;

	x = 0;
	y = 0;
	len_x = 0;
	while (s_game->map[0][len_x + 1])
		len_x++;
	while (s_game->map[y] != 0)
	{
		x = 0;
		while (s_game->map[y][x + 1])
		{
			if (!check_char(s_game->map[y][x], "01CEP"))
				return (-1);
			x++;
		}
		if (x != len_x)
			return (0);
		y++;
	}
	return (1);
}

int	ft_check_map(t_game *s_game)
{
	int	int_check_lines;

	int_check_lines = check_lines(s_game);
	if (int_check_lines == 0)
		return (ft_check_error(s_game, "The map is not rectangular !"));
	if (int_check_lines == -1)
		return (ft_check_error(s_game, "An invalid character is in the map !"));
	if (!ft_init_game(s_game))
		return (ft_check_error(s_game, "There must be no duplication !"));
	if (s_game->e_x == -1)
		return (ft_check_error(s_game,
				"You must have 1 exit in your map to play !"));
	if (s_game->p_x == -1)
		return (ft_check_error(s_game,
				"You must have 1 player in your map to play !"));
	if (s_game->n_key < 1)
		return (ft_check_error(s_game,
				"You must have 1 item in your map to play !"));
	if (!check_map_border(s_game))
		return (ft_check_error(s_game, "Borders are not closed !"));
	return (1);
}
