/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 12:01:57 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/14 17:29:58 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i ++;
	return (i);
}

size_t	ft_strlen_ptr(char *str)
{
	char	*start;

	start = str;
	while (*str)
		str ++;
	return (str - start);
}

int main(void)
{
	char	*string = "";

	printf("%zu\n", ft_strlen(string));
	printf("%zu\n", ft_strlen_ptr(string));
	return (0);
}
