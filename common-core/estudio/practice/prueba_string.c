/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prueba_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 08:15:44 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/14 08:24:04 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	prueba_const_string()
{
	char	*s = "Hola";
	s[0] = 'X';
	printf("s = %s\n", s);
}

void	prueba_array_string()
{
	char s[] = "Hola";
	s[0] = 'X';
	printf("s = %s\n", s);
}

int	main(void)
{
	prueba_const_string();
	prueba_array_string();
	return (0);
}
