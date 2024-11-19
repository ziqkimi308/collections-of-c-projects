/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putaddr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhakimi- <mhakimi-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/18 12:13:36 by mhakimi-          #+#    #+#             */
/*   Updated: 2024/11/18 16:57:52 by mhakimi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	ft_recursive_putaddr(unsigned long addr, int *len)
{
	const char	*digits;

	digits = "0123456789abcdef";
	if (addr >= 16)
		ft_recursive_putaddr(addr / 16, len);
	ft_putchar(digits[addr % 16], len);
}

void	ft_putaddr(void *ptr, int *len)
{
	unsigned long	addr;

	addr = (unsigned long)ptr;
	ft_putstr("0x", len);
	ft_recursive_putaddr(addr, len);
}
