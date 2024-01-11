/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ymostows <ymostows@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/08 10:57:47 by ymostows          #+#    #+#             */
/*   Updated: 2023/11/14 17:35:48 by ymostows         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_nb_len(long int nb)
{
	if (nb == 0)
		return (1);
	if (nb < 0)
		nb = -nb;
	if (nb / 10 > 0)
		return (ft_nb_len(nb / 10) + 1);
	return (1);
}

static void	ft_insert_nb(char *out, long int nb, int i)
{
	if (nb < 0)
		nb = -nb;
	if (nb >= 10)
	{
		ft_insert_nb(out, nb / 10, i - 1);
		out[i] = nb % 10 + '0';
	}
	else if (nb <= 9)
		out[i] = nb + '0';
}

char	*ft_itoa(int n)
{
	int		i;
	int		nb_len;
	char	*out;

	if (n < 0)
		nb_len = ft_nb_len(n) + 1;
	else
		nb_len = ft_nb_len(n);
	out = malloc((nb_len + 1) * sizeof(char));
	if (!out)
		return (0);
	if (n < 0)
		out[0] = '-';
	i = nb_len - 1;
	ft_insert_nb(out, n, i);
	out[nb_len] = '\0';
	return (out);
}

/*int	main(int argc, char const *argv[])
{
	printf("%s\n", ft_itoa(2147483647));
	return (0);
}*/
