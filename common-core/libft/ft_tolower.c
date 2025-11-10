/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42malaga.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 15:12:46 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/10 15:16:21 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_tolower(int c)
{
	unsigned char	ch;

	ch = (unsigned char) c;
	if (ch >= 'A' && ch <= 'Z')
		return (ch + 32);
	return (ch);
}
