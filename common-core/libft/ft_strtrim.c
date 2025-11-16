/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/16 14:12:22 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/16 16:27:18 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdio.h>

static int	in_set(char c, const char *set) {
	while (*set)
		if (c == *set++)
			return 1;
	return 0;
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*end;
	char	*trim;
	char	*result_trim;

	end = (char *)s1 + (ft_strlen(s1) - 1);
	while (*set)
	{
		while (in_set(*s1, set))
			s1 ++;
		while (in_set(*end, set))
			end --;
		set ++;
	}
	trim = malloc((end - s1 + 2) * sizeof(char));
	if (trim == NULL)
		return (NULL);
	result_trim = trim;
	while (s1 <= end)
	{
		*trim = *s1;
		trim ++;
		s1 ++;
	}
	*trim = '\0';
	return (result_trim);
}

int	main(void)
{
	char *s1 = "    Hola que tal ";
	char *trim = ft_strtrim(s1, "");
	printf("|%s|\n", trim);
	printf("%zu", ft_strlen(trim));
	return (0);
}

/*
 * s1: String que debe ser recortada.
 * set: Los caracteres a recortar de la string.
 * Devuelve la string recortada (creada)
 * Devuelve NULL si falla algo.
 */
