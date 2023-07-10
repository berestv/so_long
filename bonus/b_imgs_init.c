/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:05:18 by bbento-e          #+#    #+#             */
/*   Updated: 2023/07/10 15:22:16 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	img_init(t_data *data)
{
	data->clct = malloc(sizeof(void *) * 2);
	data->clct[0] = mlx_xpm_file_to_image(data->mlx,
			COLL0, &data->width, &data->height);
	data->clct[1] = mlx_xpm_file_to_image(data->mlx,
			COLL1, &data->width, &data->height);
	data->windows = malloc(sizeof(void *) * 4);
	data->windows[0] = mlx_xpm_file_to_image(data->mlx,
			MOVES, &data->width, &data->height);
	data->windows[1] = mlx_xpm_file_to_image(data->mlx,
			COLBG, &data->width, &data->height);
	data->windows[2] = mlx_xpm_file_to_image(data->mlx,
			EXTCL, &data->width, &data->height);
	data->windows[3] = mlx_xpm_file_to_image(data->mlx,
			EXTOP, &data->width, &data->height);
	wall_init(data);
	data->astr[5] = mlx_xpm_file_to_image(data->mlx,
			BOOM0, &data->width, &data->height);
	data->astr[6] = mlx_xpm_file_to_image(data->mlx,
			BOOM1, &data->width, &data->height);
	data->astr[7] = mlx_xpm_file_to_image(data->mlx,
			BOOM2, &data->width, &data->height);
	data->astr[8] = mlx_xpm_file_to_image(data->mlx,
			BOOM3, &data->width, &data->height);
	data->astr[9] = mlx_xpm_file_to_image(data->mlx,
			BOOM4, &data->width, &data->height);
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
	data->floor = mlx_xpm_file_to_image(data->mlx,
			FLOOR, &data->width, &data->height);
	exit_init(data);
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
	data->astr = malloc(sizeof(void *) * 10);
	data->astr[0] = mlx_xpm_file_to_image(data->mlx,
			ASTR0, &data->width, &data->height);
	data->astr[1] = mlx_xpm_file_to_image(data->mlx,
			ASTR1, &data->width, &data->height);
	data->astr[2] = mlx_xpm_file_to_image(data->mlx,
			ASTR2, &data->width, &data->height);
	data->astr[3] = mlx_xpm_file_to_image(data->mlx,
			ASTR3, &data->width, &data->height);
	data->astr[4] = mlx_xpm_file_to_image(data->mlx,
			ASTR4, &data->width, &data->height);
	player_init_ud(data);
	player_init_lr(data);
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
			PLRD0, &data->width, &data->height);
	data->playerd[1] = mlx_xpm_file_to_image(data->mlx,
			PLRD1, &data->width, &data->height);
	data->playerd[2] = mlx_xpm_file_to_image(data->mlx,
			PLRD2, &data->width, &data->height);
	data->playerd[3] = mlx_xpm_file_to_image(data->mlx,
			PLRD3, &data->width, &data->height);
	data->playerd[4] = mlx_xpm_file_to_image(data->mlx,
			PLRD4, &data->width, &data->height);
}

void	player_init_lr(t_data *data)
{
	data->playerl = malloc(sizeof(void *) * 5);
	data->playerr = malloc(sizeof(void *) * 5);
	data->playerl[0] = mlx_xpm_file_to_image(data->mlx,
			PLRL0, &data->width, &data->height);
	data->playerl[1] = mlx_xpm_file_to_image(data->mlx,
			PLRL1, &data->width, &data->height);
	data->playerl[2] = mlx_xpm_file_to_image(data->mlx,
			PLRL2, &data->width, &data->height);
	data->playerl[3] = mlx_xpm_file_to_image(data->mlx,
			PLRL3, &data->width, &data->height);
	data->playerl[4] = mlx_xpm_file_to_image(data->mlx,
			PLRL4, &data->width, &data->height);
	data->playerr[0] = mlx_xpm_file_to_image(data->mlx,
			PLRR0, &data->width, &data->height);
	data->playerr[1] = mlx_xpm_file_to_image(data->mlx,
			PLRR1, &data->width, &data->height);
	data->playerr[2] = mlx_xpm_file_to_image(data->mlx,
			PLRR2, &data->width, &data->height);
	data->playerr[3] = mlx_xpm_file_to_image(data->mlx,
			PLRR3, &data->width, &data->height);
	data->playerr[4] = mlx_xpm_file_to_image(data->mlx,
			PLRR4, &data->width, &data->height);
}
