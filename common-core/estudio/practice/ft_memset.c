/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:36:41 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/14 19:12:46 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memset(void *s, int c, size_t n)
{
	unsigned char *chars;
	size_t	i;

	chars = (unsigned char *)s; // Si omito (unsigned char *) hace conversión implícita
	i = 0;
	while (i < n)
	{
		*chars = (unsigned char) c;
		chars ++;
		i ++;
	}
	return (s);
}

int	main(void)
{
	char	buffer[10];

	ft_memset(buffer, 'H', 9);
	buffer[9] = '\0';
	printf("%s", buffer);
	return (0);
}
