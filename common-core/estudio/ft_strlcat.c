/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:37:59 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/12 19:38:28 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Incluimos "libft.h" para que la función esté declarada correctamente
   dentro de la biblioteca y disponible para el resto del proyecto. */

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
/* Concatena la cadena 'src' al final de 'dst' sin sobrepasar el tamaño total
   del buffer 'dstsize'. Siempre añade '\0' al final si hay espacio.
   Devuelve la longitud total que habría tenido la cadena final
   si hubiese habido espacio suficiente. */
{
	size_t	len_dst;
	size_t	len_src;
	size_t	i;

	len_dst = ft_strlen(dst);
	len_src = ft_strlen(src);
	/* Calculamos la longitud de ambas cadenas para saber
	   hasta dónde podemos copiar sin sobrepasar dstsize. */

	if (dstsize <= len_dst)
		/* Si el tamaño total del buffer es menor o igual que la longitud de 'dst',
		   no podemos concatenar nada. Se devuelve dstsize + len_src,
		   que indica la longitud total que habría resultado si hubiera espacio. */
		return (dstsize + len_src);

	i = 0;
	while (src[i] && (len_dst + i) < (dstsize - 1))
		/* Mientras haya caracteres en src y no se supere el tamaño máximo permitido,
		   copiamos uno a uno al final de 'dst'. */
	{
		dst[len_dst + i] = src[i];
		i++;
	}

	dst[len_dst + i] = '\0';
	/* Aseguramos que la cadena resultante quede correctamente terminada con '\0'. */

	return (len_dst + len_src);
	/* La función devuelve la longitud total que tendría la cadena concatenada
	   si no hubiera límite de espacio (es decir, len_dst + len_src). */
}

/*
-------------------------------------------------------------------------------
🧠 EXPLICACIÓN:
ft_strlcat concatena de forma segura dos cadenas en un buffer limitado.
Evita desbordamientos y garantiza que la cadena final esté terminada en '\0'
siempre que haya espacio disponible.

✔ Parámetros:
- dst → cadena destino (ya contiene texto inicial).
- src → cadena fuente que queremos añadir al final.
- dstsize → tamaño total del buffer destino (no solo el espacio libre).

✔ Devuelve:
- La longitud total que habría tenido la cadena concatenada completa
  (len_dst + len_src), aunque no haya cabido entera.

⚙️ Lógica:
- Si no hay espacio (dstsize <= len_dst) → no se copia nada.
- Si hay espacio → copia hasta llenar el buffer dejando espacio para '\0'.

Ejemplo visual:
dst = "Hola", src = " Mundo", dstsize = 10
Resultado: dst = "Hola Mund"
Devuelve: 11 (4 + 7), que es la longitud total sin truncar.

-------------------------------------------------------------------------------
💡 APRENDIZAJE:
- Control preciso del tamaño de buffers y prevención de overflow.
- Gestión simultánea de dos longitudes: la actual (len_dst) y la posible (len_src).
- Garantizar la terminación nula ('\0') en todas las situaciones.
- Diferencia entre longitud “real” (lo que se copió) y “potencial” (lo que cabría).
-------------------------------------------------------------------------------
*/

