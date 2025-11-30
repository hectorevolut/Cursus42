/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mini_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 15:25:49 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/30 20:24:51 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>

size_t	ft_strlen(const char *s)
{
	size_t	length;

	length = 0;
	while (s[length])
		length ++;
	return (length);
}

static int	count_digits(int n)
{
	int		count;
	long	nb;

	nb = n;
	count = (nb <= 0);
	if (nb < 0)
		nb = -nb;
	while (nb)
	{
		nb /= 10;
		count++;
	}
	return (count);
}

static char	*ft_itoa(int n)
{
	char	*itoa;
	int		len_isneg[2];
	long	nb;

	len_isneg[1]= 0;
	nb = n;
	len_isneg[0] = count_digits(n);
	itoa = malloc(len_isneg[0] + 1);
	if (!itoa)
		return (NULL);
	itoa[len_isneg[0]] = '\0';
	if (nb < 0)
	{
		nb *= -1;
		len_isneg[1] = 1;
	}
	while (len_isneg[0] > 0)
	{
		itoa[len_isneg[0] - 1] = (nb % 10) + '0';
		nb /= 10;
		len_isneg[0] --;
	}
	if (len_isneg[1])
		itoa[0] = '-';
	return (itoa);
}

void	mini_printf(const char *format, ...)
{
	va_list	args;
	int	integer;
	char *str;

	va_start(args, format);
	while (*format)
	{
		if (*format == '%')
		{
			format ++;
			if (*format == 'd')
			{
				integer = va_arg(args, int);
				str = ft_itoa(integer);
				if (str)
				{
					write(1 , str, ft_strlen(str));
					free(str);
				}
				format ++;
			}
			else if (!*format)
			{
				write(1, "%", 1);
			}
			else
			{
				write(1, "%", 1);
				format ++;
			}
		}
		else
		{
			write (1, format, 1);
			format ++;
		}
	}
	va_end(args);
	write(1, "\n", 1);
}

int	main(void)
{
	char	*str1 = "Número: %d y texto.";
	char	*str2 = "Literal porcentaje: %";
	char	*str3 = "Texto con %x sin implementar";

	mini_printf(str1, 1);
	mini_printf(str2);
	mini_printf(str3);
	mini_printf("Número: %d y texto.", 42);
	mini_printf("Número negativo: %d", -123);
	mini_printf("Cero: %d", 0);
	mini_printf("Fin en porcentaje: %");
	mini_printf("No implementado: %x", 42);

	return (0);
}
