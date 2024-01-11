/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:33:15 by marvin            #+#    #+#             */
/*   Updated: 2023/12/18 15:33:15 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_free_all(t_game *s_game)
{
	mlx_destroy_window(s_game->mlx_ptr, s_game->win_ptr);
	mlx_destroy_image(s_game->mlx_ptr, s_game->img_door);
	mlx_destroy_image(s_game->mlx_ptr, s_game->img_door_open);
	mlx_destroy_image(s_game->mlx_ptr, s_game->img_empty);
	mlx_destroy_image(s_game->mlx_ptr, s_game->img_key);
	mlx_destroy_image(s_game->mlx_ptr, s_game->img_obst);
	mlx_destroy_image(s_game->mlx_ptr, s_game->img_obst_border);
	mlx_destroy_image(s_game->mlx_ptr, s_game->img_player_right);
	mlx_destroy_image(s_game->mlx_ptr, s_game->img_player_left);
	mlx_destroy_display(s_game->mlx_ptr);
	free(s_game->mlx_ptr);
	ft_free_map(s_game);
	free(s_game);
	return (0);
}

int	ft_free_map(t_game *s_game)
{
	int	i;

	i = 0;
	while (i < s_game->height)
	{
		free(s_game->map[i]);
		i++;
	}
	free(s_game->map);
	return (0);
}
