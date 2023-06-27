/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/27 17:13:48 by bbento-e          #+#    #+#             */
/*   Updated: 2023/06/27 19:59:59 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mvmnt(t_data *data, int key)
{
	if (key == XK_w && valid_mvmnt(data, data->px, data->py - 1))
	{
		data->dir = 'U';
		data->map[data->py][data->px] = '0';
		mlx_put_image_to_window(data->mlx, data->win,
			data->floor, (data->px * 64), (data->py * 64));
		data->py--;
		data->map[data->py][data->px] = 'P';
	}
	else if (key == XK_a && valid_mvmnt(data, data->px - 1, data->py))
	{
		data->dir = 'L';
		data->map[data->py][data->px] = '0';
		mlx_put_image_to_window(data->mlx, data->win,
			data->floor, (data->px * 64), (data->py * 64));
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
		data->dir = 'R';
		data->map[data->py][data->px] = '0';
		mlx_put_image_to_window(data->mlx, data->win,
			data->floor, (data->px * 64), (data->py * 64));
		data->px++;
		data->map[data->py][data->px] = 'P';
	}
	else if (key == XK_s && valid_mvmnt(data, data->px, data->py + 1))
	{
		data->dir = 'D';
		data->map[data->py][data->px] = '0';
		mlx_put_image_to_window(data->mlx, data->win,
			data->floor, (data->px * 64), (data->py * 64));
		data->py++;
		data->map[data->py][data->px] = 'P';
	}
}

int	valid_mvmnt(t_data *data, int x, int y)
{
	if (data->map[y][x] == 'E' || data->map[y][x] == '1')
		return (0);
	data->moves++;
	smoothen(data, x, y);
	if (data->map[y][x] == 'C' && data->picked != data->topick)
	{
		smoothen(data, x, y);
		data->picked++;
		data->map[y][x] = '0';
		smoothen(data, x, y);
		if (data->picked == data->topick)
			data->map[data->ey][data->ex] = 'e';
	}
	else if (data->map[y][x] == 'e')
	{
		smoothen(data, x, y);
		ft_printf("Congratulations! Map completed!");
		end(data);
	}
	return (1);
}

void	smoothen(t_data *data, int x, int y)
{
	if (data->dir == 'U')
		mlx_put_image_to_window(data->mlx, data->win,
			data->playeru[0], (x * 64), (y * 64));
	else if (data->dir == 'D')
		mlx_put_image_to_window(data->mlx, data->win,
			data->playerd[0], (x * 64), (y * 64));
	else if (data->dir == 'L')
		mlx_put_image_to_window(data->mlx, data->win,
			data->playerl[0], (x * 64), (y * 64));
	else if (data->dir == 'R')
		mlx_put_image_to_window(data->mlx, data->win,
			data->playerr[0], (x * 64), (y * 64));
}