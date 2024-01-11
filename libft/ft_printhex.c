/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:40:40 by marvin            #+#    #+#             */
/*   Updated: 2023/11/23 14:40:40 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_int_to_hex(unsigned int n)
{
	char	*hex;
	int		size;

	hex = "0123456789abcdef";
	size = 0;
	if (n / 16)
		size += ft_int_to_hex(n / 16);
	return (ft_putchar(hex[n % 16]) + size);
}

int	ft_int_to_hexmaj(unsigned int n)
{
	char	*hex;
	int		size;

	hex = "0123456789ABCDEF";
	size = 0;
	if (n / 16)
		size += ft_int_to_hexmaj(n / 16);
	return (ft_putchar(hex[n % 16]) + size);
}
