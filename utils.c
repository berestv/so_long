/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/06 19:28:00 by bbento-e          #+#    #+#             */
/*   Updated: 2023/06/14 17:12:58 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*int	get_lines(t_data *data, char *path)
{
	data->fd = open();
}*/

int	err_picker(char type)
{
	if (type == 'p')
		ft_putstr_fd("Error\n The number of players should be 1.\n", 2);
	else if (type == 'e')
		ft_putstr_fd("Error\n The number of exits should be 1.\n", 2);
	else if (type == 'c')
		ft_putstr_fd("Error\n You should have at least one collectible.\n", 2);
	else if (type == 'i')
		ft_putstr_fd("Error\n Unsolvable map.\n", 2);
	else if (type == 's')
		ft_putstr_fd("Error\n Map is missing its boundaries.\n", 2);
	else if (type == 'r')
		ft_putstr_fd("Error\n Map isn't rectangular.\n", 2);
	else if (type == 'f')
		ft_putstr_fd("Error\nWrong map format. Use [mapname].ber\n", 2);
	return (-1);
}

void	err_handler(void)
{
	ft_putstr_fd("Error\n Program usage: ./so_long [path]/[mapname].ber\n", 2);
}

int	int_err_handler(int n)
{
	ft_putstr_fd("Error\n Program usage: ./so_long [path]/[mapname].ber\n", 2);
	return (n);
}

void	free_list(t_data *data)
{
	int	i;

	i = 0;
	free(data->mlx);
	while (data->map)
	{
		free(data->map[i]);
		i++;
	}
	free(data->map);
	i = 0;
	while (data->copy)
	{
		free(data->copy[i]);
		i++;
	}
	free(data->copy);
}
