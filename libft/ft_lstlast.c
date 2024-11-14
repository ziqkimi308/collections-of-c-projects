/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhakimi- <mhakimi-@student.42kl.edu.my>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/09 21:50:17 by mhakimi-          #+#    #+#             */
/*   Updated: 2024/11/09 21:50:27 by mhakimi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* It takes pointer to first node in the list (*lst)
   and return the last node of the list (*lst)
*/

#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}
