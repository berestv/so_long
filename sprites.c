/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_ops.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/23 13:09:58 by bbento-e          #+#    #+#             */
/*   Updated: 2023/06/23 13:12:37 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_sprite(t_data *data)
{
	static int	i;

	data->playerup = mlx_xpm_file_to_image(data->mlx,
										   PLYR0, &data->width, &data->height);
}

void	exit_sprite(t_data *data)
{
	static int	i;

	data->playerup = mlx_xpm_file_to_image(data->mlx,
										   PLYR0, &data->width, &data->height);
}