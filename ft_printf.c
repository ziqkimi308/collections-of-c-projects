/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhakimi- <mhakimi-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 21:54:55 by mhakimi-          #+#    #+#             */
/*   Updated: 2024/11/22 20:49:43 by mhakimi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_parse_flags(const char **str, t_flags *flags)
{
	flags->plus = 0;
	flags->hash = 0;
	flags->space = 0;
	while (**str == '+' || **str == ' ' || **str == '#')
	{
		if (**str == '+')
			flags->plus = 1;
		else if (**str == ' ')
			flags->space = 1;
		else if (**str == '#')
			flags->hash = 1;
		(*str)++;
	}
}

static void	ft_check_flags(va_list args, const char **str, int *len)
{
	t_flags	flags;

	ft_parse_flags(str, &flags);
	if (**str == 'd' || **str == 'i')
		ft_putnbr(va_arg(args, int), len, &flags);
	else if (**str == 'u')
		ft_putnbr_unsigned(va_arg(args, unsigned int), len);
	else if (**str == 'c')
		ft_putchar((char)va_arg(args, int), len);
	else if (**str == 's')
		ft_putstr(va_arg(args, char *), len);
	else if (**str == '%')
		ft_putchar(**str, len);
	else if (**str == 'x' || **str == 'X')
		ft_putnbr_base(va_arg(args, int), **str, len, &flags);
	else if (**str == 'p')
		ft_putaddr(va_arg(args, void *), len);
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
		{
			str++;
			ft_check_flags(args, &str, &len);
		}
		else
			ft_putchar(*str, &len);
		str++;
	}
	va_end(args);
	return (len);
}
/********** DON"T CHANGE CODE ABOVE THIS ******************/
/*
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // Basic Test Cases
    printf("Expected Output: |Hello, world!|\n");
    ft_printf("Your ft_printf Output: |Hello, %s!|\n\n", "world");

    printf("Expected Output: |Number: 42|\n");
    ft_printf("Your ft_printf Output: |Number: %d|\n\n", 42);

    printf("Expected Output: |Hex: ff|\n");
    ft_printf("Your ft_printf Output: |Hex: %x|\n\n", 255);

    printf("Expected Output: |Character: A|\n");
    ft_printf("Your ft_printf Output: |Character: %c|\n\n", 'A');

    printf("Expected Output: |Unsigned int: 12345|\n");
    ft_printf("Your ft_printf Output: |Unsigned int: %u|\n\n", 12345);

    printf("Expected Output: |Pointer: %p|\n", &main);
    ft_printf("Your ft_printf Output: |Pointer: %p|\n\n", &main);

    printf("Expected Output: |Percentage sign: %%|\n");
    ft_printf("Your ft_printf Output: |Percentage sign: %%|\n\n");

    // Edge Cases
    printf("Expected Output: |Empty string: |\n");
    ft_printf("Your ft_printf Output: |Empty string: %s|\n\n", "");

    printf("Expected Output: |Null string: (null)|\n");
    ft_printf("Your ft_printf Output: |Null string: %s|\n\n", NULL);

    printf("Expected Output: |Negative number: -12345|\n");
    ft_printf("Your ft_printf Output: |Negative number: %d|\n\n", -12345);

    printf("Expected Output: |Large number: 2147483647|\n");
    ft_printf("Your ft_printf Output: |Large number: %d|\n\n",
    2147483647); // INT_MAX

    printf("Expected Output: |Small number: -2147483648|\n");
    ft_printf("Your ft_printf Output: |Small number: %d|\n\n",
    -2147483648); // INT_MIN

    // Hexadecimal with uppercase
    printf("Expected Output: |Hex (uppercase): FF|\n");
    ft_printf("Your ft_printf Output: |Hex (uppercase): %X|\n\n", 255);

    // Testing flags
    printf("Expected Output: |Plus flag: +42|\n");
    ft_printf("Your ft_printf Output: |Plus flag: %+d|\n\n", 42);

    printf("Expected Output: |Space flag:  42|\n");
    ft_printf("Your ft_printf Output: |Space flag: % d|\n\n", 42);

    printf("Expected Output: |Space flag with negative: -42|\n");
    ft_printf("Your ft_printf Output: |Space flag with negative: % d|\n\n", -42);

    printf("Expected Output: |Hash flag: 0xff|\n");
    ft_printf("Your ft_printf Output: |Hash flag: %#x|\n\n", 255);

    // Edge case for unsigned
    printf("Expected Output: |Max unsigned: 4294967295|\n");
    ft_printf("Your ft_printf Output: |Max unsigned: %u|\n\n", 4294967295u);

    // Multiple types in one format string
    printf("Expected Output: |String: Hello, Number: 42, Hex: ff, Char: A|\n");
    ft_printf("Your ft_printf Output: |String: %s, Number: %d, Hex: %x, Char: 
    %c|\n\n", "Hello", 42, 255, 'A');

    printf("Expected Output: |Mix: 42 Hello -42 (null) ff A 0xff 4294967295|\n");
    ft_printf("Your ft_printf Output: |Mix: %d %s %d %s %x %c %#x %u|\n\n", 42,
    "Hello", -42, NULL, 255, 'A', 255, 4294967295u);

    return 0;
}
*/
