/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   addback.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 11:12:58 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/26 11:42:04 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	int				*content;
	struct s_list	*next;
} t_list;

void	addback(t_list **list, t_list *new)
{
	t_list *temp;

	if (!*list)
		*list = new;
	temp = *list;
	while (temp->next)
		temp = temp->next;
	temp->next = new;
	new->next = NULL;
}

int	main(void)
{
	t_list	*nodo;
	t_list	*nodo1;

	nodo = malloc(sizeof(t_list));
	if (!nodo)
		return(1);
	nodo->content = malloc(sizeof(int));
	if (!nodo->content)
		return(1);
	nodo->next = NULL;
	nodo1 = malloc(sizeof(t_list));
	if (!nodo1)
		return(1);
	nodo1->content = malloc(sizeof(int));
	if (!nodo1->content)
		return(1);
	nodo1->next = NULL;
	addback(&nodo, nodo1);
	free(nodo1->content);
	free(nodo1);
	free(nodo->content);
	free(nodo);
	return (0);
}
