/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   listas.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 08:43:56 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/26 09:22:46 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>
#include <stdlib.h>

typedef struct	s_list
{
	int				*valor;
	struct s_list	*next;
} t_list;

int	main(void)
{
	t_list	*nodo;
	t_list	*nextnodo;

	nodo = malloc(sizeof(t_list));
	if (!nodo)
		return (1);
	nodo->valor = malloc (sizeof(int));
	if (!nodo->valor)
		return (1);
	nextnodo = malloc(sizeof(t_list));
	if (!nextnodo)
		return (1);
	nextnodo->valor = malloc (sizeof(int));
	if (!nextnodo->valor)
		return (1);
	*nodo->valor = 42;
	nodo->next = nextnodo;
	*nextnodo->valor = 41;
	nextnodo->next = NULL;
	printf("%d\n%d\n", *nodo->valor, *nextnodo->valor);
	free(nextnodo->valor);
	free(nextnodo);
	free(nodo->valor);
	free(nodo);
	return (0);
}
