/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   win_info.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/07 15:54:32 by bbento-e          #+#    #+#             */
/*   Updated: 2023/07/07 18:21:29 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	txt_to_win(t_data *data)
{
	char	*str;
	char	*picked;
	char	*topick;

	str = ft_itoa(data->moves);
	picked = ft_itoa(data->picked);
	topick = ft_itoa(data->topick);
	img_picker(data, 0, 0);
	img_picker(data, 1, 0);
	mlx_string_put(data->mlx, data->win, 15, 15, 0xFFFFFF, "Moves: ");
	mlx_string_put(data->mlx, data->win, 60, 15, 0xFFFFFF, str);
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