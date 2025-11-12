/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:36:33 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/12 19:36:52 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Incluimos "libft.h" para mantener la declaración coherente dentro del proyecto
   y permitir que la función sea reutilizada en otros módulos. */

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
/* Copia hasta 'dstsize - 1' caracteres desde la cadena 'src' a 'dst',
   añadiendo un '\0' al final. Devuelve la longitud total de 'src'. */
{
	size_t	srcsize;
	size_t	i;
	/* srcsize almacenará la longitud completa de 'src' (sin contar el '\0').
	   i se usará como índice para recorrer los caracteres. */

	srcsize = ft_strlen(src);
	/* Obtenemos la longitud de la cadena fuente. Esta será el valor de retorno
	   de la función, aunque no necesariamente el número de caracteres copiados. */

	if (dstsize == 0)
		/* Si el tamaño del destino es 0, no se puede copiar nada ni siquiera el '\0'. */
		return (srcsize);

	if (dstsize > 0)
	{
		i = 0;
		while (i < dstsize - 1 && src[i])
			/* Copiamos carácter por carácter desde 'src' hasta 'dst',
			   siempre dejando un espacio libre para el terminador '\0'. */
		{
			dst[i] = src[i];
			i++;
		}
		dst[i] = '\0';
		/* Aseguramos que la cadena destino esté terminada en nulo. */
	}
	return (srcsize);
	/* La función devuelve la longitud total de la cadena fuente,
	   no la cantidad de caracteres copiados. */
}

/*
-------------------------------------------------------------------------------
🧠 EXPLICACIÓN:
ft_strlcpy copia una cadena de forma segura, evitando desbordamientos.
Siempre garantiza que la cadena destino quede terminada en '\0'
si el tamaño del buffer lo permite.

✔ Parámetros:
- dst → buffer destino donde se copiará la cadena.
- src → cadena fuente que queremos copiar.
- dstsize → tamaño total del buffer destino.

✔ Devuelve:
- La longitud completa de 'src' (no el número de caracteres copiados).

⚙️ Lógica:
- Si dstsize == 0 → no se copia nada, solo se devuelve ft_strlen(src).
- Si dstsize > 0 → copia hasta dstsize - 1 caracteres y añade '\0' final.

Ejemplo visual:
src: "Hola"
dst: buffer de tamaño 3 → ['H']['o']['\0']
ft_strlcpy devuelve 4 (la longitud total de "Hola").

-------------------------------------------------------------------------------
💡 APRENDIZAJE:
- Diferencia entre el tamaño del buffer (dstsize) y el número de caracteres copiados.
- Uso de ft_strlen para obtener la longitud real de la fuente.
- Control de terminación nula ('\0') para evitar cadenas sin cierre.
- Importancia de proteger la escritura en memoria (evita buffer overflow).
-------------------------------------------------------------------------------
*/

