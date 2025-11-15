/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:06:05 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/14 17:09:47 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		return (c + 32);
	return (c);
}

int	main(void)
{
	int	c;

	c = 'a';
	printf("%c\n", ft_tolower(c));
	c = 'g';
	printf("%c\n", ft_tolower(c));
	c = 'Z';
	printf("%c\n", ft_tolower(c));
	c = '9';
	printf("%c\n", ft_tolower(c));
	return (0);
}
