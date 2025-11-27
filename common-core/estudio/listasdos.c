/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listasdos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 09:24:47 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/26 10:49:00 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	int			*content;
	struct s_list	*next;
} t_list;

void	print_list(t_list *head)
{
	t_list	*temp;

	if (!head)
		return ;
	temp = head;
	while (temp)
		{
			printf("%d\n", *temp->content);
			temp = temp->next;
		}
}

int	main(void)
{
	t_list	*nodo;
	t_list	*nextnodo;

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
	print_list(nodo);
	free(nextnodo->content);
	free(nextnodo);
	free(nodo->content);
	free(nodo);
	return (0);
}
