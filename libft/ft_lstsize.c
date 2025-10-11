/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhakimi- <mhakimi-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:10:57 by mhakimi-          #+#    #+#             */
/*   Updated: 2024/11/10 15:07:57 by mhakimi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* It takes the first node in the list (t_list *lst)
   and returns size of the whole list (int t_list)
*/

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	count;

	count = 0;
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}
