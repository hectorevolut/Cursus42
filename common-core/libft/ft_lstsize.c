/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/23 14:55:37 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/23 16:03:33 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst)
	{
		size ++;
		lst = lst->next;
	}
	return (size);
}
/*
int main(void)
{
    int     number;
    t_list  *node1;
	t_list	*node2;
    t_list	*list;
	
    number = 42;
	
    node1 = ft_lstnew(&number);
	list = node1;

	if (node1->content == list->content)
		printf("\nMi puntero lista apunta a node1 y por tanto 
		tengo el contenido de node1 en list\n");
	
	node2 = ft_lstnew(&number);
	ft_lstadd_front(&list, node2);
	
	printf("\nNodos: %d\n", ft_lstsize(list));
	
	free(node1); // al final de lst
	free(node2); // al principio
	
	//free(list->next); //node1 está al final 
	//free(list); //node2 está al principio
	
    return (0);   
}*/