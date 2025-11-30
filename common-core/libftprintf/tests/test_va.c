/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_va.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 14:55:16 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/30 15:18:14 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>

int sumint(int count, ...)
{
	int	sum;
	int	i;

	sum = 0;
	i = 0;
	va_list(args);
	va_start(args, count);
	while (i < count)
	{
		sum += va_arg(args, int);
		i ++;
	}
	va_end(args);
	return (sum);
}

int	main(void)
{
	printf("La suma es: %d\n", sumint(6, 10, 20, 30, 3, 4, 5));
	return (0);
}
