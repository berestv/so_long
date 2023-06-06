/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:28:00 by bbento-e          #+#    #+#             */
/*   Updated: 2023/06/06 19:32:51 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	err_handler(void)
{
	ft_printf("Error!\nProgram usage: ./so_long [path]/[mapname].ber");
}

int	int_err_handler(int n)
{
	ft_printf("Error!\nProgram usage: ./so_long [path]/[mapname].ber");
	return (n);
}
