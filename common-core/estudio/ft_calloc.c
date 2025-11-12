/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:53:40 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/12 19:53:50 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft.h"
/* Incluimos <stdint.h> para tener disponible SIZE_MAX,
   el valor máximo representable por size_t.
   Incluimos libft.h para usar ft_bzero y mantener coherencia con la biblioteca. */

void	*ft_calloc(size_t count, size_t size)
/* Reserva memoria dinámica para un array de 'count' elementos de tamaño 'size',
   e inicializa todos los bytes a cero.
   Devuelve un puntero a la memoria asignada o NULL si falla. */
{
	void	*ptr;
	size_t	total_size;
	/* ptr → puntero genérico a la memoria reservada.
	   total_size → número total de bytes a reservar (count * size). */

	if (size != 0 && count > SIZE_MAX / size)
		/* Evita desbordamiento (overflow) en la multiplicación count * size.
		   Si count * size > SIZE_MAX, la operación sobrepasa el límite
		   y malloc podría reservar menos memoria de la esperada, causando errores. */
		return (NULL);

	total_size = count * size;
	/* Calculamos el tamaño total de la memoria a reservar. */

	ptr = malloc(total_size);
	/* Solicitamos al sistema operativo la memoria dinámica. */

	if (!ptr)
		/* Si malloc falla (devuelve NULL), propagamos el error devolviendo NULL. */
		return (NULL);

	ft_bzero(ptr, total_size);
	/* Inicializamos toda la memoria asignada a cero
	   (igual que lo haría la calloc estándar). */

	return (ptr);
	/* Devolvemos el puntero a la memoria inicializada. */
}

/*
-------------------------------------------------------------------------------
🧠 EXPLICACIÓN:
ft_calloc combina la funcionalidad de malloc + memset (o ft_bzero) para crear
una zona de memoria inicializada completamente a cero, lista para usarse.

✔ Parámetros:
- count → número de elementos a reservar.
- size → tamaño de cada elemento en bytes.

✔ Devuelve:
- Puntero a la memoria asignada e inicializada en 0.
- NULL → si ocurre overflow o malloc falla.

⚙️ Lógica:
1. Verifica que la multiplicación (count * size) no cause overflow.
2. Calcula el tamaño total.
3. Llama a malloc para reservar memoria.
4. Si malloc falla → devuelve NULL.
5. Si no falla → limpia la memoria con ft_bzero.

Ejemplo:
  ft_calloc(5, sizeof(int))
  → reserva memoria para 5 enteros (5 * 4 = 20 bytes)
  → inicializa esos 20 bytes a 0.

-------------------------------------------------------------------------------
💡 APRENDIZAJE:
- calloc = malloc + inicialización.
- Siempre que reserves memoria dinámica para arrays, calloc es más seguro
  porque garantiza que todos los bytes comienzan en 0.
- Comprobar overflow con SIZE_MAX evita errores graves en arquitecturas grandes.
- Saber combinar malloc, sizeof, bzero y control de errores
  es esencial en programación de bajo nivel en C.
-------------------------------------------------------------------------------
*/

