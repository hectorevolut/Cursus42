/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 08:59:20 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/27 15:01:20 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
} t_list;

t_list	*ft_lstnew(void	*content)
{
	t_list	*lstnew;

	lstnew = malloc(sizeof(t_list));
	if (!lstnew)
		return (NULL);
	lstnew->content = content;
	lstnew->next = NULL;
	return (lstnew);
}

size_t	ft_strlen(char *str)
{
	size_t	len;

	len = 0;
	while (str[len])
	{
		len ++;
	}
	return (len);
}

char	*ft_strdup(char *str)
{
	char	*strdup;
	char	*strtemp;
	char	*duptemp;
	size_t	len;

	len = ft_strlen(str);
	strdup = malloc((sizeof(char) * len) + 1);
	if (!strdup)
		return (NULL);
	strtemp = str;
	duptemp = strdup;
	while (*strtemp)
	{
		*duptemp = *strtemp;
		duptemp ++;
		strtemp ++;
	}
	*duptemp = '\0';
	return (strdup);
}

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*temp;

	if (!*lst)
		*lst = new;
	else
	{
		temp = *lst;
		while (temp->next)
		{
			temp = temp->next;
		}
		temp->next = new;
		new->next = NULL;
	}
}

void	ft_printlist(t_list	*lst)
{
	t_list	*temp;
	int	node;

	if (!lst)
		return ;
	temp = lst;
	node = 1;
	while (temp)
	{
		printf("Content %d: %s\n", node, (char *)temp->content);
		temp = temp->next;
		node ++;
	}
}

void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (!lst || !del)
		return;
	del(lst->content);
	free(lst);
}

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*current;
	t_list	*next;

	if (!lst || !*lst)
		return ;

	current = *lst;
	while (current)
	{
		next = current->next;
		del(current->content);
		free(current);
		current = next;
	}
	*lst = NULL;
}

void	ft_lstiter(t_list *lst, void (*f)(void *))
{
	t_list	*temp;

	if (!lst || !f)
		return ;
	temp = lst;
	while (temp)
		{
			f(temp->content);
			temp = temp->next;
		}
}

void	ft__print_toupper(char *str)
{
	char *temp;

	temp = str;
	while (*temp)
	{
		if (*temp >= 'a' && *temp <= 'z')
			*temp += 32;
		write(1, temp, 1);
	}
}

int	main(void)
{
	t_list	*nodo1;
	t_list	*nodo2;
	t_list	*nodo3;
	char	*str1 = ft_strdup("Hola");
	char	*str2 = ft_strdup("42");
	char	*str3 = ft_strdup("Malaga");

	nodo1 = ft_lstnew(str1);
	nodo2 = ft_lstnew(str2);
	nodo3 = ft_lstnew(str3);
	ft_lstadd_back(&nodo1, nodo2);
	ft_lstadd_back(&nodo1, nodo3);
	printf("Antes de eliminar el nodo3\n");
	ft_printlist(nodo1);
	nodo2->next = NULL;
	ft_lstdelone(nodo3, free);
	nodo3 = NULL;
	printf("Después de borrar el nodo 3\n");
	ft_printlist(nodo1);
	printf("Aplicamos función con lstiter...");
	ft_lstiter(node1, ft_print_toupper);
	ft_lstclear(&nodo1, free);
	if (!nodo1)
		printf("Lista liberada.\n");
	return (0);
}
