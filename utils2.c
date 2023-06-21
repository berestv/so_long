/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:34:20 by bbento-e          #+#    #+#             */
/*   Updated: 2023/06/21 15:55:48 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_array(t_data *data, char **array)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= data->y)
	{
		while (array && array[i][j] != '\0')
		{
			ft_printf("%c", array[i][j]);
			j++;
		}
		i++;
		j = 0;
		ft_printf("\n");
	}
}

void	player_handler(t_types *types, t_data *data, int x, int y)
{
	types->player++;
	data->px = x;
	data->py = y;
}

void	wall_handler(t_types *types, t_data *data, int x, int y)
{
	if (data->map[y][x] == '1')
		types->wall++;
	else
		types->trigger = -1;
}