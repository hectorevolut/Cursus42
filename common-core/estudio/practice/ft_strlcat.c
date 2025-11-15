/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 12:29:11 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/15 13:09:48 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlen(const char *str)
{
	size_t i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
    size_t	len_dest;
    size_t	len_src;
    size_t	i;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	i = 0;
	// Si no hay espacio para concatenar, devuelve el tamaño que habría sido necesario
	if (len_dest >= size)
		return size + len_src;
	// Copiar caracteres desde src al final de dest, sin sobrepasar size - 1
	while (src[i] && (len_dest + i < size - 1))
	{
		dest[len_dest + i] = src[i];
		i++;
	}
	// Agregar terminador nulo
	dest[len_dest + i] = '\0';
	return len_dest + len_src;
}

int	main(void)
{
	char buf[10] = "Hola";
	size_t r = ft_strlcat(buf, " mundo", 10);

	printf("%zu\n", r);
	return (0);
}
