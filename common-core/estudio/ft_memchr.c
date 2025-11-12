/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:47:15 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/12 19:47:47 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Incluimos libft.h para mantener la coherencia del proyecto
   y asegurar la declaración de la función. */

void	*ft_memchr(const void *s, int c, size_t n)
/* Busca la primera aparición del byte 'c' dentro del bloque de memoria 's',
   considerando un máximo de 'n' bytes.
   Si se encuentra, devuelve un puntero a esa posición de memoria.
   Si no se encuentra, devuelve NULL. */
{
	size_t				i;
	const unsigned char	*p;
	/* Usamos un puntero a unsigned char porque vamos a recorrer memoria
	   byte a byte, y unsigned char garantiza el tamaño de 1 byte exacto. */

	p = s;
	i = 0;
	while (i < n)
		/* Recorremos el bloque de memoria hasta un máximo de n bytes. */
	{
		if (p[i] == (unsigned char)c)
			/* Si encontramos el byte buscado (convertido a unsigned char),
			   devolvemos la dirección correspondiente. */
			return ((void *)(p + i));
			/* Hacemos cast a (void *) porque la función original devuelve
			   un puntero genérico a memoria (no a char). */

		i++;
	}
	return (NULL);
	/* Si llegamos al final sin encontrar el byte, devolvemos NULL. */
}

/*
-------------------------------------------------------------------------------
🧠 EXPLICACIÓN:
ft_memchr busca un byte concreto en un bloque de memoria sin depender
de terminadores de cadena ('\0'), a diferencia de funciones como ft_strchr.

✔ Parámetros:
- s → puntero al bloque de memoria donde se busca.
- c → valor del byte a buscar (se pasa como int por compatibilidad).
- n → número de bytes a examinar.

✔ Devuelve:
- Puntero a la primera aparición de 'c' dentro del bloque.
- NULL si no se encuentra en los primeros n bytes.

⚙️ Lógica:
1. Se convierte 's' en un puntero a unsigned char (unidad mínima de memoria).
2. Se recorre byte a byte comparando con 'c'.
3. Si hay coincidencia → se devuelve la dirección.
4. Si no → NULL.

Ejemplo visual:
  Memoria (s) = [0x41, 0x42, 0x43, 0x44]  ('A', 'B', 'C', 'D')
  c = 'C'
  n = 4
  → ft_memchr(s, 'C', 4) devuelve puntero al byte 0x43.

-------------------------------------------------------------------------------
💡 APRENDIZAJE:
- Diferencia clave con ft_strchr: aquí no hay '\0', se trabaja con memoria cruda.
- Uso del tipo unsigned char para acceder de forma segura a bytes individuales.
- Patrón de búsqueda secuencial en memoria, útil para parsing binario o buffers.
- Introduce el concepto de “puntero genérico” (void *).
-------------------------------------------------------------------------------
*/

