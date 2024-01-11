/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:26:09 by ymostows          #+#    #+#             */
/*   Updated: 2023/11/08 12:26:09 by ymostows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char			*out;
	unsigned int	i;

	if (!s)
		return (0);
	if (start >= ft_strlen(s))
		len = 0;
	else if (len > ft_strlen(s + start))
		len = ft_strlen(s + start);
	out = malloc((len + 1) * sizeof(char));
	if (!out)
		return (0);
	i = 0;
	while (start + i < ft_strlen(s) && i < len)
	{
		out[i] = s[start + i];
		i++;
	}
	out[i] = '\0';
	return (out);
}

/*int main(int argc, char const *argv[])
{
	printf("%s\n", ft_substr("lorem ipsum dolor sit amet", 7, 10));
	return (0);
}*/
