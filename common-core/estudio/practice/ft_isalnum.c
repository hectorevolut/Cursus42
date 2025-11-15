/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 16:13:43 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/14 16:21:50 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	ft_isalpha(int c)
{
	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
	return (1);
	return (0);
}

int	ft_isdigit(int n)
{
	if (n >= '0' && n <= '9')
		return (1);
	return (0);
}

int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	return (0);
}

int	main(void)
{
	int	n;

	n = 'A';
	printf("%d\n", ft_isalnum(n));
	n = 'z';
	printf("%d\n", ft_isalnum(n));
	n = '4';
	printf("%d\n", ft_isalnum(n));
	n = '%';
	printf("%d\n", ft_isalnum(n));
	n = ' ';
	printf("%d\n", ft_isalnum(n));
	return (0);
}
