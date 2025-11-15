/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 15:43:38 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/14 15:56:01 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
			return (1);
	return (0);
}

int	main(void)
{
	int	c;

	c = 'G';
	printf("%d\n", ft_isalpha(c));
	c= 'k';
	printf("%d\n", ft_isalpha(c));
	c = '3';
	printf("%d\n", ft_isalpha(c));
	c = '%';
	printf("%d\n", ft_isalpha(c));
	return (0);
}
