/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hecalder <hecalder@student.42nalaga.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/10 14:54:59 by hecalder          #+#    #+#             */
/*   Updated: 2025/11/10 15:07:26 by hecalder         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_toupper(int c)
{
	unsigned char	ch;

	ch = (unsigned char) c;
	if (ch >= 'a' && ch <= 'z')
		return (ch - 32);
	return (ch);
}
