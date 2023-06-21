/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:35:23 by bbento-e          #+#    #+#             */
/*   Updated: 2023/06/21 18:39:28 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	builder(t_data *data)
{
	populate(data);
}

void	populate(t_data *data)
{
	int	x;
	int	y;

	y = 0;
	while (y < data->y)
	{
		x = 0;
		while (x < data->x)
		{
			if (data->map[y][x] == '0')
				mlx_put_image_to_window(data->mlx, data->win,
					data->floor, (x * 64), (y * 64));
			x++;
		}
		y++;
	}
}


