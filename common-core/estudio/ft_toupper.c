/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:39:58 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/12 19:40:18 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
/* Convierte un carácter en minúscula ('a'–'z') a mayúscula ('A'–'Z').
   Si el carácter no es una letra minúscula, se devuelve sin modificar. */
{
	if (c >= 'a' && c <= 'z')
		/* Comprobamos si el valor ASCII del carácter está entre
		   los códigos de las letras minúsculas (97–122). */
		return (c - 32);
		/* Restamos 32 porque en la tabla ASCII la diferencia entre
		   una letra minúscula y su mayúscula equivalente es de 32 posiciones. */

	return (c);
	/* Si no está en el rango de minúsculas, se devuelve el mismo carácter. */
}

/*
-------------------------------------------------------------------------------
🧠 EXPLICACIÓN:
ft_toupper convierte letras minúsculas a mayúsculas según su código ASCII.

✔ Parámetro:
- c → carácter (recibido como int por compatibilidad con EOF y funciones de stdio).

✔ Devuelve:
- La versión mayúscula del carácter si era minúscula.
- El mismo carácter si no lo era.

⚙️ Lógica:
- En ASCII:
  'a' → 97
  'A' → 65
  Diferencia → 32 → (97 - 32 = 65)

Ejemplo:
  ft_toupper('b') → 'B'
  ft_toupper('!') → '!'

-------------------------------------------------------------------------------
💡 APRENDIZAJE:
- Entender la relación entre los rangos ASCII de letras mayúsculas y minúsculas.
- Saber por qué se usa un parámetro tipo `int` en lugar de `char`.
- Este tipo de manipulación de caracteres se repite en ft_tolower.
-------------------------------------------------------------------------------
*/

