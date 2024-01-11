/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 12:25:09 by ymostows          #+#    #+#             */
/*   Updated: 2023/11/08 12:25:09 by ymostows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t			i;
	unsigned char	*us1;
	unsigned char	*us2;

	us1 = (unsigned char *)s1;
	us2 = (unsigned char *)s2;
	i = 0;
	while (n--)
	{
		if (us1[i] != us2[i] || us1[i] == 0 || us2[i] == 0)
			return (us1[i] - us2[i]);
		i++;
	}
	return (0);
}

/*int main(int argc, char const *argv[])
{
	printf("%d\n", ft_strncmp(argv[1], argv[2],
			(size_t)atoi((char *)argv[3])));
	return (0);
}*/
