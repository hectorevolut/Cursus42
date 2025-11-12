/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 21:50:57 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/12 22:13:34 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char	*substr;
	size_t	i;

	s_len = ft_strlen(s);
	if (len == 0 || len > s_len)
		return (NULL);
	substr = malloc(len * sizeof(char));
	if (!substr)
		return (NULL);
	i = 0;
	while (s[i])
	{
		substr[i] = s[i + start];
		i ++;
	}
	substr[i] = '\0';
	return (substr);
}

int	main(void)
{
	char	str[] = "Hola Héctor";;
	char *substr = ft_substr(str, 5, 6);

	printf("%s", substr);
	return (0);
}
