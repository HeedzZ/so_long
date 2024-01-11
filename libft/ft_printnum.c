/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:35:37 by marvin            #+#    #+#             */
/*   Updated: 2023/11/23 14:35:37 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printdec(int nb)
{
	int		size;
	long	n;

	n = nb;
	size = 0;
	if (n < 0)
	{
		size += ft_putchar('-');
		n = -n;
	}
	if (n / 10)
		size += ft_printdec(n / 10);
	return (ft_putchar(n % 10 + '0') + size);
}

int	ft_printu(unsigned int nb)
{
	int	size;

	size = 0;
	if (nb / 10)
		size += ft_printu(nb / 10);
	return (ft_putchar(nb % 10 + '0') + size);
}
