/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:24:51 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/12 19:25:20 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Incluimos "libft.h" para mantener la declaración coherente dentro del
   conjunto de funciones de la biblioteca. */

int	ft_isascii(int c)
/* Recibe un entero (int) porque en C los caracteres se manejan como enteros
   y pueden provenir de distintas fuentes, incluyendo valores negativos o EOF. */
{
	if (c >= 0 && c <= 127)
	/* Comprueba si el valor está dentro del rango ASCII estándar.
	   El código ASCII válido va del 0 al 127 (total de 128 caracteres). */
		return (1);
		/* Devuelve 1 si el carácter pertenece al conjunto ASCII. */
	return (0);
	/* Devuelve 0 si el valor está fuera del rango (por ejemplo, caracteres extendidos). */
}

/*
-------------------------------------------------------------------------------
🧠 EXPLICACIÓN:
ft_isascii determina si un valor entero pertenece al conjunto ASCII estándar.
El código ASCII define 128 símbolos: letras, dígitos, signos, control, etc.

✔ Devuelve 1 → si 0 ≤ c ≤ 127
✖ Devuelve 0 → si c < 0 o c > 127

ASCII incluye:
- Caracteres de control (0–31)
- Espacio (32)
- Símbolos, números, letras y signos de puntuación (33–126)
- DEL (127)

Ejemplos:
ft_isascii('A') → 1
ft_isascii(200) → 0
ft_isascii('\n') → 1
ft_isascii(-5) → 0

-------------------------------------------------------------------------------
💡 APRENDIZAJE:
- Concepto de rango ASCII (0–127).
- Validación simple de enteros con comparadores lógicos.
- Importancia de trabajar con int para evitar problemas de signo.
- Estructura mínima y eficiente en funciones booleanas.
-------------------------------------------------------------------------------
*/

