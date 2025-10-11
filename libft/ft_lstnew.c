/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mhakimi- <mhakimi-@student.42kl.edu.m      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 15:29:47 by mhakimi-          #+#    #+#             */
/*   Updated: 2024/11/10 09:59:56 by mhakimi-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* 
 * (1) Create new node named "new".
 * (2) Allocate memory size of struct list.
 * (3) Guard malloc.
 * (4) Assign value of content (from parameter) to new node's
 * (member of t_list struct).
 * (5) Assign NULL to the new node's next (member of t_list
 * struct).
 * (6) Return "new".
*/

#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}
