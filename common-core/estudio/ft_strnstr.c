/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:50:01 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/12 19:50:42 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Incluimos libft.h para tener acceso a ft_strlen y mantener coherencia. */

char	*ft_strnstr(const char *big, const char *little, size_t len)
/* Busca la primera aparición de la subcadena 'little' dentro de 'big',
   pero sin sobrepasar un máximo de 'len' caracteres en 'big'.
   Si se encuentra, devuelve un puntero a la posición donde empieza.
   Si no se encuentra, devuelve NULL. */
{
	size_t	i;
	size_t	j;
	size_t	needle_len;
	/* i → recorre 'big'.
	   j → recorre 'little' dentro del punto de coincidencia.
	   needle_len → almacena la longitud total de 'little' para saber
	   cuándo se ha encontrado la subcadena completa. */

	if (little[0] == '\0')
		/* Si 'little' es una cadena vacía, por convención
		   se devuelve 'big' directamente. */
		return ((char *)big);

	needle_len = ft_strlen(little);
	/* Calculamos la longitud de la subcadena que estamos buscando. */

	i = 0;
	while (big[i] && i < len)
		/* Recorremos 'big' mientras no llegue al final ni supere el límite 'len'. */
	{
		j = 0;
		while (i + j < len && big[i + j] == little[j])
			/* Mientras haya coincidencia carácter a carácter y no superemos 'len'... */
		{
			j++;
			if (j == needle_len)
				/* Si hemos avanzado toda la longitud de 'little'
				   → encontramos la subcadena completa. */
				return ((char *)(big + i));
				/* Devolvemos puntero al inicio de la coincidencia. */
		}
		i++;
	}
	return (NULL);
	/* Si no se encuentra la subcadena dentro del límite, devolvemos NULL. */
}

/*
-------------------------------------------------------------------------------
🧠 EXPLICACIÓN:
ft_strnstr busca una subcadena dentro de otra, limitando la búsqueda a un número
máximo de caracteres (len). Es una versión “segura” de strstr que evita leer
más allá del límite indicado.

✔ Parámetros:
- big → cadena donde buscar.
- little → subcadena que se quiere encontrar.
- len → número máximo de caracteres de 'big' a examinar.

✔ Devuelve:
- Puntero al inicio de la primera coincidencia de 'little' dentro de 'big'.
- NULL si no se encuentra en los primeros 'len' caracteres.
- Si 'little' está vacía, devuelve 'big'.

⚙️ Lógica:
1. Si 'little' está vacía → devolvemos 'big'.
2. Recorremos 'big' con un índice i.
3. En cada posición, comparamos los caracteres con 'little' usando j.
4. Si j alcanza la longitud total de 'little', hay coincidencia.
5. Si se llega al final o se supera 'len', devolvemos NULL.

Ejemplo:
  big = "Hola mundo", little = "mun", len = 8
  → Solo se buscan los primeros 8 caracteres ("Hola mun")
  → Encuentra "mun" en la posición 5 → devuelve puntero a 'm'.

-------------------------------------------------------------------------------
💡 APRENDIZAJE:
- ft_strnstr combina punteros, iteración doble y control de longitud.
- Es una versión protegida de búsqueda de subcadenas.
- Dominar esta función te prepara para parsing de strings con límites.
- Saber cuándo retornar directamente la cadena original o NULL
  es una clave de diseño segura en C.
-------------------------------------------------------------------------------
*/

