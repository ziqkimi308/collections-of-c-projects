/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhakimi- <mhakimi-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/17 22:04:27 by mhakimi-          #+#    #+#             */
/*   Updated: 2024/11/20 10:49:09 by mhakimi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>

typedef struct s_flags
{
	int	plus;
	int	space;
	int	hash;
}	t_flags;

int		ft_printf(const char *str, ...);
void	ft_putchar(char c, int *len);
void	ft_putnbr(int n, int *len, t_flags *flags);
void	ft_putnbr_unsigned(unsigned int n, int *len);
void	ft_putstr(char *str, int *len);
void	ft_putnbr_base(int n, char base, int *len, t_flags *flags);
void	ft_putaddr(void *ptr, int *len);

#endif