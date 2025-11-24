/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 16:08:06 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/24 09:10:18 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

t_list	*ft_lstlast(t_list *lst)
{
	t_list	*temp;

	if (!lst)
		return (NULL);
	while (lst)
	{
		temp = lst;
		lst = lst->next;
	}
	return (temp);
}
/*
int	main(void)
{
	int		content;
	t_list	*node1;
	t_list	*node2;
	t_list	*list;
	t_list	*lastnode;

	content = 42;
	node1 = ft_lstnew(&content);
	node2 = ft_lstnew(&content);
	list = node2;
	ft_lstadd_front(&list, node1);
	lastnode = ft_lstlast(list);
	printf("La dirección de memoria de list es: %p\n", list);
	printf("La dirección de memoria de node1 es: %p\n", node1);
	printf("La dirección de memoria de node2 es: %p\n", node2);
	printf("La dirección de memoria de lastnode es: %p\n", lastnode);
	return (0);
}
*/