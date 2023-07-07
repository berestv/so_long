/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asteroid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:19:50 by bbento-e          #+#    #+#             */
/*   Updated: 2023/07/07 15:30:51 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	asteroid(t_data *data)
{
	static int	i;

	srand(time((0)));
	if (i == data->r)
	{
		data->fd = 1;
		i = 0;
		data->r = (rand() % (100000 + 1 - 0) + 0);
		return (1);
	}
	i++;
	return (0);
}

void	execute_order66(t_data *data)
{
	static int	i;

	srand(time((0)));
	if (i == 0)
		mlx_put_image_to_window(data->mlx, data->win,
			data->astr[0], (data->ax * 64), (data->ay * 64));
	else if (i == 1500)
		mlx_put_image_to_window(data->mlx, data->win,
			data->astr[1], (data->ax * 64), (data->ay * 64));
	else if (i == 3000)
		mlx_put_image_to_window(data->mlx, data->win,
			data->astr[2], (data->ax * 64), (data->ay * 64));
	continue_order66(data, i);
	explode(data, i);
	if (i == data->explode)
		i = 0;
	i++;
}

void	continue_order66(t_data *data, int i)
{
	srand(time((0)));
	if (i == 4500)
		mlx_put_image_to_window(data->mlx, data->win,
			data->astr[3], (data->ax * 64), (data->ay * 64));
	else if (i == 6000)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->astr[4], (data->ax * 64), (data->ay * 64));
		img_picker(data, data->ax, data->ay);
		data->ax--;
		mlx_put_image_to_window(data->mlx, data->win,
			data->astr[0], (data->ax * 64), (data->ay * 64));
		data->explode = 6000;
	}
	if (data->map[data->ay][data->ax] != 'C'
		&& data->map[data->ay][data->ax] != '0')
		reset_astr_img(data);
}

void	explode(t_data *data, int i)
{
	if ((data->map[data->ay][data->ax - 1] == '1'
		|| data->map[data->ay][data->ax - 1] == 'P'))
	{
		data->explode = 21000;
		if (i == 9000)
			mlx_put_image_to_window(data->mlx, data->win,
				data->astr[5], (data->ax * 64), (data->ay * 64));
		else if (i == 12000)
			mlx_put_image_to_window(data->mlx, data->win,
				data->astr[6], (data->ax * 64), (data->ay * 64));
		else if (i == 15000)
			mlx_put_image_to_window(data->mlx, data->win,
				data->astr[7], (data->ax * 64), (data->ay * 64));
		else if (i == 18000)
			mlx_put_image_to_window(data->mlx, data->win,
				data->astr[8], (data->ax * 64), (data->ay * 64));
		else if (i == 21000)
		{
			mlx_put_image_to_window(data->mlx, data->win,
				data->astr[9], (data->ax * 64), (data->ay * 64));
			if (data->map[data->ay][data->ax - 1] == 'P')
				end(data);
			reset_astr_img(data);
		}
	}
}

void	reset_astr_img(t_data *data)
{
	img_picker(data, data->ax, data->ay);
	data->ax = data->x - 2;
	data->ay = (rand() % ((data->y - 2) + 1 - 0) + 1);
	data->fd = 0;
}
