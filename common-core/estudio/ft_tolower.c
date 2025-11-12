/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:41:31 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/12 19:41:58 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
/* Convierte un carácter en mayúscula ('A'–'Z') a minúscula ('a'–'z').
   Si el carácter no es una letra mayúscula, lo devuelve sin modificar. */
{
	if (c >= 'A' && c <= 'Z')
		/* Comprobamos si el valor ASCII del carácter está dentro del rango
		   de letras mayúsculas (65–90). */
		return (c + 32);
		/* Sumamos 32 porque en la tabla ASCII la diferencia entre
		   una letra mayúscula y su minúscula equivalente es de 32 posiciones. */

	return (c);
	/* Si el carácter no es una letra mayúscula, se devuelve tal cual. */
}

/*
-------------------------------------------------------------------------------
🧠 EXPLICACIÓN:
ft_tolower convierte letras mayúsculas a minúsculas según su código ASCII.

✔ Parámetro:
- c → carácter (pasado como int para compatibilidad con EOF y funciones estándar).

✔ Devuelve:
- La versión minúscula del carácter si era mayúscula.
- El mismo carácter si no lo era.

⚙️ Lógica:
- En ASCII:
  'A' → 65
  'a' → 97
  Diferencia → 32 → (65 + 32 = 97)

Ejemplo:
  ft_tolower('D') → 'd'
  ft_tolower('7') → '7'

-------------------------------------------------------------------------------
💡 APRENDIZAJE:
- La relación numérica entre mayúsculas y minúsculas en ASCII es constante (32).
- Este patrón de transformación es simétrico con ft_toupper.
- Saber cuándo usar `int` en vez de `char` evita errores con EOF o caracteres extendidos.
-------------------------------------------------------------------------------
*/

