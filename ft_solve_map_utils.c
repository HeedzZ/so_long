/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_solve_map_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/20 14:09:01 by marvin            #+#    #+#             */
/*   Updated: 2023/12/20 14:09:01 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_array_strdup(char **array)
{
	char	**array_out;
	int		i;
	int		len;

	len = 0;
	while (array[len] != 0)
		len++;
	array_out = malloc((len) * sizeof(char *));
	if (!array_out)
		return (0);
	i = 0;
	while (i < len)
	{
		array_out[i] = ft_strdup(array[i]);
		if (!array_out[i])
			return (0);
		i++;
	}
	return (array_out);
}

int	ft_check_char(char c, int *count, int *e)
{
	if (c == 'E')
		*e = *e + 1;
	if (c == 'C')
		*count = *count + 1;
	return (0);
}

int	ft_free_temp_map(char **map, t_game *s_game)
{
	int	i;

	i = 0;
	while (i < s_game->height)
	{
		free(map[i]);
		i++;
	}
	free(map);
	return (1);
}
