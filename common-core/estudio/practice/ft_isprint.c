/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:48:18 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/14 16:53:51 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}

int	main(void)
{
	int	c;

	c = 'A';
	printf("%d\n", ft_isprint(c));
	c = ' ';
	printf("%d\n", ft_isprint(c));
	c = 31;
	printf("%d\n", ft_isprint(c));
	c = 127;
	printf("%d\n", ft_isprint(c));
	c = '~';
	printf("%d\n", ft_isprint(c));
	return (0);
}
