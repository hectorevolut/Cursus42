/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:21:56 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/12 19:22:07 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Incluimos "libft.h" para declarar la función dentro del proyecto y
   mantener coherencia con las demás funciones de la biblioteca. */

int	ft_isdigit(int c)
/* La función recibe un entero porque en C los caracteres se promueven a int.
   Así puede manejar correctamente caracteres y valores especiales como EOF. */
{
	if (c >= '0' && c <= '9')
	/* Comprobamos si el valor entero (ASCII) de 'c' está entre '0' y '9'.
	   En la tabla ASCII, los dígitos consecutivos ocupan los valores 48–57. */
		return (1);
		/* Si el carácter está dentro de ese rango, devuelve 1 (verdadero). */
	return (0);
	/* Si no lo está, devuelve 0 (falso). */
}

/*
-------------------------------------------------------------------------------
🧠 EXPLICACIÓN:
Determina si el carácter pasado como argumento es un dígito decimal.
Equivale a la función estándar isdigit() de <ctype.h>.

✔ Devuelve 1 → si 'c' representa un número entre '0' y '9'.
✖ Devuelve 0 → si no es un número.

ASCII:
'0' = 48
'1' = 49
...
'9' = 57

Ejemplos:
ft_isdigit('3') → 1
ft_isdigit('a') → 0
ft_isdigit(' ') → 0
ft_isdigit('9') → 1

-------------------------------------------------------------------------------
💡 APRENDIZAJE:
- Comparaciones directas con valores ASCII.
- Uso de condiciones simples (rango inclusivo).
- Lógica booleana básica: devolver 1 o 0.
- Comprensión del tipo int para funciones de clasificación de caracteres.
-------------------------------------------------------------------------------
*/

