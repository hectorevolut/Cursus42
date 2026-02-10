/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_integer_functions.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/02/07 21:03:04 by hecalder          #+#    #+#             */
/*   Updated: 2026/02/07 21:03:48 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_digits(int n)
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
char	*ft_itoa(int n)
{
	char	*itoa;
	int		len;
	long	nb;

	nb = n;
	len = ft_count_digits(n);
	itoa = malloc(len + 1);
	if (!itoa)
		return (NULL);
	itoa[len] = '\0';
	if (nb < 0)
	{
		itoa[0] = '-';
		nb *= -1;
	}
	while (--len >= 0 && itoa[len] != '-')
	{
		itoa[len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (itoa);
}
int	ft_count_digits_u(unsigned int n)
{
	int		        count;
	unsigned long	nb;

	nb = n;
	if (nb == 0)
		return (1);
	count = 0;
	while (nb)
	{
		nb /= 10;
		count ++;
	}
	return (count);
}
char	*ft_utoa(unsigned int n)
{
	char			*utoa;
	int				len;
	unsigned long	nb;

	nb = n;
	len = ft_count_digits_u(n);
	utoa = malloc(len + 1);
	if (!utoa)
		return (NULL);
	utoa[len] = '\0';
	while (--len >= 0)
	{
		utoa[len] = (nb % 10) + '0';
		nb /= 10;
	}
	return (utoa);
}
char	*ft_utoa_base(unsigned long int n, int base, char *tabla)
{
	char			*utoa_base;
	int				len;
	unsigned long	nb;

	nb = n;
    len = 0;
    if (n == 0)
        len = 1;
	while (n > 0)
	{
        n /= base;
        len ++;
    }
	utoa_base = malloc(len + 1);
	if (!utoa_base)
		return (NULL);
	utoa_base[len] = '\0';
	while (--len >= 0)
	{
		utoa_base[len] = tabla[nb % base];
		nb /= base;
	}
	return (utoa_base);
}
