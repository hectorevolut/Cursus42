/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:30:28 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/12 19:30:52 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Incluimos "libft.h" para mantener la declaración coherente dentro del
   proyecto y poder reutilizar la función en otros módulos de la librería. */

void	*ft_memset(void *s, int c, size_t n)
/* Esta función escribe 'n' bytes del valor 'c' en la zona de memoria apuntada
   por 's'. Devuelve el puntero original 's' para permitir encadenar operaciones. */
{
	unsigned char	*init;
	/* Definimos un puntero a unsigned char, ya que vamos a trabajar con
	   bytes individuales (1 byte = 8 bits). Esto permite manipular memoria
	   sin importar el tipo original del puntero recibido. */

	size_t	i;
	/* Variable para recorrer la memoria byte a byte. */

	init = (unsigned char *)s;
	/* Convertimos el puntero genérico 'void *' a 'unsigned char *' para
	   poder indexar posiciones de memoria y asignar valores byte a byte. */

	i = 0;
	/* Inicializamos el contador. */

	while (i < n)
	/* Recorremos los primeros 'n' bytes del bloque de memoria apuntado por 's'. */
	{
		init[i] = (unsigned char)c;
		/* Asignamos el valor convertido a unsigned char en cada posición.
		   El cast garantiza que solo se tome el byte menos significativo
		   del entero 'c', tal como define el estándar. */
		i++;
	}
	return (s);
	/* Devolvemos el puntero original 's' para mantener compatibilidad con
	   la función estándar memset() y permitir llamadas encadenadas. */
}

/*
-------------------------------------------------------------------------------
🧠 EXPLICACIÓN:
ft_memset llena un bloque de memoria con un valor específico, byte a byte.

✔ Parámetros:
- s → puntero al área de memoria a rellenar.
- c → valor que se escribirá en cada byte (convertido a unsigned char).
- n → número de bytes a escribir.

✔ Devuelve:
- El mismo puntero 's' que recibió como argumento.

Ejemplo visual:
char buffer[5];
ft_memset(buffer, 'A', 5);

buffer en memoria:
['A']['A']['A']['A']['A']

-------------------------------------------------------------------------------
💡 APRENDIZAJE:
- Manipulación directa de memoria a nivel de byte.
- Uso de punteros genéricos (void *) y necesidad de casting.
- Tipo unsigned char como unidad mínima de almacenamiento.
- Estructura clásica de bucle de asignación secuencial.
-------------------------------------------------------------------------------
*/

