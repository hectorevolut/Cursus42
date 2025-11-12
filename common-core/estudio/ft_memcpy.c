/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:32:47 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/12 19:33:14 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Incluimos "libft.h" para mantener la declaración coherente dentro de la
   biblioteca y poder reutilizar esta función en otros módulos. */

void	*ft_memcpy(void *dest, const void *str, size_t n)
/* Copia 'n' bytes desde la dirección apuntada por 'str' hasta 'dest'.
   Devuelve el puntero original 'dest'. No gestiona solapamientos de memoria
   (para eso está ft_memmove). */
{
	unsigned char		*chardest;
	const unsigned char	*charstr;
	size_t				i;
	/* Se utilizan punteros a unsigned char para copiar memoria byte a byte.
	   'const' en la fuente indica que no modificamos los datos originales. */

	if (!dest && !str)
	/* Si ambos punteros son NULL, no hay nada que copiar ni donde copiarlo.
	   Evita comportamiento indefinido devolviendo NULL. */
		return (NULL);

	chardest = (unsigned char *)dest;
	charstr = (const unsigned char *)str;
	/* Convertimos los punteros genéricos (void *) a unsigned char *
	   para poder recorrer y copiar byte a byte. */

	i = 0;
	while (i < n)
	/* Bucle que recorre 'n' posiciones de memoria. */
	{
		chardest[i] = charstr[i];
		/* Copiamos el byte actual de la fuente a la posición equivalente en destino. */
		i++;
	}
	return (dest);
	/* Devolvemos el puntero original a la memoria destino, como hace la versión estándar. */
}

/*
-------------------------------------------------------------------------------
🧠 EXPLICACIÓN:
ft_memcpy copia un bloque de memoria de una dirección (src) a otra (dest).
Es una función básica de manipulación de memoria binaria.

✔ Parámetros:
- dest → puntero al destino donde se copian los datos.
- str  → puntero a la fuente de los datos.
- n    → número de bytes a copiar.

✔ Devuelve:
- El puntero 'dest' original.

⚠️ Nota:
- Si las áreas de memoria se solapan, el comportamiento es indefinido.
  (usa ft_memmove en ese caso).

Ejemplo visual:
char src[] = "Hola";
char dest[5];
ft_memcpy(dest, src, 5);

Resultado:
src  → ['H']['o']['l']['a']['\0']
dest → ['H']['o']['l']['a']['\0']

-------------------------------------------------------------------------------
💡 APRENDIZAJE:
- Manipulación directa de memoria.
- Diferencia entre punteros de lectura (const) y escritura.
- Copia byte a byte mediante indexación.
- Importancia de comprobar punteros nulos.
- Distinción entre memcpy (sin solapamiento) y memmove (segura con solapamiento).
-------------------------------------------------------------------------------
*/

