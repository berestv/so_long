/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:23:17 by bbento-e          #+#    #+#             */
/*   Updated: 2023/07/04 14:27:55 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	err_picker(char type)
{
	if (type == 'p')
		ft_putstr_fd("Error\nThe number of players should be 1.\n", 2);
	else if (type == 'e')
		ft_putstr_fd("Error\nThe number of exits should be 1.\n", 2);
	else if (type == 'c')
		ft_putstr_fd("Error\nYou should have at least 1 collectible.\n", 2);
	else if (type == 'i')
		ft_putstr_fd("Error\nUnsolvable map.\n", 2);
	else if (type == 'w')
		ft_putstr_fd("Error\nMap is missing its boundaries.\n", 2);
	else if (type == 'r')
		ft_putstr_fd("Error\nMap isn't rectangular.\n", 2);
	else if (type == 'E')
		ft_putstr_fd("Error\nThe player is unable to exit the map.\n", 2);
	else if (type == 'C')
		ft_putstr_fd("Error\nThere's at least one unreachable collectible.\n", 2);
	else if (type == 'I')
		ft_putstr_fd("Error\nInvalid characters found.\n", 2);
	return (-1);
}

int	err_pick(char type, int i)
{
	if (type == 'f')
		ft_putstr_fd("Error\nWrong map format. Use [path]/[mapname].ber\n", 2);
	else if (type == 'r')
		ft_putstr_fd("Error\nMap isn't rectangular.\n", 2);
	else if (type == '/')
	{
		ft_putstr_fd("Error\nFile not found. Use [path]/[mapname].ber\n", 2);
		close(i);
	}
	exit(0);
}

int	int_err_handler(int n)
{
	ft_putstr_fd("Error\nProgram usage: ./so_long [path]/[mapname].ber\n", 2);
	return (n);
}
