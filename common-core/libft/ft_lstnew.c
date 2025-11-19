/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/19 16:21:35 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/19 16:36:03 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

t_list	*ft_lstnew(void *content)
{
	t_list	*newNode;

	newNode = malloc(sizeof(t_list));
	if (!newNode)
		return (NULL);
	newNode->content = content;
	newNode->next = NULL;
	return (newNode);
}