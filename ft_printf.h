/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agnesgar <agnesgar@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 18:31:39 by agnesgar          #+#    #+#             */
/*   Updated: 2024/06/15 14:53:09 by agnesgar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdio.h> // debug
# include <unistd.h> // write
# include <stdarg.h> // macros for printf
# include <limits.h> // debug

// for printf
int				print_format(char type, va_list ap);
int				ft_printf(const char *format, ...);

// for digits and ints
int				print_digit(long num);

// for unsigned ints
unsigned int	print_unsigned(unsigned int num);

// for hexadecimals
unsigned int	print_hexa(unsigned int num, char type, int base);

// for pointers TODO
int				print_pointer(unsigned long p);
void			ft_putchar(char c);
int				ft_putstr(char *s);

// for chars & strings
int				print_char(int c);
int				print_string(char *str);

#endif