/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:09:58 by bbento-e          #+#    #+#             */
/*   Updated: 2023/06/26 17:56:08 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_sprite_u(t_data *data)
{
	static int	i;

	if (i == 0)
		mlx_put_image_to_window(data->mlx, data->win,
			data->playeru[0], (data->px * 64), (data->py * 64));
	else if (i == 13000)
		mlx_put_image_to_window(data->mlx, data->win,
			data->playeru[1], (data->px * 64), (data->py * 64));
	else if (i == 26000)
		mlx_put_image_to_window(data->mlx, data->win,
			data->playeru[2], (data->px * 64), (data->py * 64));
	else if (i == 39000)
		mlx_put_image_to_window(data->mlx, data->win,
			data->playeru[3], (data->px * 64), (data->py * 64));
	else if (i == 54000)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->playeru[4], (data->px * 64), (data->py * 64));
		i = 0;
	}
	i++;
}

void	player_sprite_d(t_data *data)
{
	static int	i;

	if (i == 0)
		mlx_put_image_to_window(data->mlx, data->win,
								data->playeru[0], (data->px * 64), (data->py * 64));
	else if (i == 13000)
		mlx_put_image_to_window(data->mlx, data->win,
								data->playeru[1], (data->px * 64), (data->py * 64));
	else if (i == 26000)
		mlx_put_image_to_window(data->mlx, data->win,
								data->playeru[2], (data->px * 64), (data->py * 64));
	else if (i == 39000)
		mlx_put_image_to_window(data->mlx, data->win,
								data->playeru[3], (data->px * 64), (data->py * 64));
	else if (i == 54000)
	{
		mlx_put_image_to_window(data->mlx, data->win,
								data->playeru[4], (data->px * 64), (data->py * 64));
		i = 0;
	}
	i++;
}

void	player_sprite_l(t_data *data)
{
	static int	i;

	if (i == 0)
		mlx_put_image_to_window(data->mlx, data->win,
								data->playeru[0], (data->px * 64), (data->py * 64));
	else if (i == 13000)
		mlx_put_image_to_window(data->mlx, data->win,
								data->playeru[1], (data->px * 64), (data->py * 64));
	else if (i == 26000)
		mlx_put_image_to_window(data->mlx, data->win,
								data->playeru[2], (data->px * 64), (data->py * 64));
	else if (i == 39000)
		mlx_put_image_to_window(data->mlx, data->win,
								data->playeru[3], (data->px * 64), (data->py * 64));
	else if (i == 54000)
	{
		mlx_put_image_to_window(data->mlx, data->win,
								data->playeru[4], (data->px * 64), (data->py * 64));
		i = 0;
	}
	i++;
}

void	player_sprite_r(t_data *data)
{
	static int	i;

	if (i == 0)
		mlx_put_image_to_window(data->mlx, data->win,
								data->playeru[0], (data->px * 64), (data->py * 64));
	else if (i == 13000)
		mlx_put_image_to_window(data->mlx, data->win,
								data->playeru[1], (data->px * 64), (data->py * 64));
	else if (i == 26000)
		mlx_put_image_to_window(data->mlx, data->win,
								data->playeru[2], (data->px * 64), (data->py * 64));
	else if (i == 39000)
		mlx_put_image_to_window(data->mlx, data->win,
								data->playeru[3], (data->px * 64), (data->py * 64));
	else if (i == 54000)
	{
		mlx_put_image_to_window(data->mlx, data->win,
								data->playeru[4], (data->px * 64), (data->py * 64));
		i = 0;
	}
	i++;
}

void	exit_sprite(t_data *data)
{
	static int	i;

	if (i == 0)
		mlx_put_image_to_window(data->mlx, data->win,
			data->exit[0], (data->ex * 64), (data->ey * 64));
	else if (i == 15000)
		mlx_put_image_to_window(data->mlx, data->win,
			data->exit[1], (data->ex * 64), (data->ey * 64));
	else if (i == 30000)
		mlx_put_image_to_window(data->mlx, data->win,
			data->exit[2], (data->ex * 64), (data->ey * 64));
	else if (i == 45000)
		mlx_put_image_to_window(data->mlx, data->win,
			data->exit[3], (data->ex * 64), (data->ey * 64));
	else if (i == 60000)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->exit[4], (data->ex * 64), (data->ey * 64));
		i = 0;
	}
	i++;
}
