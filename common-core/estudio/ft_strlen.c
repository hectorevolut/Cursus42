/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:27:36 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/12 19:29:25 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Incluimos "libft.h" para declarar la función dentro de la biblioteca y
   mantener coherencia con el resto del proyecto. */

size_t	ft_strlen(const char *s)
/* Recibe un puntero a una cadena de caracteres (const char *).
   Se usa 'const' porque la función no debe modificar la cadena original.
   Devuelve un valor de tipo size_t, el más apropiado para contar tamaños o longitudes. */
{
	size_t	length;
	/* Declaramos una variable 'length' de tipo size_t (entero sin signo) para
	   almacenar el número de caracteres. Este tipo evita desbordamientos al
	   tratar con conteos o tamaños en memoria. */

	length = 0;
	/* Inicializamos el contador en 0 para empezar a contar desde el primer carácter. */

	while (s[length])
	/* El bucle recorre la cadena hasta encontrar el carácter nulo '\0',
	   que marca el final de toda cadena en C. */
		length++;
		/* Por cada carácter no nulo, incrementamos el contador. */

	return (length);
	/* Al salir del bucle, 'length' contiene la cantidad de caracteres de la cadena.
	   El valor devuelto excluye el carácter nulo ('\0'). */
}

/*
-------------------------------------------------------------------------------
🧠 EXPLICACIÓN:
ft_strlen calcula la longitud de una cadena terminada en '\0'.
Equivale al comportamiento de la función estándar strlen() de <string.h>.

✔ Devuelve → número de caracteres antes del '\0'
✖ No incluye el '\0' en el conteo.

Ejemplo de cadena en memoria:
"s" = ['H']['o']['l']['a']['\0']
              ↑   ↑   ↑   ↑   ↳ fin de cadena

ft_strlen("Hola") → 4

-------------------------------------------------------------------------------
💡 APRENDIZAJE:
- Cómo se representan las cadenas en C (terminadas en '\0').
- Uso del tipo size_t para tamaños y longitudes.
- Recorrido secuencial con índice sobre punteros.
- Lógica de parada basada en el carácter nulo.
-------------------------------------------------------------------------------
*/

