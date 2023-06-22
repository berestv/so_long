/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:23:32 by bbento-e          #+#    #+#             */
/*   Updated: 2023/06/22 11:56:28 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_y(t_data *data, char *path)
{
	char	*line;

	initialize(data);
	data->fd = open(path, O_RDONLY);
	data->x = ft_strlen(ft_strtrim(get_next_line(data->fd), "\n"));
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
	close(data->fd);
	free(line);
}

int	get_x(t_data *data, char *path, int y)
{
	int	len;

	len = data->x;
	data->map = malloc((sizeof(char) * data->x) * data->y);
	data->fd = open(path, O_RDONLY);
	while (y <= data->y)
	{
		data->map[y] = ft_strtrim(get_next_line(data->fd), "\n");
		len = ft_strlen(data->map[y]);
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
	data->width = 64;
	data->height = 64;
	data->collected = 0;
	data->moves = 0;
}

void	free_2d(char **array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		free(array[i]);
		i++;
	}
	free(array);
}
