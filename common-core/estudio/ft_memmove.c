/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:34:37 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/12 19:34:48 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Incluimos "libft.h" para mantener coherencia en la definición y
   permitir su uso desde otros módulos de la librería. */

void	*ft_memmove(void *dest, const void *src, size_t n)
/* Copia 'n' bytes de 'src' a 'dest', incluso si las zonas de memoria se solapan.
   A diferencia de memcpy, garantiza un comportamiento definido en ese caso. */
{
	unsigned char		*chardest;
	const unsigned char	*charsrc;
	size_t				i;
	/* Se usan punteros a unsigned char para tratar la memoria byte a byte. */

	if (dest == src || n == 0)
	/* Si origen y destino son el mismo puntero o no hay bytes que copiar,
	   no hay trabajo que hacer. Devolvemos directamente 'dest'. */
		return (dest);

	chardest = (unsigned char *)dest;
	charsrc = (const unsigned char *)src;
	/* Convertimos los punteros genéricos (void *) a unsigned char *
	   para acceder a la memoria de forma indexada y precisa. */

	if (chardest > charsrc && chardest < charsrc + n)
	/* Caso 1: Las áreas de memoria se solapan y 'dest' está dentro del rango de 'src'.
	   Si copiáramos de adelante hacia atrás, sobreescribiríamos datos aún no copiados.
	   Por tanto, copiamos **de atrás hacia adelante**. */
	{
		i = n;
		while (i > 0)
		{
			i--;
			chardest[i] = charsrc[i];
			/* Copiamos cada byte desde el final hacia el inicio. */
		}
	}
	else
	/* Caso 2: No hay solapamiento o 'dest' está antes de 'src'.
	   Podemos copiar de forma directa, de inicio a fin. */
	{
		while (n--)
			*chardest++ = *charsrc++;
			/* Se copian los bytes secuencialmente y se incrementan ambos punteros. */
	}
	return (dest);
	/* Devolvemos el puntero original 'dest', como hace la función estándar. */
}

/*
-------------------------------------------------------------------------------
🧠 EXPLICACIÓN:
ft_memmove copia bloques de memoria incluso cuando se solapan,
asegurando que los datos originales no se corrompan durante el proceso.

✔ Parámetros:
- dest → puntero al área de destino.
- src  → puntero al área de origen.
- n    → número de bytes a copiar.

✔ Devuelve:
- El puntero 'dest' original.

⚙️ Lógica interna:
- Si dest y src se solapan y dest está **después** de src → copia hacia atrás.
- En cualquier otro caso → copia hacia adelante.

Ejemplo visual (solapamiento):
src:  [H][O][L][A][_][_]
dest:    ↑ empieza aquí (1 byte después)
Resultado correcto: “OLAA_” (no corrupto).

-------------------------------------------------------------------------------
💡 APRENDIZAJE:
- Diferencia entre ft_memcpy y ft_memmove.
- Detección de solapamiento de zonas de memoria.
- Copia segura hacia adelante o hacia atrás según posición relativa.
- Uso inteligente del orden de iteración para preservar datos.
- Manipulación con punteros incrementales y decrementales.
-------------------------------------------------------------------------------
*/

