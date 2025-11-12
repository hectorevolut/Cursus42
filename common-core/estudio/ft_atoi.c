/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/12 19:52:16 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/12 19:52:27 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* Función auxiliar interna que identifica espacios en blanco
   según las reglas de isspace del estándar de C. */
static int	ft_isspace(char chr)
{
	if (chr == ' ' || chr == '\f' || chr == '\n' || chr == '\r')
		return (1);
	else if (chr == '\t' || chr == '\v')
		return (1);
	else
		return (0);
	/* Devuelve 1 si el carácter es un espacio válido, 0 en caso contrario. */
}

int	ft_atoi(const char *str)
/* Convierte una cadena de texto numérica en un entero (int).
   Ignora espacios iniciales, gestiona signos '+' o '-',
   y procesa los dígitos hasta que encuentra un carácter no numérico. */
{
	int	sign;
	int	result;
	int	asigned;
	/* sign → controla si el número será positivo o negativo.
	   result → acumula el valor numérico convertido.
	   asigned → controla que solo haya un signo (+ o -). */

	sign = 1;
	result = 0;
	asigned = 0;

	while (ft_isspace(*str))
		/* Saltamos todos los espacios en blanco iniciales. */
		str++;

	while (*str == '+' || *str == '-')
		/* Si hay un signo al principio, lo procesamos. */
	{
		if (*str == '-')
			sign *= -1;
			/* Si es '-', invertimos el signo multiplicándolo por -1. */
		str++;
		asigned++;
		if (asigned > 1)
			/* Si hay más de un signo consecutivo, devolvemos 0,
			   ya que no sería una conversión válida (por ejemplo "--42"). */
			return (0);
	}

	while (*str >= '0' && *str <= '9')
		/* Mientras haya caracteres numéricos, los procesamos. */
	{
		result = result * 10 + (*str - '0');
		/* Multiplicamos el valor previo por 10 y sumamos el nuevo dígito.
		   (*str - '0') convierte el carácter ASCII a su valor numérico. */
		str++;
	}

	return (result * sign);
	/* Devolvemos el número final con su signo aplicado. */
}

/*
-------------------------------------------------------------------------------
🧠 EXPLICACIÓN:
ft_atoi convierte texto a número entero, siguiendo la lógica de la función
atoi estándar del C. Es fundamental para interpretar valores leídos de texto.

✔ Parámetros:
- str → puntero a la cadena de texto a convertir.

✔ Devuelve:
- El número entero resultante (tipo int).
- Si la cadena no contiene dígitos válidos, devuelve 0.
- No gestiona overflow, por lo que un número fuera de rango produce
  comportamiento indefinido (igual que atoi original).

⚙️ Lógica:
1. Saltar espacios iniciales (isspace).
2. Detectar signo y ajustarlo si es '-'.
3. Convertir cada carácter numérico en valor decimal.
4. Parar al encontrar un carácter no numérico.
5. Devolver el resultado multiplicado por el signo.

Ejemplo:
  str = "   -1234abc"
  → Ignora espacios → detecta signo negativo → convierte 1234 → resultado -1234

-------------------------------------------------------------------------------
💡 APRENDIZAJE:
- La conversión *carácter a número* se basa en la diferencia ASCII: `'0' = 48`.
- Manejar el signo antes del bucle evita operaciones extra después.
- El control de `asigned` previene casos como `--42` o `+-5`, que no son válidos.
- Es un gran ejemplo de control de flujo y validación paso a paso en C.
-------------------------------------------------------------------------------
*/

