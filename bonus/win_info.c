/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:54:32 by bbento-e          #+#    #+#             */
/*   Updated: 2023/07/11 10:43:39 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	txt_to_win(t_data *data)
{
	char	*str;
	char	*picked;
	char	*topick;
	int		sum;

	str = ft_itoa(data->moves);
	picked = ft_itoa(data->picked);
	topick = ft_itoa(data->topick);
	sum = ft_strlen(str);
	mlx_put_image_to_window(data->mlx, data->win, data->windows[0], 0, 0);
	mlx_put_image_to_window(data->mlx, data->win, data->windows[1], 64, 0);
	if (data->picked == data->topick)
		mlx_put_image_to_window(data->mlx, data->win, data->windows[3], 128, 0);
	else
		mlx_put_image_to_window(data->mlx, data->win, data->windows[2], 128, 0);
	mlx_string_put(data->mlx, data->win, 32 - (sum * 3), 29, 0x3DC700, str);
	sum = ft_strlen(picked);
	mlx_string_put(data->mlx, data->win, 85 - (sum * 3), 34, 0xFFFFFF, picked);
	mlx_string_put(data->mlx, data->win, 104, 34, 0xFFFFFF, topick);
	free(str);
	free(picked);
	free(topick);
}

int	can_explode(t_data *data)
{
	if ((data->map[data->ay][data->ax - 1] == '1'
		|| data->map[data->ay][data->ax - 1] == 'E'
		|| data->map[data->ay][data->ax - 1] == 'P'
		|| data->map[data->ay][data->ax - 1] == 'e'))
		return (1);
	return (-1);
}
