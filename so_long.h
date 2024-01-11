/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/19 22:04:34 by marvin            #+#    #+#             */
/*   Updated: 2024/01/11 14:53:13 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "minilibx-linux/mlx_int.h"
# include "libft/libft.h"
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <X11/keysym.h>
# include <X11/X.h>

//# define KEY_W				119
//# define KEY_A				97
//# define KEY_S				115
//# define KEY_D				100

# define KEY_UP  			119
# define KEY_LEFT  			97
# define KEY_RIGHT 			100
# define KEY_DOWN  			115
# define KEY_Q				113
# define KEY_ESC  			65307

# define DOOR_XPM			"Sprites/Tiles/door_closed.xpm"
# define DOOR_OPEN_XPM		"Sprites/Tiles/door_open.xpm"
# define PLAYER_RIGHT_XPM		"Sprites/Player/player_right.xpm"
# define PLAYER_LEFT_XPM		"Sprites/Player/player_left.xpm"
# define OBST_XPM			"Sprites/Tiles/obst.xpm"
# define OBST_BOT_XPM		"Sprites/Tiles/obst_border.xpm"
# define KEY_XPM			"Sprites/Tiles/key.xpm"
# define EMPTY_XPM			"Sprites/Tiles/empty.xpm"

# define GREEN				"\033[0;32m"
# define RED 				"\033[1;31m"
# define GREY 				"\033[0;90m"
# define CYAN				"\033[1;96m"
# define RESET 				"\033[0m"

typedef struct s_game
{
	char	**map;
	int		width;
	int		height;
	void	*mlx_ptr;
	void	*win_ptr;
	int		x;
	int		y;
	int		p_x;
	int		p_y;
	int		p_key;
	int		p_mouv;
	int		p_bool;
	int		n_key;
	int		e_x;
	int		e_y;
	int		door_o;
	void	*img_door;
	void	*img_door_open;
	void	*img_player_right;
	void	*img_player_left;
	void	*img_obst;
	void	*img_obst_border;
	void	*img_key;
	void	*img_empty;
}					t_game;

char	**ft_parse_map(int fd, int *nb_line, int *nb_chr_line);
int		ft_close_game(t_game *s_game);
int		ft_check_map(t_game *s_game);
int		ft_init_mlx(t_game *s_game);
t_game	*ft_init_map(const char *argv[]);
int		ft_init_game(t_game *s_game);
int		ft_free_all(t_game *s_game);
int		ft_free_map(t_game *s_game);
int		ft_check_error(t_game *s_game, char *msg);
int		ft_file_error(t_game *s_game);
int		ft_error(t_game *s_game, char *msg);
int		ft_render( t_game *s_game);
int		ft_init_game(t_game *s_game);
void	ft_init_sprites(t_game *s_game);
int		ft_check_file(const char *str);
int		ft_win(t_game *s_game);
int		ft_close_game(t_game *s_game);
int		ft_move_player(int keysym, t_game *s_game);
int		ft_solve_map(t_game *s_game);
char	**ft_array_strdup(char **array);
int		ft_check_char(char c, int *count, int *e);
int		ft_free_temp_map(char **map, t_game *s_game);

#endif
