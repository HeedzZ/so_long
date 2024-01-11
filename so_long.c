/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 15:19:35 by marvin            #+#    #+#             */
/*   Updated: 2023/12/12 15:19:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char const *argv[])
{
	t_game		*s_game;

	if (argc == 2)
	{
		s_game = ft_init_map(argv);
		if (!s_game)
			return (0);
		if (!ft_check_map(s_game))
			return (0);
		if (!ft_solve_map(s_game))
			return (ft_check_error(s_game, "This map is not winnable !"));
		ft_init_mlx(s_game);
		ft_init_sprites(s_game);
		mlx_hook(s_game->win_ptr, KeyPress, KeyPressMask,
			&ft_move_player, s_game);
		mlx_hook(s_game->win_ptr, DestroyNotify, \
		ButtonPressMask, ft_close_game, s_game);
		mlx_loop_hook(s_game->mlx_ptr, &ft_render, s_game);
		mlx_loop(s_game->mlx_ptr);
	}
	else
		ft_printf(RED"Error\n"RESET"Invalid argument !\n");
	return (0);
}
