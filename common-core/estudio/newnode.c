/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   newnode.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/26 14:41:28 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/26 15:13:21 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
} t_list;

t_list	*newnode()
{
	t_list	*newnode;

	newnode = malloc(sizeof(t_list));
	if (!newnode)
		return (NULL);
	newnode->content = NULL;
	newnode->next = NULL;
	return (newnode);
}

void	modifynode(t_list **node, void *content)
{
	t_list	*temp;

	temp = *node;
	temp->content = content;
}

int	main(void)
{
	t_list *head;
	int	content = 42;

	head = newnode();
	modifynode(&head, &content);
	printf("%d", *(int *)head->content);
	return (0);
}
