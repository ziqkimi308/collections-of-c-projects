/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhakimi- <mhakimi-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:45:57 by mhakimi-          #+#    #+#             */
/*   Updated: 2024/11/20 08:52:24 by mhakimi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_base_extension(unsigned int nb, char base, int *len)
{
	const char		*digits;

	digits = 0;
	if (base == 'x')
		digits = "0123456789abcdef";
	else
		digits = "0123456789ABCDEF";
	if (nb >= 16)
		ft_putnbr_base_extension(nb / 16, base, len);
	ft_putchar(digits[nb % 16], len);
}

void	ft_putnbr_base(int n, char base, int *len, t_flags *flags)
{
	if (flags->hash && base == 'x')
	{
		if (n != 0)
		{
			ft_putstr("0x", len);
			flags->hash = 0;
		}
	}
	else if (flags->hash && base == 'X')
	{
		if (n != 0)
		{
			ft_putstr("0X", len);
			flags->hash = 0;
		}
	}
	ft_putnbr_base_extension(n, base, len);
}
