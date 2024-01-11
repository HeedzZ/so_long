/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_render.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:54:59 by marvin            #+#    #+#             */
/*   Updated: 2023/12/18 15:54:59 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	print_bloc(t_game *s_game, void *img_ptr, int x, int y)
{
	mlx_put_image_to_window (s_game->mlx_ptr, s_game->win_ptr, img_ptr, x, y);
	return (1);
}

static int	chose_sprite(char c, t_game *s_game)
{
	if (c == '0')
		return (print_bloc(s_game, s_game->img_empty, s_game->x, s_game->y));
	if (c == '1')
	{
		if (((s_game->width - 1) == (s_game->x / 64))
			|| ((s_game->height - 1) == (s_game->y / 64))
			|| (0 == (s_game->y / 64)) || (0 == (s_game->x / 64)))
			return (print_bloc(s_game, s_game->img_obst, s_game->x, s_game->y));
		else
			return (print_bloc(s_game, s_game->img_obst_border,
					s_game->x, s_game->y));
	}
	if (c == 'C')
		return (print_bloc(s_game, s_game->img_key, s_game->x, s_game->y));
	if (c == 'E')
	{
		if (s_game->door_o == 0)
			return (print_bloc(s_game, s_game->img_empty, s_game->x, s_game->y)
				+ print_bloc(s_game, s_game->img_door, s_game->x, s_game->y));
		else
			return (print_bloc(s_game, s_game->img_empty, s_game->x, s_game->y)
				+ print_bloc(
					s_game, s_game->img_door_open, s_game->x, s_game->y));
	}
	return (0);
}

static int	ft_print_map(t_game *s_game)
{
	int	x;
	int	y;

	y = 0;
	while (y < s_game->height)
	{
		x = 0;
		while (x < s_game->width)
		{
			if (x == s_game->p_x && y == s_game->p_y)
				x++;
			s_game->x = x * 64;
			s_game->y = y * 64;
			chose_sprite(s_game->map[y][x], s_game);
			x++;
		}
		y++;
	}
	return (1);
}

static int	ft_print_player(t_game *s_game)
{
	if (s_game->p_bool == 0)
		print_bloc(s_game, s_game->img_player_right,
			s_game->p_x * 64, s_game->p_y * 64);
	if (s_game->p_bool == 1)
		print_bloc(s_game, s_game->img_player_left,
			s_game->p_x * 64, s_game->p_y * 64);
	return (1);
}

int	ft_render( t_game *s_game)
{
	ft_print_map(s_game);
	ft_print_player(s_game);
	return (1);
}
