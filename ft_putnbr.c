/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhakimi- <mhakimi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 11:22:17 by mhakimi-          #+#    #+#             */
/*   Updated: 2024/11/18 17:11:08 by mhakimi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_putnbr_extension(int n, int *len, t_flags *flags)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648", len);
		return ;
	}
	if (n < 0)
	{
		ft_putchar('-', len);
		n = -n;
	}
	if (n > 9)
		ft_putnbr_extension(n / 10, len, flags);
	ft_putchar(n % 10 + '0', len);
}

void	ft_putnbr(int n, int *len, t_flags *flags)
{
	if (n >= 0 && flags->plus)
	{
		ft_putchar('+', len);
		flags->plus = 0;
	}
	else if (n >= 0 && flags->space)
	{
		ft_putchar(' ', len);
		flags->space = 0;
	}
	ft_putnbr_extension(n, len, flags);
}
