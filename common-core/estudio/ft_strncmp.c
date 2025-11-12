/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:46:16 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/12 19:46:36 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/* Incluimos libft.h para disponer de la declaración y mantener consistencia. */

int	ft_strncmp(const char *s1, const char *s2, size_t n)
/* Compara las dos cadenas s1 y s2 hasta un máximo de 'n' caracteres.
   Devuelve la diferencia entre el primer par de caracteres distintos,
   o 0 si son iguales en los primeros 'n' caracteres. */
{
	size_t	i;

	if (n == 0)
		/* Si n es 0, no hay nada que comparar → se consideran iguales. */
		return (0);

	i = 0;
	while (i < n - 1 && s1[i] && s2[i] && s1[i] == s2[i])
		/* Recorremos ambas cadenas carácter a carácter mientras:
		   - No hayamos alcanzado el límite n - 1.
		   - Ninguna haya terminado ('\0').
		   - Los caracteres sean iguales. */
		i++;

	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
	/* Comparamos el primer carácter distinto o el final si alguna cadena terminó.
	   Se hace cast a (unsigned char) para evitar errores con caracteres negativos.
	   Si las cadenas son iguales hasta n, la resta será 0. */
}

/*
-------------------------------------------------------------------------------
🧠 EXPLICACIÓN:
ft_strncmp compara dos cadenas de forma controlada, limitando el número máximo
de caracteres comparados (n). Es una versión segura de strcmp.

✔ Parámetros:
- s1 → primera cadena.
- s2 → segunda cadena.
- n → número máximo de caracteres a comparar.

✔ Devuelve:
- 0 → si las cadenas son iguales en los primeros 'n' caracteres.
- Valor positivo → si el primer carácter distinto en s1 > s2.
- Valor negativo → si el primer carácter distinto en s1 < s2.

⚙️ Lógica:
1. Recorre ambas cadenas mientras haya caracteres y no se supere n-1.
2. Si se encuentra una diferencia → se devuelve la resta de esos caracteres.
3. Si no hay diferencias en los primeros n → se devuelve 0.

Ejemplo:
  s1 = "Hola", s2 = "Horno", n = 3 → resultado = 0 (porque "Hol" == "Hor" en los 3 primeros)
  s1 = "abc", s2 = "abd", n = 3 → resultado = -1 (porque 'c' - 'd' = -1)
  s1 = "abc", s2 = "abc", n = 5 → resultado = 0

-------------------------------------------------------------------------------
💡 APRENDIZAJE:
- Saber cómo limitar comparaciones con 'n' para evitar lecturas fuera de rango.
- Entender el uso del cast a (unsigned char) para evitar overflow de signo.
- Comprender cómo se determina el orden lexicográfico entre cadenas.
- Estructura base para implementar funciones como ft_memcmp.
-------------------------------------------------------------------------------
*/

