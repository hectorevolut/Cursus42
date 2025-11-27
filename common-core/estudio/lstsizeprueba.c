/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lstsizeprueba.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 10:55:32 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/26 11:08:50 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	int				*content;
	struct s_list	*next;
} t_list;

int	lstsizeprueba(t_list *head)
{
	t_list	*temp;
	int		size;

	if (!head)
		return (0);
	size = 0;
	temp = head;
	while (temp)
	{
		size ++;
		temp = temp->next;
	}
	return size;
}

int	main(void)
{
	t_list	*nodo;
	t_list	*nextnodo;
	int		size;

	nodo = malloc(sizeof(t_list));
	if (!nodo)
		return (1);
	nodo->content = malloc (sizeof(int));
	if (!nodo->content)
		return (1);
	nextnodo = malloc(sizeof(t_list));
	if (!nextnodo)
		return (1);
	nextnodo->content = malloc (sizeof(int));
	if (!nextnodo->content)
		return (1);
	*nodo->content = 42;
	nodo->next = nextnodo;
	*nextnodo->content = 41;
	nextnodo->next = NULL;
	size = lstsizeprueba(nodo);
	printf("Tamaño de la lista: %d\n", size);

	free(nextnodo->content);
	free(nextnodo);
	free(nodo->content);
	free(nodo);
	return (0);
}
