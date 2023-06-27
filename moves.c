/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:13:48 by bbento-e          #+#    #+#             */
/*   Updated: 2023/06/27 18:17:21 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mvmnt(t_data *data, int key)
{
	if (key == XK_w && valid_mvmnt(data, data->px, data->py - 1))
	{
		data->map[data->py][data->px] = '0';
		mlx_put_image_to_window(data->mlx, data->win,
			data->floor, data->px, data->py);
		data->py--;
		data->map[data->py][data->px] = 'P';
	}
	else if (key == XK_a && valid_mvmnt(data, data->px - 1, data->py))
	{
		data->map[data->py][data->px] = '0';
		mlx_put_image_to_window(data->mlx, data->win,
			data->floor, data->px, data->py);
		data->px--;
		data->map[data->py][data->px] = 'P';
	}
	else
		mvmnt2(data, key);
}

void	mvmnt2(t_data *data, int key)
{
	if (key == XK_d && valid_mvmnt(data, data->px + 1, data->py))
	{
		data->map[data->py][data->px] = '0';
		mlx_put_image_to_window(data->mlx, data->win,
			data->floor, data->px, data->py);
		data->py++;
		data->map[data->py][data->px] = 'P';
	}
	else if (key == XK_s && valid_mvmnt(data, data->px, data->py + 1))
	{
		data->map[data->py][data->px] = '0';
		mlx_put_image_to_window(data->mlx, data->win,
			data->floor, data->px, data->py);
		data->py++;
		data->map[data->py][data->px] = 'P';
	}
}

int	valid_mvmnt(t_data *data, int x, int y)
{
	if (data->map[y][x] == 'E' || data->map[y][x] == '1')
		return (0);
	data->moves++;
	if (data->map[y][x] == 'C' && data->picked != data->topick)
	{
		data->picked++;
		data->map[y][x] = '0';
		mlx_put_image_to_window(data->mlx, data->win, data->floor, x, y);
		if (data->picked == data->topick)
			data->map[data->ey][data->ex] = 'e';
	}
	else if (data->map[y][x] == 'e')
	{
		ft_printf("Congratulations! Map completed!");
		end(data);
	}
	return (1);
}
