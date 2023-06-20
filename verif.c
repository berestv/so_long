/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:23:05 by bbento-e          #+#    #+#             */
/*   Updated: 2023/06/20 17:21:18 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verify(t_data *data, char *str)
{
	int		i;
	t_types	types;

	type0(&types);
	(void)data;
	i = (int)ft_strlen(str) - 4;
	if (ft_strncmp(str + i, ".ber", 4) != 0 || !str)
		return (err_picker('f'));
	i = open(str, O_RDONLY);
	if (i < 0)
		return (err_picker('/'));
	close(i);
	get_y(data, str);
	if (get_x(data, str, 0) == -1)
		return (err_picker('r'));
	if (finder(&types, data) == -1)
		return (-1);
	pathcheck(&types, data, data->px, data->py);

	return (0);
}

void	type0(t_types *types)
{
	types->player = 0;
	types->enemy = 0;
	types->floor = 0;
	types->exit = 0;
	types->exitcheck = 0;
	types->wall = 0;
	types->clct = 0;
	types->clctcheck = 0;
}

int	finder(t_types *types, t_data *data)
{
	int		ix;
	int		iy;

	iy = 0;
	while (iy <= data->y)
	{
		ix = 0;
		while (ix <= data->x)
		{
			if (data->map[iy][ix] == '1')
				types->wall++;
			else if (data->map[iy][ix] == 'C')
				types->clct++;
			else if (data->map[iy][ix] == 'E')
				types->exit++;
			else if (data->map[iy][ix] == 'P')
				types->player++;
			ix++;
		}
		iy++;
	}
	return (count(data, types));
}

int	count(t_data *data, t_types *types)
{
	if (types->player != 1)
		return (err_picker('p'));
	if (types->exit != 1)
		return (err_picker('e'));
	if (types->clct < 1)
		return (err_picker('c'));
	if (types->wall < ((2 * data->x) + (2 * data->y)))
		return (err_picker('w'));
	if (types->)
	return (0);
}

void	pathcheck(t_types *types, t_data *data, int x, int y)
{
	if (data->map[y][x] == '1' || data->map[y][x] == '-' || !data->map[y][x])
		return ;
	else
	{
		if (data->map[y][x] == 'E')
			types->exitcheck++;
		if (data->map[y][x] == 'C')
			types->clctcheck++;
	}
	pathcheck(types, data, x + 1, y);
	pathcheck(types, data, x, y + 1);
	pathcheck(types, data, x - 1, y);
	pathcheck(types, data, x, y - 1);
}
