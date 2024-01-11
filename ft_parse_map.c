/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_parse_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/12 14:19:33 by marvin            #+#    #+#             */
/*   Updated: 2023/12/12 14:19:33 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	*ft_str_map(int fd, int *nb_line, char *line)
{
	char	*str_map;

	str_map = malloc(sizeof(char));
	if (!str_map)
		return (0);
	*str_map = 0;
	while (line != 0)
	{
		if (*nb_line != 0)
		{
			line = get_next_line(fd);
			if (!line)
				break ;
		}
		str_map = ft_strjoin_gnl(str_map, line);
		if (!str_map)
			return (0);
		free(line);
		*nb_line = *nb_line + 1;
	}
	return (str_map);
}

char	**ft_parse_map(int fd, int *nb_line, int *nb_chr_line)
{
	char	*line;
	char	*str_map;
	char	**map;

	line = get_next_line(fd);
	if (!line)
		return (0);
	*nb_chr_line = ft_strlen(line) - 2;
	str_map = ft_str_map(fd, nb_line, line);
	if (!str_map)
		return (0);
	map = ft_split(str_map, '\n');
	if (!map)
		return (0);
	free(str_map);
	return (map);
}
