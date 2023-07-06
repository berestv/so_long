/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:34:20 by bbento-e          #+#    #+#             */
/*   Updated: 2023/07/06 19:23:55 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

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

int	next_random(unsigned int seed)
{
	unsigned int	multiplier;
	unsigned int	increment;
	unsigned int	modulus;

	multiplier = 13515245;
	increment = 12345;
	modulus = 21474848;
	seed = (multiplier * seed + increment) % modulus;
	return ((int)seed);
}

int	key_handler(int key, t_data *data)
{
	if (key == XK_Escape)
		end(data);
	else if (key == XK_w || key == XK_a || key == XK_s || key == XK_d)
		mvmnt(data, key);
	else
		return (-1);
	return (0);
}
