/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:43:11 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/12 19:43:21 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Incluimos libft.h para la declaración de la función y consistencia del proyecto. */

char	*ft_strchr(const char *s, int c)
/* Busca la primera aparición del carácter 'c' dentro de la cadena 's'.
   Si se encuentra, devuelve un puntero a esa posición dentro de la cadena.
   Si no se encuentra, devuelve NULL. */
{
	while (*s)
		/* Iteramos por la cadena carácter a carácter hasta llegar al terminador '\0'. */
	{
		if (*s == (unsigned char)c)
			/* Si el carácter actual coincide con 'c', devolvemos la dirección
			   de esa posición dentro de la cadena. */
			return ((char *)s);
			/* Hacemos casting a (char *) porque 's' es un puntero a const char,
			   pero necesitamos devolver un puntero modificable. */

		s++;
		/* Avanzamos el puntero a la siguiente posición de la cadena. */
	}

	if ((unsigned char)c == '\0')
		/* Si se busca el carácter nulo ('\0'), la función debe devolver
		   un puntero al final de la cadena (después del último carácter). */
		return ((char *)s);

	return (NULL);
	/* Si no se encontró el carácter buscado, devolvemos NULL. */
}

/*
-------------------------------------------------------------------------------
🧠 EXPLICACIÓN:
ft_strchr busca un carácter dentro de una cadena y devuelve un puntero al primer
lugar donde aparece. Es una de las funciones base para análisis de texto y parsing.

✔ Parámetros:
- s → puntero a la cadena donde se busca.
- c → carácter a buscar (se pasa como int para permitir EOF o caracteres extendidos).

✔ Devuelve:
- Puntero al primer carácter encontrado en la cadena.
- NULL si no se encuentra.
- Si c == '\0', devuelve puntero al final de la cadena.

⚙️ Lógica:
1. Recorre la cadena carácter por carácter.
2. Si encuentra coincidencia → devuelve dirección.
3. Si no → continúa hasta llegar al final.
4. Si busca '\0' → devuelve puntero al terminador.
5. Si no hay coincidencias → NULL.

Ejemplo:
  s = "Hola Mundo"
  c = 'M' → devuelve puntero a "Mundo"
  c = '\0' → devuelve puntero al final de "Hola Mundo\0"

-------------------------------------------------------------------------------
💡 APRENDIZAJE:
- Entender que los punteros en C pueden moverse como iteradores.
- Saber por qué el retorno es (char *) y no (const char *).
- Comprender cómo se interpreta '\0' en memoria como carácter especial de fin.
- `ft_strchr` es la base para funciones como ft_strrchr o ft_strnstr.
-------------------------------------------------------------------------------
*/

