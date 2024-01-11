/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:23:45 by ymostows          #+#    #+#             */
/*   Updated: 2023/11/08 12:23:45 by ymostows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	len;
	char	*out;

	if (!s1 && !s1)
		return (0);
	len = ft_strlen((char *)s1) + ft_strlen((char *)s2);
	out = malloc((len + 1) * sizeof(char));
	if (!out)
		return (0);
	ft_strcpy(out, (char *)s1);
	ft_strcpy(out + ft_strlen((char *)s1), (char *)s2);
	return (out);
}
