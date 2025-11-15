/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/15 08:36:32 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/15 10:15:40 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*auxdest;
	const unsigned char	*auxsrc;
	size_t				i;

	auxdest = (unsigned char *) dest;
	auxsrc = (const unsigned char *) src;
	i = 0;
	while (i < n)
	{
		*auxdest = *auxsrc;
		auxdest ++;
		auxsrc ++;
		i ++;
	}
	return (dest);
}

int	main(void)
{
	int		a[7] = {3, 2, 4, 1, 5, 6, 7};
	int		b[3];
	size_t	i;
	size_t	elements;

	elements = 3;
	ft_memcpy(b, a, elements * sizeof(int)); // Hay solapamiento - Error
	i = 0;
	while (i < elements)
	{
		printf("%d", b[i]);
		i ++;
	}
	return (0);
}
