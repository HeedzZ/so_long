/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_way.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 11:17:51 by marvin            #+#    #+#             */
/*   Updated: 2023/12/20 11:17:51 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_fill_line(char **map, int line, int *c, int *e)
{
	int	x;
	int	i;

	x = 0;
	while (map[line][x])
	{
		if (map[line][x] == 'X')
		{
			i = x;
			while (map[line][i - 1] != '1')
			{
				i--;
				ft_check_char(map[line][i], c, e);
				map[line][i] = 'X';
			}
			i = x;
			while (map[line][i + 1] != '1')
			{
				i++;
				ft_check_char(map[line][i], c, e);
				map[line][i] = 'X';
			}
		}
		x++;
	}
}

static void	ft_fill_up_down(char **map, int line, int *c, int *e)
{
	int	x;

	x = 0;
	while (map[line][x])
	{
		if (map[line][x] == 'X')
		{
			if (map[line + 1][x] != '1')
			{
				ft_check_char(map[line + 1][x], c, e);
				map[line + 1][x] = 'X';
			}
			if (map[line - 1][x] != '1')
			{
				ft_check_char(map[line - 1][x], c, e);
				map[line - 1][x] = 'X';
			}
		}
		x++;
	}
}

static void	ft_fill_lines(char **map, int *c, int *e, int y)
{
	ft_fill_line(map, y, c, e);
	ft_fill_up_down(map, y, c, e);
}

static int	ft_fill_map(t_game *s_game, char **map)
{
	int		y;
	int		c;
	int		e;
	int		dead_line;

	c = 0;
	e = 0;
	dead_line = 0;
	y = s_game->p_y;
	map[y][s_game->p_x] = 'X';
	while (e != 1 || c != s_game->n_key)
	{
		while (y < s_game->height - 1)
		{
			ft_fill_lines(map, &c, &e, y);
			y++;
		}
		while (y-- > 1)
			ft_fill_lines(map, &c, &e, y);
		if (dead_line++ == s_game->height * s_game->width)
			return (0);
	}
	return (1);
}

int	ft_solve_map(t_game *s_game)
{
	char	**temp_map;

	temp_map = ft_array_strdup(s_game->map);
	if (!temp_map)
		return (0);
	if (!ft_fill_map(s_game, temp_map))
	{
		ft_free_temp_map(temp_map, s_game);
		return (0);
	}
	ft_free_temp_map(temp_map, s_game);
	return (1);
}
