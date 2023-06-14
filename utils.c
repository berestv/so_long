/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:23:32 by bbento-e          #+#    #+#             */
/*   Updated: 2023/06/14 18:07:57 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	get_lines(t_data *data, char *path)
{
	data->fd = open(path, O_RDONLY);

	return (0);
}

int	err_picker(char type)
{
	if (type == 'p')
		ft_putstr_fd("Error\nThe number of players should be 1.\n", 2);
	else if (type == 'e')
		ft_putstr_fd("Error\nThe number of exits should be 1.\n", 2);
	else if (type == 'c')
		ft_putstr_fd("Error\nYou should have at least one collectible.\n", 2);
	else if (type == 'i')
		ft_putstr_fd("Error\nUnsolvable map.\n", 2);
	else if (type == 's')
		ft_putstr_fd("Error\nMap is missing its boundaries.\n", 2);
	else if (type == 'r')
		ft_putstr_fd("Error\nMap isn't rectangular.\n", 2);
	else if (type == 'f')
		ft_putstr_fd("Error\nWrong map format. Use [path]/[mapname].ber\n", 2);
	else if (type == '/')
		ft_putstr_fd("Error\nFile not found. Use [path]/[mapname].ber\n", 2);
	return (-1);
}

void	err_handler(void)
{
	ft_putstr_fd("Error\nProgram usage: ./so_long [path]/[mapname].ber\n", 2);
}

int	int_err_handler(int n)
{
	ft_putstr_fd("Error\nProgram usage: ./so_long [path]/[mapname].ber\n", 2);
	return (n);
}

void	free_list(t_data *data)
{
	int	i;

	i = 0;
	if (data->mlx)
		free(data->mlx);
	if (data->map)
	{
		while (data->map[i])
		{
			free(data->map[i]);
			i++;
		}
		free(data->map);
	}
	i = 0;
	if (data->copy)
	{
		while (data->copy[i])
		{
			free(data->copy[i]);
			i++;
		}
		free(data->copy);
	}
}
