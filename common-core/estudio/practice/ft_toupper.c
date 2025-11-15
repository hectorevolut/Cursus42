/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:59:13 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/14 17:05:01 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - 32);
	return (c);
}

int	main(void)
{
	int	c;

	c = 'a';
	printf("%c\n", ft_toupper(c));
	c = 'g';
	printf("%c\n", ft_toupper(c));
	c = 'Z';
	printf("%c\n", ft_toupper(c));
	c = '9';
	printf("%c\n", ft_toupper(c));
	return (0);
}
