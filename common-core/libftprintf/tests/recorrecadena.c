/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   recorrecadena.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 15:05:54 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/30 15:25:38 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>

void	recorre_string(char *str)
{
	while (*str)
	{
		if (*str == '%')
		{
			str ++;
			printf("Se encontró un %% seguido de: %c\n", *str);
			str ++;
		}
		else
		{
			write (1, str, 1);
			write (1, "\n", 1);
			str ++;
		}
	}
}

int	main(void)
{
	char *str = "Hola %d Mundo %s";

	recorre_string(str);
	return (0);
}
