/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhakimi- <mhakimi-@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/06 11:20:25 by mhakimi-          #+#    #+#             */
/*   Updated: 2024/11/08 12:06:54 by ziqkimi308       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t size)
{
	void				*ptr;
	size_t				i;
	size_t				total_size;
	unsigned char		*clone;

	if (nelem == 0 || size == 0)
	{
		ptr = malloc(1);
		return (ptr);
	}
	total_size = nelem * size;
	if (total_size / nelem != size)
		return (NULL);
	ptr = malloc(total_size);
	if (ptr == NULL)
		return (NULL);
	i = 0;
	clone = (unsigned char *)ptr;
	while (i < (nelem * size))
		clone[i++] = 0;
	return (ptr);
}
