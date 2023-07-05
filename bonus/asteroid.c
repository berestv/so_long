/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asteroid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:19:50 by bbento-e          #+#    #+#             */
/*   Updated: 2023/07/05 16:43:44 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	asteroid(t_data *data)
{
	static int	i;
	static int	r;
	int			y;

	r = (rand() % (200000 + 1 - 0) + 0);
	if (i == r)
	{
		y = (data->y + 1 - 0) + 0;
		execute_order66(data, data->x, y, 0);
		i = 0;
		r = (rand() % (200000 + 1 - 0) + 0);
	}
	i++;
}

void	execute_order66(t_data *data, int x, int y, int i)
{
	if (i == 0)
		mlx_put_image_to_window(data->mlx, data->win,
								data->astr[0], (x * 64), (y * 64));
	else if (i == 1300)
		mlx_put_image_to_window(data->mlx, data->win,
								data->astr[1], (x * 64), (y * 64));
	else if (i == 2600)
		mlx_put_image_to_window(data->mlx, data->win,
								data->astr[2], (x * 64), (y * 64));
	else if (i == 3900)
		mlx_put_image_to_window(data->mlx, data->win,
								data->astr[3], (x * 64), (y * 64));
	else if (i == 5400)
	{
		mlx_put_image_to_window(data->mlx, data->win,
								data->astr[4], (x * 64), (y * 64));
		i = 0;
	}
	x--;
	i++;
}
