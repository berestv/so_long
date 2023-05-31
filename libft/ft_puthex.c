/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_puthex.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:11:54 by bbento-e          #+#    #+#             */
/*   Updated: 2023/02/06 18:41:53 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_puthex(unsigned long hex, char c)
{
	int		i;
	char	*base;

	i = 0;
	if (c == 'x')
		base = "0123456789abcdef";
	else if (c == 'X')
		base = "0123456789ABCDEF";
	if (hex < 16)
		i += ft_putchar(base[hex]);
	else
	{
		i += ft_puthex(hex / 16, c);
		i += ft_puthex(hex % 16, c);
	}
	return (i);
}
