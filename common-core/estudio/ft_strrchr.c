/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:45:05 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/12 19:45:18 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Incluimos libft.h para la declaración y consistencia del proyecto. */

char	*ft_strrchr(const char *s, int c)
/* Busca la última aparición del carácter 'c' dentro de la cadena 's'.
   Si lo encuentra, devuelve un puntero a esa posición en la cadena.
   Si no se encuentra, devuelve NULL. */
{
	char	*ptr;

	ptr = NULL;
	/* Inicializamos ptr en NULL para almacenar la dirección
	   de la última coincidencia encontrada. */

	while (*s)
		/* Recorremos toda la cadena carácter por carácter
		   hasta llegar al terminador nulo '\0'. */
	{
		if (*s == (unsigned char)c)
			/* Si el carácter actual coincide con 'c', actualizamos ptr
			   para que apunte a esta posición. */
			ptr = (char *)s;
			/* No salimos del bucle, porque queremos la **última** coincidencia.
			   Por eso seguimos avanzando por la cadena. */

		s++;
		/* Avanzamos al siguiente carácter. */
	}

	if (ptr != NULL)
		/* Si encontramos al menos una coincidencia, devolvemos
		   la dirección guardada en ptr (la última aparición). */
		return (ptr);

	if ((unsigned char)c == '\0')
		/* Caso especial: si buscamos el carácter nulo '\0',
		   devolvemos la dirección del final de la cadena. */
		return ((char *)s);

	return (NULL);
	/* Si no se encontró el carácter en ningún punto, devolvemos NULL. */
}

/*
-------------------------------------------------------------------------------
🧠 EXPLICACIÓN:
ft_strrchr realiza la misma búsqueda que ft_strchr, pero devuelve la **última**
ocurrencia del carácter dentro de la cadena.

✔ Parámetros:
- s → puntero a la cadena donde se busca.
- c → carácter a buscar (pasado como int para compatibilidad).

✔ Devuelve:
- Puntero a la última aparición de 'c' en la cadena.
- NULL si no aparece.
- Si c == '\0', devuelve un puntero al final de la cadena.

⚙️ Lógica:
1. Se recorre toda la cadena de principio a fin.
2. Cada vez que aparece el carácter buscado, se actualiza `ptr`.
3. Al final del recorrido, `ptr` apunta a la última coincidencia (si la hubo).
4. Si se busca '\0', se devuelve el puntero al terminador final.
5. Si no hay coincidencias, se devuelve NULL.

Ejemplo:
  s = "Hola Mundo"
  c = 'o' → devuelve puntero a "o" en "Mundo"
  c = 'x' → devuelve NULL
  c = '\0' → devuelve puntero al final de la cadena

-------------------------------------------------------------------------------
💡 APRENDIZAJE:
- Diferencia clave con ft_strchr: en lugar de devolver la **primera**, devuelve la **última**.
- Uso de un puntero auxiliar (ptr) para guardar la última posición encontrada.
- Ejemplo perfecto de cómo actualizar un puntero durante una iteración.
- Reforzar la comprensión del carácter nulo '\0' y su posición en memoria.
-------------------------------------------------------------------------------
*/

