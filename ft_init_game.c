/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_game.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 15:56:57 by marvin            #+#    #+#             */
/*   Updated: 2023/12/18 15:56:57 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_init_mlx(t_game *s_game)
{
	s_game->mlx_ptr = mlx_init();
	s_game->win_ptr = mlx_new_window(
			s_game->mlx_ptr, (s_game->width) * 64,
			s_game->height * 64, "mlx 42");
	return (1);
}

t_game	*ft_init_map(const char *argv[])
{
	int		fd;
	t_game	*s_game;

	s_game = malloc(sizeof(t_game));
	if (!s_game)
		return (0);
	if (!ft_check_file(argv[1]))
		ft_file_error(s_game);
	fd = open(argv[1], O_RDONLY);
	if (fd == -1)
		ft_file_error(s_game);
	s_game->height = 0;
	s_game->map = ft_parse_map(fd, &s_game->height, &s_game->width);
	close(fd);
	if (!s_game->map)
		return (0);
	return (s_game);
}

void	ft_init_sprites(t_game *s_game)
{
	void	*ptr;
	int		x;
	int		y;

	ptr = s_game->mlx_ptr;
	s_game->img_door = mlx_xpm_file_to_image(ptr, DOOR_XPM, &x, &y);
	s_game->img_door_open = mlx_xpm_file_to_image(ptr, DOOR_OPEN_XPM, &x, &y);
	s_game->img_empty = mlx_xpm_file_to_image(ptr, EMPTY_XPM, &x, &y);
	s_game->img_obst_border = mlx_xpm_file_to_image(ptr, OBST_BOT_XPM, &x, &y);
	s_game->img_obst = mlx_xpm_file_to_image(ptr, OBST_XPM, &x, &y);
	s_game->img_key = mlx_xpm_file_to_image(ptr, KEY_XPM, &x, &y);
	s_game->img_player_right = mlx_xpm_file_to_image(
			ptr, PLAYER_RIGHT_XPM, &x, &y);
	s_game->img_player_left = mlx_xpm_file_to_image(
			ptr, PLAYER_LEFT_XPM, &x, &y);
}

static int	register_pos(t_game *s_game, char c, int x, int y)
{
	if (c == 'P')
	{
		if (s_game->p_x != -1)
			return (0);
		s_game->p_x = x;
		s_game->p_y = y;
	}
	if (c == 'C')
		s_game->n_key++;
	if (c == 'E')
	{
		if (s_game->e_x != -1)
			return (0);
		s_game->e_x = x;
		s_game->e_y = y;
	}
	return (1);
}

int	ft_init_game(t_game *s_game)
{
	int	x;
	int	y;

	s_game->n_key = 0;
	s_game->p_key = 0;
	s_game->p_mouv = 0;
	s_game->e_x = -1;
	s_game->p_x = -1;
	s_game->door_o = 0;
	s_game->p_bool = 0;
	y = 0;
	while (y < s_game->height)
	{
		x = 0;
		while (x < s_game->width + 1)
		{
			if (!register_pos(s_game, s_game->map[y][x], x, y))
				return (0);
			if (s_game->map[y][x] == 'P')
				s_game->map[y][x] = '0';
			x++;
		}
		y++;
	}
	return (1);
}
