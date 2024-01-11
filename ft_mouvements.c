/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_mouvements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:58:14 by marvin            #+#    #+#             */
/*   Updated: 2023/12/18 15:58:14 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	ft_check_pos(t_game *s_game)
{
	ft_printf(RESET"Mouvements :%d\n", s_game->p_mouv);
	if (s_game->map[s_game->p_y][s_game->p_x] == 'C')
	{
		s_game->p_key++;
		if (s_game->p_key == s_game->n_key)
		{
			s_game->door_o = 1;
			ft_printf(GREEN"key :%d/%d\n"RESET, s_game->p_key, s_game->n_key);
		}
		else
			ft_printf(RED"key :%d/%d\n"RESET, s_game->p_key, s_game->n_key);
		s_game->map[s_game->p_y][s_game->p_x] = '0';
	}
	if (s_game->map[s_game->p_y][s_game->p_x] == 'E')
	{
		if (s_game->p_key == s_game->n_key)
			ft_win(s_game);
	}
	return (1);
}

static int	ft_move_player2(int keysym, t_game *s_game)
{
	if (keysym == KEY_UP)
	{
		if (s_game->map[s_game->p_y - 1][s_game->p_x] != '1')
		{
			s_game->p_mouv++;
			s_game->p_y--;
			ft_check_pos(s_game);
		}
		return (1);
	}
	if (keysym == KEY_LEFT)
	{
		if (s_game->map[s_game->p_y][s_game->p_x - 1] != '1')
		{
			s_game->p_mouv++;
			s_game->p_x--;
			ft_check_pos(s_game);
			s_game->p_bool = 1;
		}
		return (1);
	}
	return (0);
}

int	ft_move_player(int keysym, t_game *s_game)
{
	if (keysym == KEY_ESC || keysym == KEY_Q)
		ft_close_game(s_game);
	if (keysym == KEY_DOWN)
	{
		if (s_game->map[s_game->p_y + 1][s_game->p_x] != '1')
		{
			s_game->p_mouv++;
			s_game->p_y++;
			ft_check_pos(s_game);
		}
		return (1);
	}
	if (keysym == KEY_RIGHT)
	{
		if (s_game->map[s_game->p_y][s_game->p_x + 1] != '1')
		{
			s_game->p_mouv++;
			s_game->p_x++;
			ft_check_pos(s_game);
			s_game->p_bool = 0;
		}
		return (1);
	}
	return (ft_move_player2(keysym, s_game));
}
