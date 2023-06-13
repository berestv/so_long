/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:28:00 by bbento-e          #+#    #+#             */
/*   Updated: 2023/06/13 19:46:22 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_lines()
{

}

int 	err_picker(char type)
{
	if (type == 'p')
		ft_putstr_fd("The number of players on the map should be 1.\n", 2);
	else if (type == 'e')
		ft_putstr_fd("The number of players on the map should be 1.\n", 2);
	return (-1);
}


void	err_handler(void)
{
	ft_putstr_fd("Error! Program usage: ./so_long [path]/[mapname].ber\n", 2);
}

int	int_err_handler(int n)
{
	ft_putstr_fd("Error! Program usage: ./so_long [path]/[mapname].ber\n", 2);
	return (n);
}
