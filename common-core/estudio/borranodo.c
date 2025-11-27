/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   borranodo.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 12:15:48 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/26 13:14:47 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	int				*content;
	struct s_list	*next;
} t_list;

void	borrado(t_list **lista)
{
	t_list	*temp;

	temp = *lista;
	while (*lista)
	{
		temp = temp->next;
		free((*lista)->content);
		free(*lista);
		*lista = temp;
	}
}

int	main(void)
{
	t_list	*nodo;
	t_list	*nodo1;
	t_list	*nodo2;

	nodo = malloc(sizeof(t_list));
	if (!nodo)
		return (1);
	nodo->content = malloc(sizeof(int));
	if (!nodo->content)
		return (1);
	*nodo->content = 42;
	nodo1 = malloc(sizeof(t_list));
	if (!nodo1)
		return (1);
	nodo1->content = malloc(sizeof(int));
	if (!nodo1->content)
		return (1);
	nodo2 = malloc(sizeof(t_list));
	if (!nodo2)
		return (1);
	nodo2->content = malloc(sizeof(int));
	if (!nodo2->content)
		return (1);
	nodo->next = nodo1;
	*nodo1->content = 43;
	nodo1->next = nodo2;
	*nodo2->content = 44;
	nodo2->next = NULL;
	//Borrado general
	borrado(&nodo);
	return (0);
}
