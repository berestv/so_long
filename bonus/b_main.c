/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:23:27 by bbento-e          #+#    #+#             */
/*   Updated: 2023/07/07 17:52:11 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	end(t_data *data)
{
	free_2d(data->map, data->y);
	mlx_destroy_image(data->mlx, data->floor);
	mlx_destroy_image(data->mlx, data->wall[0]);
	mlx_destroy_image(data->mlx, data->wall[1]);
	mlx_destroy_image(data->mlx, data->wall[2]);
	mlx_destroy_image(data->mlx, data->wall[3]);
	mlx_destroy_image(data->mlx, data->wall[4]);
	mlx_destroy_image(data->mlx, data->wall[5]);
	mlx_destroy_image(data->mlx, data->wall[6]);
	mlx_destroy_image(data->mlx, data->wall[7]);
	mlx_destroy_image(data->mlx, data->wall[8]);
	mlx_destroy_image(data->mlx, data->wall[9]);
	mlx_destroy_image(data->mlx, data->clct[0]);
	mlx_destroy_image(data->mlx, data->clct[1]);
	mlx_destroy_image(data->mlx, data->exit[0]);
	mlx_destroy_image(data->mlx, data->exit[1]);
	mlx_destroy_image(data->mlx, data->exit[2]);
	mlx_destroy_image(data->mlx, data->exit[3]);
	mlx_destroy_image(data->mlx, data->exit[4]);
	destroy_img_array(data);
	mlx_destroy_window(data->mlx, data->win);
	mlx_destroy_display(data->mlx);
	free(data->mlx);
	free_dp(data);
	exit(0);
}

void	destroy_img_array(t_data *data)
{
	mlx_destroy_image(data->mlx, data->playeru[0]);
	mlx_destroy_image(data->mlx, data->playeru[1]);
	mlx_destroy_image(data->mlx, data->playeru[2]);
	mlx_destroy_image(data->mlx, data->playeru[3]);
	mlx_destroy_image(data->mlx, data->playeru[4]);
	mlx_destroy_image(data->mlx, data->playerd[0]);
	mlx_destroy_image(data->mlx, data->playerd[1]);
	mlx_destroy_image(data->mlx, data->playerd[2]);
	mlx_destroy_image(data->mlx, data->playerd[3]);
	mlx_destroy_image(data->mlx, data->playerd[4]);
	mlx_destroy_image(data->mlx, data->playerl[0]);
	mlx_destroy_image(data->mlx, data->playerl[1]);
	mlx_destroy_image(data->mlx, data->playerl[2]);
	mlx_destroy_image(data->mlx, data->playerl[3]);
	mlx_destroy_image(data->mlx, data->playerl[4]);
	mlx_destroy_image(data->mlx, data->playerr[0]);
	mlx_destroy_image(data->mlx, data->playerr[1]);
	mlx_destroy_image(data->mlx, data->playerr[2]);
	mlx_destroy_image(data->mlx, data->playerr[3]);
	mlx_destroy_image(data->mlx, data->playerr[4]);
	astroy_destroy(data);
}

void	astroy_destroy(t_data *data)
{
	mlx_destroy_image(data->mlx, data->astr[0]);
	mlx_destroy_image(data->mlx, data->astr[1]);
	mlx_destroy_image(data->mlx, data->astr[2]);
	mlx_destroy_image(data->mlx, data->astr[3]);
	mlx_destroy_image(data->mlx, data->astr[4]);
	mlx_destroy_image(data->mlx, data->astr[5]);
	mlx_destroy_image(data->mlx, data->astr[6]);
	mlx_destroy_image(data->mlx, data->astr[7]);
	mlx_destroy_image(data->mlx, data->astr[8]);
	mlx_destroy_image(data->mlx, data->astr[9]);
}

void	free_dp(t_data *data)
{
	free(data->wall);
	free(data->clct);
	free(data->exit);
	free(data->astr);
	free(data->playerd);
	free(data->playeru);
	free(data->playerl);
	free(data->playerr);
}

int	main(int argc, char *argv[])
{
	t_data	data;
	t_types	types;

	if (argc == 2)
	{
		if (verify(&data, &types, argv[1]) == -1)
		{
			free_2d(data.map, data.y);
			return (0);
		}
		data.mlx = mlx_init();
		data.win = mlx_new_window(data.mlx, (data.x * 64),
				((data.y + 1) * 64), "so_long");
		populate(&data);
		txt_to_win(&data);
		mlx_hook(data.win, DestroyNotify, StructureNotifyMask, &end, &data);
		mlx_key_hook(data.win, &key_handler, &data);
		mlx_loop_hook(data.mlx, &updates, &data);
		mlx_loop(data.mlx);
		end(&data);
	}
	return (int_err_handler(0));
}
