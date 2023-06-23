/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:05:18 by bbento-e          #+#    #+#             */
/*   Updated: 2023/06/23 13:25:45 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	img_init(t_data *data)
{
	data->floor = mlx_xpm_file_to_image(data->mlx,
										FLOOR, &data->width, &data->height);
	data->clct = malloc(sizeof(void *) * 2);
	data->clct[0] = mlx_xpm_file_to_image(data->mlx,
										  COLL0, &data->width, &data->height);
	data->clct[1] = mlx_xpm_file_to_image(data->mlx,
										  COLL1, &data->width, &data->height);
	wall_init(data);
	exit_init(data);
	player_init_ud(data);
}

void	wall_init(t_data *data)
{
	data->wall = malloc(sizeof(void *) * 10);
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

void	exit_init(t_data *data)
{
	data->exit = malloc(sizeof(void *) * 5);
	data->exit[0] = mlx_xpm_file_to_image(data->mlx,
										  EXIT0, &data->width, &data->height);
	data->exit[1] = mlx_xpm_file_to_image(data->mlx,
										  EXIT1, &data->width, &data->height);
	data->exit[2] = mlx_xpm_file_to_image(data->mlx,
										  EXIT2, &data->width, &data->height);
	data->exit[3] = mlx_xpm_file_to_image(data->mlx,
										  EXIT3, &data->width, &data->height);
	data->exit[4] = mlx_xpm_file_to_image(data->mlx,
										  EXIT4, &data->width, &data->height);
}

void	player_init_ud(t_data *data)
{
	data->playeru = malloc(sizeof(void *) * 5);
	data->playerd = malloc(sizeof(void *) * 5);

	data->playeru[0] = mlx_xpm_file_to_image(data->mlx,
											 PLRU0, &data->width, &data->height);
	data->playeru[1] = mlx_xpm_file_to_image(data->mlx,
											 PLRU1, &data->width, &data->height);
	data->playeru[2] = mlx_xpm_file_to_image(data->mlx,
											 PLRU2, &data->width, &data->height);
	data->playeru[3] = mlx_xpm_file_to_image(data->mlx,
											 PLRU3, &data->width, &data->height);
	data->playeru[4] = mlx_xpm_file_to_image(data->mlx,
											 PLRU4, &data->width, &data->height);

	data->playerd[0] = mlx_xpm_file_to_image(data->mlx,
											 PLRU0, &data->width, &data->height);
	data->playerd[1] = mlx_xpm_file_to_image(data->mlx,
											 PLRU0, &data->width, &data->height);
	data->playerd[2] = mlx_xpm_file_to_image(data->mlx,
											 PLRU0, &data->width, &data->height);
	data->playerd[3] = mlx_xpm_file_to_image(data->mlx,
											 PLRU0, &data->width, &data->height);
	data->playerd[4] = mlx_xpm_file_to_image(data->mlx,
											 PLRU0, &data->width, &data->height);
}

void	player_init_lr(t_data *data)
{
	data->playerl = malloc(sizeof(void *) * 5);
	data->playerr = malloc(sizeof(void *) * 5);


}
