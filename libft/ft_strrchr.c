/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:25:39 by ymostows          #+#    #+#             */
/*   Updated: 2023/11/08 12:25:39 by ymostows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	tofind;

	tofind = (unsigned char)c;
	i = ft_strlen((char *)s);
	while (i > 0)
	{
		if (s[i] == tofind)
			return ((char *)&s[i]);
		i--;
	}
	if (s[i] == tofind)
		return ((char *)&s[i]);
	return (0);
}
