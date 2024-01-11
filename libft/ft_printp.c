/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 14:39:54 by marvin            #+#    #+#             */
/*   Updated: 2023/11/23 14:39:54 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_u_to_hex(uintptr_t n)
{
	char	*hex;
	int		size;

	hex = "0123456789abcdef";
	size = 0;
	if (n / 16)
		size += ft_u_to_hex(n / 16);
	return (ft_putchar(hex[n % 16]) + size);
}

int	ft_print_ptr(unsigned long long ptr)
{
	int	size;

	if (!ptr)
		return (ft_putstr("(nil)"));
	size = 0;
	size += ft_putstr("0x");
	if (ptr == 0)
		size += ft_putchar('0');
	else
		size += ft_u_to_hex(ptr);
	return (size);
}
