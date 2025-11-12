/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:31:48 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/12 19:32:02 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Incluimos "libft.h" para mantener la coherencia de la declaración y
   permitir que la función sea usada en otros módulos del proyecto. */

void	ft_bzero(void *s, size_t n)
/* ft_bzero pone a cero los primeros 'n' bytes del área de memoria apuntada
   por 's'. No devuelve nada (tipo void). */
{
	unsigned char	*chars;
	/* Definimos un puntero a unsigned char para manipular la memoria byte a byte.
	   Trabajar con unsigned evita problemas de signo y es la unidad básica de memoria. */

	chars = (unsigned char *)s;
	/* Convertimos el puntero genérico 'void *' a 'unsigned char *' para poder
	   acceder y modificar la memoria en incrementos de 1 byte. */

	while (n--)
	/* Mientras queden bytes por escribir (n > 0), el bucle sigue ejecutándose.
	   El operador n-- reduce 'n' en cada iteración hasta llegar a 0. */
	{
		*chars = 0;
		/* Escribimos un byte con valor 0 en la posición actual de memoria. */
		chars++;
		/* Avanzamos al siguiente byte. */
	}
}

/*
-------------------------------------------------------------------------------
🧠 EXPLICACIÓN:
ft_bzero inicializa un bloque de memoria con ceros, lo que equivale a dejarlo vacío.
Es una función fundamental para limpiar memoria antes de su uso.

✔ Parámetros:
- s → puntero al área de memoria que se va a limpiar.
- n → número de bytes a establecer en 0.

✔ No devuelve valor:
- Modifica directamente la memoria apuntada por 's'.

Ejemplo visual:
char buffer[5];
ft_bzero(buffer, 5);

buffer en memoria:
['\0']['\0']['\0']['\0']['\0']

-------------------------------------------------------------------------------
💡 APRENDIZAJE:
- Relación directa con ft_memset (es básicamente memset con valor 0).
- Trabajo con punteros genéricos (void *) y cast a unsigned char *.
- Uso del operador post-decremento (n--) para control de bucle descendente.
- Concepto de inicialización de memoria antes de usarla.
-------------------------------------------------------------------------------
*/

