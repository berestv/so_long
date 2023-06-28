/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:23:32 by bbento-e          #+#    #+#             */
/*   Updated: 2023/06/28 14:59:33 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_y(t_data *data, char *path)
{
	char	*line;
	char	*temp;
	char	*trim;

	initialize(data);
	data->fd = open(path, O_RDONLY);
	temp = get_next_line(data->fd);
	trim = ft_strtrim(temp, "\n");
	data->x = (int)ft_strlen(trim);
	free(temp);
	free(trim);
	close(data->fd);
	data->fd = open(path, O_RDONLY);
	while (1)
	{
		line = get_next_line(data->fd);
		if (!line)
			break ;
		data->y++;
		free(line);
	}
	data->y--;
	free(line);
	close(data->fd);
}

int	get_x(t_data *data, char *path, int y)
{
	int		len;
	char	*temp;

	data->map = malloc((sizeof(char *) * data->x) * data->y);
	data->fd = open(path, O_RDONLY);
	while (y <= data->y)
	{
		temp = get_next_line(data->fd);
		data->map[y] = ft_strtrim(temp, "\n");
		free(temp);
		len = (int)ft_strlen(data->map[y]);
		if (!data->map[y])
			break ;
		if (data->x != len || data->x <= 0)
			return (-1);
		y++;
	}
	return (close(data->fd));
}

void	initialize(t_data *data)
{
	data->fd = 0;
	data->x = 0;
	data->y = 0;
	data->px = 0;
	data->py = 0;
	data->ex = 0;
	data->ey = 0;
	data->width = 64;
	data->height = 64;
	data->picked = 0;
	data->topick = 0;
	data->moves = 0;
	data->clct = malloc(sizeof(void *) * 2);
	data->exit = malloc(sizeof(void *) * 5);
	data->wall = malloc(sizeof(void *) * 10);
	data->playeru = malloc(sizeof(void *) * 5);
	data->playerd = malloc(sizeof(void *) * 5);
	data->playerl = malloc(sizeof(void *) * 5);
	data->playerr = malloc(sizeof(void *) * 5);
	data->dir = 'U';
}

void	type0(t_types *types)
{
	types->player = 0;
	types->exit = 0;
	types->exitcheck = 0;
	types->exit_trigg = 0;
	types->wall = 0;
	types->clct = 0;
	types->clctcheck = 0;
	types->trigger = 0;
	types->unknown = 0;
}

int	free_2d(char **array, int size)
{
	int	i;

	i = 0;
	if (!array)
		return (-1);
	while (i <= size)
	{
		free(array[i]);
		i++;
	}
	free(array);
	return (0);
}
