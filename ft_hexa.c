/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agnesgar <agnesgar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:31:39 by agnesgar          #+#    #+#             */
/*   Updated: 2024/06/15 14:53:09 by agnesgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	print_hexa(unsigned int num, char type, int base)
{
	int		count;
	char	*symbols;

	count = 0;
	if (num == 0)
		return (print_char('0'));
	else
	{
		if (type == 'x')
			symbols = "0123456789abcdef";
		else if (type == 'X')
			symbols = "0123456789ABCDEF";
		if (num < base)
			return (print_char(symbols[num]));
		else
		{
			count = print_hexa(num / base, type, base);
			return (count + print_hexa(num % base, type, base));
		}
	}
}
