/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_digit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agnesgar <agnesgar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:31:39 by agnesgar          #+#    #+#             */
/*   Updated: 2024/06/15 14:53:09 by agnesgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <limits.h>

int	print_digit(long num)
{
	int		count;
	char	*symbols;

	symbols = "0123456789";
	count = 0;
	if (num < 0)
	{
		write(1, "-", 1);
		return (print_digit(-num) + 1);
	}
	else if (num < 10)
		return (print_char(symbols[num]));
	else
	{
		count = print_digit(num / 10);
		return (count + print_digit(num % 10));
	}
}

unsigned int	print_unsigned(unsigned int num)
{
	unsigned int	count;

	count = 0;
	if (num > INT_MAX)
	{
		count = print_unsigned(num / 10);
		return (count + print_unsigned(num % 10));
	}
	else
		return (print_digit(num));
}
