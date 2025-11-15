/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:25:11 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/14 16:31:41 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isascii(int c)
{
	if (c >=0 && c <= 127)
		return (1);
	return (0);
}

int	main(void)
{
	int	c;

	c = 'A';
	printf("%d\n", ft_isascii(c));
	c = 127;
	printf("%d\n", ft_isascii(c));
	c = 128;
	printf("%d\n", ft_isascii(c));
	c = 0;
	printf("%d\n", ft_isascii(c));
	c = -1;
	printf("%d\n", ft_isascii(c));
	return (0);
}
