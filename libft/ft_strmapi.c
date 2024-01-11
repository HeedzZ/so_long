/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:24:56 by ymostows          #+#    #+#             */
/*   Updated: 2023/11/08 12:24:56 by ymostows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t	len;
	size_t	i;
	char	*out;

	if (!s)
		return (0);
	len = ft_strlen((char *)s);
	out = malloc((len + 1) * sizeof(char));
	if (!out)
		return (0);
	i = 0;
	while (s[i])
	{
		out[i] = (*f)((unsigned int)i, (char)s[i]);
		i++;
	}
	out[i] = '\0';
	return (out);
}
