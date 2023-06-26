/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:23:27 by bbento-e          #+#    #+#             */
/*   Updated: 2023/06/26 19:53:46 by bbento-e         ###   ########.fr       */
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
	if (data->picked == data->topick)
		exit_sprite(data);
	return (0);
}

int	key_handler(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		end(data);
	return (0);
}

int	end(t_data *data)
{
	mlx_destroy_image(data, data->floor);
	mlx_destroy_image(data, data->wall[0]);
	mlx_destroy_image(data, data->wall[1]);
	mlx_destroy_image(data, data->wall[2]);
	mlx_destroy_image(data, data->wall[3]);
	mlx_destroy_image(data, data->wall[4]);
	mlx_destroy_image(data, data->wall[5]);
	mlx_destroy_image(data, data->wall[6]);
	mlx_destroy_image(data, data->wall[7]);
	mlx_destroy_image(data, data->wall[8]);
	mlx_destroy_image(data, data->wall[9]);
	mlx_destroy_image(data, data->clct[0]);
	mlx_destroy_image(data, data->clct[1]);
	destroy_img_array(data, data->playeru);
	destroy_img_array(data, data->playerd);
	destroy_img_array(data, data->playerl);
	destroy_img_array(data, data->playerr);
	destroy_img_array(data, data->exit);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free_2d(data->map, data->y);
	free(data->mlx);
	exit(0);
}

void	destroy_img_array(t_data *data, void **array)
{
	int	i;

	i = 0;
	while (i <= 5)
	{
		mlx_destroy_image(data, array[i]);
		i++;
	}
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
				((data.y + 1) * 64), "so_long");
		builder(&data);
		mlx_loop_hook(data.mlx, &updates, &data);
		mlx_hook(data.mlx, DestroyNotify, StructureNotifyMask, &end, &data);
		mlx_key_hook(data.win, &key_handler, &data);
		mlx_loop(data.mlx);
		mlx_destroy_display(data.mlx);
		free_2d(data.map, data.y);
	}
	else
		return (int_err_handler(0));
}
