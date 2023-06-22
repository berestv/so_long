/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/21 16:35:23 by bbento-e          #+#    #+#             */
/*   Updated: 2023/06/22 19:09:33 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	builder(t_data *data)
{
	img_init(data);
	populate(data);
}

void	img_init(t_data *data)
{
	data->floor = mlx_xpm_file_to_image(data->mlx,
			FLOOR, &data->width, &data->height);
	data->playerup = mlx_xpm_file_to_image(data->mlx,
			PLYR0, &data->width, &data->height);
	data->clct = malloc(sizeof(void *) * 2);
	data->clct[0] = mlx_xpm_file_to_image(data->mlx,
			CLCT0, &data->width, &data->height);
	data->clct[1] = mlx_xpm_file_to_image(data->mlx,
			CLCT1, &data->width, &data->height);
	data->wall = malloc(sizeof(void *) * 10);
	wall_init(data);
}

void	wall_init(t_data *data)
{
	data->wall[0] = mlx_xpm_file_to_image(data->mlx,
			WALL0, &data->width, &data->height);
	data->wall[1] = mlx_xpm_file_to_image(data->mlx,
			WALL1, &data->width, &data->height);
	data->wall[2] = mlx_xpm_file_to_image(data->mlx,
			WALL2, &data->width, &data->height);
	data->wall[3] = mlx_xpm_file_to_image(data->mlx,
			WALL3, &data->width, &data->height);
	data->wall[4] = mlx_xpm_file_to_image(data->mlx,
			WALL4, &data->width, &data->height);
	data->wall[5] = mlx_xpm_file_to_image(data->mlx,
			WALL5, &data->width, &data->height);
	data->wall[6] = mlx_xpm_file_to_image(data->mlx,
			WALL6, &data->width, &data->height);
	data->wall[7] = mlx_xpm_file_to_image(data->mlx,
			WALL7, &data->width, &data->height);
	data->wall[8] = mlx_xpm_file_to_image(data->mlx,
			WALL8, &data->width, &data->height);
	data->wall[9] = mlx_xpm_file_to_image(data->mlx,
			WALL9, &data->width, &data->height);
}

void	populate(t_data *data)
{
	int	x;
	int	y;
	int	r;
	int	s;

	y = 0;
	s = next_random(data->x * data->y);
	while (y < data->y)
	{
		x = 0;
		while (x < data->x)
		{
			s++;
			r = rand_gen(0, 9, s);
			if (data->map[y][x] == '0')
				mlx_put_image_to_window(data->mlx, data->win,
					data->floor, (x * 64), (y * 64));
			if (data->map[y][x] == '1')
				mlx_put_image_to_window(data->mlx, data->win,
					data->wall[r], (x * 64), (y * 64));
			if (data->map[y][x] == 'P')
				mlx_put_image_to_window(data->mlx, data->win,
					data->playerup, (x * 64), (y * 64));
			if (data->map[y][x] == 'C')
				mlx_put_image_to_window(data->mlx, data->win,
					data->clct[0], (x * 64), (y * 64));
			x++;
		}
		y++;
	}
}

/*void	img_picker(t_data *data, int x, int y)
{

}*/
