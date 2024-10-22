/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agnesgar <agnesgar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:31:39 by agnesgar          #+#    #+#             */
/*   Updated: 2024/06/15 14:53:09 by agnesgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	print_format(char type, va_list ap)
{
	int	count;

	count = 0;
	if (type == 'c')
		count += print_char(va_arg(ap, int));
	else if (type == 's')
		count += print_string(va_arg(ap, char *));
	else if (type == 'i')
		count += print_digit(va_arg(ap, int));
	else if (type == 'u')
		count += print_unsigned(va_arg(ap, unsigned int));
	else if (type == 'd')
		count += print_digit((long)(va_arg(ap, int)));
	else if (type == 'x' || type == 'X')
		count += print_hexa((va_arg(ap, unsigned int)), type, 16);
	else if (type == 'p')
		count += print_pointer(va_arg(ap, unsigned long));
	else
		count += write(1, &type, 1);
	return (count);
}

int	ft_printf(const char *format, ...)
{
	int		total;
	va_list	ap;

	total = 0;
	va_start (ap, format);
	while (*format)
	{
		if (*format == '%')
			total += print_format(*(++format), ap);
		else
			total += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (total);
}
