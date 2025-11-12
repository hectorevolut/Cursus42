/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:26:20 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/12 19:26:42 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Incluimos "libft.h" para mantener la coherencia con el resto de funciones
   de la biblioteca y declarar el prototipo de ft_isprint. */

int	ft_isprint(int c)
/* La función recibe un int (y no un char) porque los caracteres en C se
   promueven a enteros automáticamente. Esto evita errores con valores negativos. */
{
	if (c >= 32 && c <= 126)
	/* En la tabla ASCII, los caracteres imprimibles van desde 32 (espacio ' ')
	   hasta 126 ('~'). Todo lo que esté fuera de ese rango son caracteres de
	   control (no visibles), como tabulaciones o saltos de línea. */
		return (1);
		/* Devuelve 1 → el carácter es imprimible. */
	return (0);
	/* Devuelve 0 → no es imprimible (por ejemplo, '\n', '\t', etc.). */
}

/*
-------------------------------------------------------------------------------
🧠 EXPLICACIÓN:
ft_isprint comprueba si el carácter pasado es imprimible,
es decir, si corresponde a un símbolo visible en pantalla (incluido el espacio).

✔ Devuelve 1 → si el valor ASCII está entre 32 y 126.
✖ Devuelve 0 → si está fuera de ese rango (caracteres de control o extendidos).

ASCII relevantes:
32 = ' ' (espacio)
33–47 = signos de puntuación
48–57 = '0'–'9'
65–90 = 'A'–'Z'
97–122 = 'a'–'z'
126 = '~'

Ejemplos:
ft_isprint('A') → 1
ft_isprint(' ') → 1
ft_isprint('\n') → 0
ft_isprint(127) → 0

-------------------------------------------------------------------------------
💡 APRENDIZAJE:
- Comprensión del rango de caracteres imprimibles en ASCII.
- Evaluación condicional simple (rango inclusivo).
- Distinción entre caracteres de control e imprimibles.
- Patrón clásico de función booleana en C: return (1) / return (0).
-------------------------------------------------------------------------------
*/

