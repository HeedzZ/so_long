/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:25:22 by ymostows          #+#    #+#             */
/*   Updated: 2023/11/08 12:25:22 by ymostows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t len)
{
	size_t	i;
	size_t	l_s1;
	size_t	l_s2;
	size_t	l;

	if (len <= 0 && (!s1 || !s2))
		return (0);
	i = 0;
	l = len;
	l_s1 = ft_strlen(s1);
	l_s2 = ft_strlen(s2);
	if (s2[i] == '\0')
		return ((char *)s1);
	if (l_s1 < l_s2 || len < l_s2)
		return (0);
	while (s1[i] && l-- >= l_s2)
	{
		if (ft_memcmp(s1 + i, s2, l_s2) == 0)
			return ((char *)s1 + i);
		i++;
	}
	return (0);
}
