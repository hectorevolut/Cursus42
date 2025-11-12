/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:23:28 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/12 19:23:38 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Incluimos "libft.h" porque la función usa ft_isalpha() y ft_isdigit(),
   que también están declaradas en esta cabecera. */

int	ft_isalnum(int c)
/* La función recibe un entero (int) porque en C los caracteres se promueven
   a int para permitir valores especiales como EOF (-1). */
{
	unsigned char	ch;
	/* Usamos un unsigned char temporal para evitar problemas de signo
	   si 'c' tiene valores negativos (por ejemplo, caracteres extendidos). */

	ch = (unsigned char)c;
	/* Convertimos 'c' a unsigned char para garantizar una comparación segura. */

	if (ft_isalpha(ch) || ft_isdigit(ch))
	/* Si el carácter es alfabético (A–Z o a–z) O es un dígito (0–9),
	   devuelve verdadero. Usamos las funciones ya definidas para reutilizar código. */
		return (1);
		/* Devuelve 1 → el carácter es alfanumérico. */
	return (0);
	/* Devuelve 0 → no es ni letra ni número. */
}

/*
-------------------------------------------------------------------------------
🧠 EXPLICACIÓN:
La función ft_isalnum comprueba si el carácter recibido es alfanumérico,
es decir, si pertenece al conjunto de letras (A–Z, a–z) o dígitos (0–9).

Equivale a la función estándar isalnum() de <ctype.h>.

✔ Devuelve 1 → si el carácter es alfanumérico.
✖ Devuelve 0 → si no lo es.

Ejemplos:
ft_isalnum('A') → 1
ft_isalnum('3') → 1
ft_isalnum(' ') → 0
ft_isalnum('$') → 0

-------------------------------------------------------------------------------
💡 APRENDIZAJE:
- Reutilización de funciones internas (ft_isalpha, ft_isdigit).
- Uso de operadores lógicos OR (||).
- Buenas prácticas: conversión a unsigned char para evitar valores negativos.
- Modularidad: la función se apoya en componentes ya testados.
-------------------------------------------------------------------------------
*/

