/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pointers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agnesgar <agnesgar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:31:39 by agnesgar          #+#    #+#             */
/*   Updated: 2024/06/15 14:53:09 by agnesgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdint.h>

static void	recursive_pointer(unsigned long p)
{
	if (p >= 16)
	{
		recursive_pointer(p / 16);
		recursive_pointer(p % 16);
	}
	else
	{
		if (p < 10)
			print_char(p + '0');
		else
			print_char(p - 10 + 'a');
	}
}

static int	length_pointer(unsigned long p)
{
	int	len;

	len = 0;
	if (p == 0)
		return (1);
	while (p > 0)
	{
		len++;
		p /= 16;
	}
	return (len);
}

int	print_pointer(unsigned long p)
{
	int				count;

	count = 0;
	if (p == 0)
		return (ft_putstr("(nil)"));
	count += print_string("0x");
	if (p == 0)
		count += print_char('0');
	else
	{
		recursive_pointer(p);
		count += length_pointer(p);
	}
	return (count);
}
