/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 09:56:50 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/15 10:39:50 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	unsigned char		*auxdest;
	unsigned const char *auxsrc;
	size_t				i;
	auxdest =  (unsigned char *) dest;
	auxsrc = (unsigned const char *) src;
	if (auxdest < auxsrc)
	{
		i = 0;
		while (i < n)
		{
			auxdest[i] = auxsrc[i];
			i ++;
		}
	}
	else
	{
		i = n; //Si empiezo en n - tengo que decrementar antes de copiar
			   //Otra opción es empezar en n - 1 y decrementar después
		while (i > 0) //No usar i >= 0  con size_t - No tiene signo y será true siempre
		{
			i --;
			auxdest[i] = auxsrc[i];
		}
	}
	return (dest);
}

int	main(void)
{
	char	buffer[] = "ABCDEFG";
	ft_memmove(buffer + 2, buffer, 5);
	printf("%s\n", buffer);
	return (0);
}
