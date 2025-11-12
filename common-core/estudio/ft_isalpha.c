/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:17:06 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/12 19:19:30 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Incluimos libft.h para que el compilador conozca la declaración de la función
   y mantenga coherencia con el resto de la librería. */

int	ft_isalpha(int c)
/* Recibe un entero (no un char). En C, los caracteres se promueven a int para
   permitir también valores especiales como EOF (-1). */
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	/* Comprobamos si el valor ASCII está en el rango de letras mayúsculas (A-Z)
	   o minúsculas (a-z). Los caracteres en C son en realidad números enteros. */
		return (1);
		/* Si el carácter pertenece a alguno de esos rangos, devolvemos 1.
		   En C, cualquier valor distinto de 0 se considera "verdadero". */
	return (0);
	/* Si no está en los rangos anteriores, devolvemos 0 (falso). */
}

/*
-------------------------------------------------------------------------------
🧠 EXPLICACIÓN:
Esta función determina si un carácter es alfabético.
Equivale al comportamiento de la función estándar isalpha() de <ctype.h>.

✔ Devuelve 1 → si el carácter es una letra (A-Z o a-z)
✖ Devuelve 0 → si no lo es

ASCII:
A-Z → 65–90
a-z → 97–122

Ejemplos:
ft_isalpha('A') → 1
ft_isalpha('z') → 1
ft_isalpha('5') → 0
ft_isalpha('$') → 0

-------------------------------------------------------------------------------
💡 APRENDIZAJE:
- Manejo de condiciones lógicas con operadores && y ||.
- Uso del tipo int para representar caracteres en C.
- Concepto de “verdadero/falso” numérico.
- Comprensión de los rangos ASCII.
-------------------------------------------------------------------------------
*/
