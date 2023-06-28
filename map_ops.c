/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:35:23 by bbento-e          #+#    #+#             */
/*   Updated: 2023/06/28 14:03:29 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	populate(t_data *data)
{
	int	x;
	int	y;

	img_init(data);
	y = 0;
	while (y <= data->y)
	{
		x = 0;
		while (x < data->x)
		{
			img_picker(data, x, y);
			x++;
		}
		y++;
	}
}

void	img_picker(t_data *data, int x, int y)
{
	int	s;
	int	r;


	s = next_random(data->x + data->y + x + y);
	r = rand_gen(0, 9, s);
	if (data->map[y][x] == '0')
		mlx_put_image_to_window(data->mlx, data->win,
			data->floor, (x * 64), (y * 64));
	else if (data->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx, data->win,
			data->wall[r], (x * 64), (y * 64));
	else if (data->map[y][x] == 'P')
		mlx_put_image_to_window(data->mlx, data->win,
			data->playeru[0], (x * 64), (y * 64));
	else if (data->map[y][x] == 'C')
	{
		r = contradict();
		mlx_put_image_to_window(data->mlx, data->win,
			data->clct[r], (x * 64), (y * 64));
	}
	else if (data->map[y][x] == 'E')
		mlx_put_image_to_window(data->mlx, data->win,
			data->exit[0], (x * 64), (y * 64));
	s++;
}

int	contradict(void)
{
	static int	i;

	if (i == 0)
		i++;
	else
		i = 0;
	return (i);
}

void	unknown_handler(t_types *types, char c)
{
	if (c != '0' && c != '1' && c != 'P' && c != 'E' && c != 'C')
		types->unknown = -1;
}

int	rand_gen(int min, int max, unsigned int seed)
{
	unsigned int	range;
	unsigned int	r_num;

	if (min > max)
		return (0);
	min++;
	range = max - min + 1;
	r_num = next_random(seed) % range;
	return ((int)(r_num + min));
}
