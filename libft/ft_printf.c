/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 21:39:53 by marvin            #+#    #+#             */
/*   Updated: 2023/11/20 21:39:53 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printf_extended(const char format, va_list p_info)
{
	if (format == 'd')
		return (ft_printdec(va_arg(p_info, int)));
	if (format == 'i')
		return (ft_printdec(va_arg(p_info, int)));
	if (format == 'c')
		return (ft_putchar(va_arg(p_info, int)));
	if (format == 's')
		return (ft_putstr(va_arg(p_info, char *)));
	if (format == 'u')
		return (ft_printu(va_arg(p_info, unsigned long long)));
	if (format == 'x')
		return (ft_int_to_hex(va_arg(p_info, unsigned long long)));
	if (format == 'X')
		return (ft_int_to_hexmaj(va_arg(p_info, unsigned long long)));
	if (format == 'p')
		return (ft_print_ptr(va_arg(p_info, unsigned long long)));
	if (format == '%')
		return (ft_putchar('%'));
	return (0);
}

int	ft_printf(const char *format, ...)
{
	va_list	p_info;
	int		i;
	int		size;

	va_start(p_info, format);
	i = 0;
	size = 0;
	while (format[i])
	{
		if (format[i] != '%')
			size += ft_putchar(format[i]);
		if (format[i] == '%')
		{
			size += ft_printf_extended(format[i + 1], p_info);
			i++;
		}
		i++;
	}
	return (size);
}

/*int main(int argc, char const *argv[])
{
	int i = -42;
	printf("%d\n", printf(" %p %p ", 0, 0));
	printf("%d\n", ft_printf(" %p %p ", 0, 0));
	return 0;
}*/
