/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:23:27 by bbento-e          #+#    #+#             */
/*   Updated: 2023/06/26 17:57:24 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	updates(t_data *data)
{
	if (data->dir == 'U')
		player_sprite_u(data);
	else if (data->dir == 'D')
		player_sprite_d(data);
	else if (data->dir == 'L')
		player_sprite_l(data);
	else if (data->dir == 'R')
		player_sprite_r(data);
	exit_sprite(data);

	return (0);
}

int	keyhandler(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx, data->win);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	t_types	types;

	if (argc == 2)
	{
		if (verify(&data, &types, argv[1]) == -1)
			return (0);
		data.mlx = mlx_init();
		data.win = mlx_new_window(data.mlx, (data.x * 64),
				(data.y * 64), "so_long");
		builder(&data);
		mlx_loop_hook(data.mlx, &updates, &data);
		mlx_key_hook(data.win, &keyhandler, &data);
		mlx_loop(data.mlx);
		mlx_destroy_display(data.mlx);
		free_2d(data.map, data.y);
	}
	else
		return (int_err_handler(0));
	return (0);
}
