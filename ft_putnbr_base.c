/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhakimi- <mhakimi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:45:57 by mhakimi-          #+#    #+#             */
/*   Updated: 2024/11/18 19:55:44 by mhakimi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putnbr_base_extension(int n, char base, int *len, t_flags *flags)
{
	unsigned int	number;
	const char		*digits;

	digits = 0;
	if (base == 'x')
		digits = "0123456789abcdef";
	else
		digits = "0123456789ABCDEF";
	number = 0;
	if (n < 0)
		number = (unsigned int)(-n);
	else
		number = (unsigned)n;
	if (number >= 16)
		ft_putnbr_base_extension(number / 16, base, len, flags);
	ft_putchar(digits[number % 16], len);
}

void	ft_putnbr_base(int n, char base, int *len, t_flags *flags)
{
	if (flags->hash && base == 'x')
	{
		ft_putstr("0x", len);
		flags->hash = 0;
	}
	else if (flags->hash && base == 'X')
	{
		ft_putstr("0X", len);
		flags->hash = 0;
	}
	ft_putnbr_base_extension(n, base, len, flags);
}
