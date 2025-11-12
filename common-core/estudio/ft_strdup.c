/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:55:04 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/12 19:55:17 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Incluimos libft.h para acceder a malloc y mantener coherencia con la biblioteca. */

static size_t	strlen(const char *s)
/* Implementación interna de strlen, usada solo dentro de este archivo.
   Calcula la longitud de la cadena 's' sin contar el carácter nulo '\0'. */
{
	size_t	length;

	length = 0;
	while (s[length])
		/* Avanza hasta encontrar el carácter nulo final. */
		length++;
	return (length);
}

/* ----------------------------------------------------------------------------
   ft_strdup: duplica una cadena de caracteres en una nueva zona de memoria.
   ---------------------------------------------------------------------------- */
char	*ft_strdup(const char *s)
{
	char	*ptr;
	char	*aux;
	/* ptr → apuntará a la nueva cadena duplicada.
	   aux → guarda el puntero original de ptr para poder devolverlo al final. */

	ptr = malloc(strlen(s) + 1);
	/* Reservamos memoria dinámica para la nueva cadena:
	   longitud de 's' + 1 para el carácter nulo final. */

	if (!ptr)
		/* Si malloc devuelve NULL, significa que no se pudo asignar memoria. */
		return (NULL);

	aux = ptr;
	/* Guardamos el puntero original antes de avanzar 'ptr' durante la copia. */

	while (*s)
		/* Copiamos carácter a carácter desde 's' a la nueva cadena. */
	{
		*ptr = *s;
		ptr++;
		s++;
	}

	*ptr = '\0';
	/* Terminamos la nueva cadena con el carácter nulo '\0'. */

	return (aux);
	/* Devolvemos el puntero original a la cadena duplicada. */
}

/*
-------------------------------------------------------------------------------
🧠 EXPLICACIÓN:
ft_strdup crea una copia idéntica de una cadena de texto en una nueva
posición de memoria (heap). Es equivalente a la función strdup estándar de C.

✔ Parámetros:
- s → puntero a la cadena que queremos duplicar.

✔ Devuelve:
- Un nuevo puntero a la cadena duplicada.
- NULL si malloc falla (sin memoria disponible).

⚙️ Lógica:
1. Calcula la longitud de 's' con strlen.
2. Reserva memoria con malloc para la nueva cadena (+1 por '\0').
3. Copia carácter a carácter hasta llegar al final.
4. Añade el '\0' final.
5. Devuelve el puntero original (aux).

Ejemplo:
  s = "Evolut"
  → malloc(7) → copia "Evolut" → devuelve puntero a nueva cadena "Evolut".

-------------------------------------------------------------------------------
💡 APRENDIZAJE:
- strdup combina malloc + strcpy.
- Siempre reserva nueva memoria: modificar el duplicado no afecta al original.
- Guardar el puntero original (aux) evita perder la referencia tras iterar ptr.
- Es una base perfecta para entender funciones que manipulan strings dinámicos.
-------------------------------------------------------------------------------
*/

