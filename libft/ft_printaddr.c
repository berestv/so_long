/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printaddr.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/06 15:11:28 by bbento-e          #+#    #+#             */
/*   Updated: 2023/02/06 18:38:06 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printaddr(unsigned long addr)
{
	int	i;

	i = 0;
	if (!addr)
		return (ft_putstr("(nil)"));
	i += ft_putstr("0x");
	i += ft_puthex(addr, 'x');
	return (i);
}
