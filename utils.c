/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:28:00 by bbento-e          #+#    #+#             */
/*   Updated: 2023/06/12 17:45:22 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_handler(void)
{
	ft_putstr_fd("Error! Program usage: ./so_long [path]/[mapname].ber\n", 2);
}

int	int_err_handler(int n)
{
	ft_putstr_fd("Error! Program usage: ./so_long [path]/[mapname].ber\n", 2);
	return (n);
}
