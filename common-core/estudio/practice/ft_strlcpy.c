/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 10:43:49 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/15 11:16:25 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i ++;
	return i;
}

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;

	if (size == 0)
		return ft_strlen((char *) src);
	i = 0;
	while (src[i] && i < size - 1)
	{
		dest[i] = src[i];
		i ++;
	}
	dest[i] = '\0';
	return ft_strlen((char *) src);
}

int	main(void)
{
	const char *src = "Hola caracola";
	char		dest[14];
	size_t		size = 20;

	printf("%zu\n", ft_strlcpy(dest, src, size));
	printf("%s", dest);
	return (0);
}
