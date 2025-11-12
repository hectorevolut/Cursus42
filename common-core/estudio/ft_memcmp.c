/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:48:42 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/12 19:49:08 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Incluimos libft.h para mantener consistencia y declarar la función. */

int	ft_memcmp(const void *s1, const void *s2, size_t n)
/* Compara los primeros 'n' bytes de dos bloques de memoria (s1 y s2).
   Devuelve la diferencia entre el primer par de bytes distintos,
   o 0 si los bloques son idénticos en los primeros 'n' bytes. */
{
	const unsigned char	*chars1;
	const unsigned char	*chars2;
	size_t				i;
	/* Usamos unsigned char para comparar bytes individuales sin signo.
	   Esto evita resultados negativos inesperados en comparaciones. */

	chars1 = (const unsigned char *)s1;
	chars2 = (const unsigned char *)s2;
	/* Convertimos ambos punteros a unsigned char para acceder byte a byte. */

	i = 0;
	while (i < n)
		/* Recorremos los 'n' bytes de ambos bloques simultáneamente. */
	{
		if (chars1[i] != chars2[i])
			/* Si los bytes en la posición i son diferentes,
			   devolvemos la diferencia (igual que en strcmp). */
			return (chars1[i] - chars2[i]);

		i++;
	}
	return (0);
	/* Si terminamos el bucle sin diferencias, los bloques son iguales. */
}

/*
-------------------------------------------------------------------------------
🧠 EXPLICACIÓN:
ft_memcmp compara dos bloques de memoria sin detenerse en '\0',
a diferencia de funciones como strcmp o strncmp que trabajan con cadenas.

✔ Parámetros:
- s1 → primer bloque de memoria.
- s2 → segundo bloque de memoria.
- n → número de bytes a comparar.

✔ Devuelve:
- 0 → si los bloques son iguales en los primeros 'n' bytes.
- Valor positivo → si el primer byte distinto en s1 > s2.
- Valor negativo → si el primer byte distinto en s1 < s2.

⚙️ Lógica:
1. Recorre byte a byte ambos bloques.
2. Si encuentra una diferencia, devuelve la resta de esos bytes.
3. Si no encuentra ninguna, devuelve 0.

Ejemplo visual:
  s1 = [0x41, 0x42, 0x43]
  s2 = [0x41, 0x42, 0x44]
  n = 3
  → Diferencia en el byte 2: 0x43 - 0x44 = -1

  Resultado: -1 → s1 < s2

-------------------------------------------------------------------------------
💡 APRENDIZAJE:
- ft_memcmp trabaja con memoria binaria pura, no con texto.
- Usar unsigned char evita errores por interpretación de signo.
- Devuelve la misma lógica de comparación que strcmp, pero sin depender de '\0'.
- Base conceptual para comparar estructuras, buffers o datos binarios.
-------------------------------------------------------------------------------
*/

