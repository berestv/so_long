/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:23:32 by bbento-e          #+#    #+#             */
/*   Updated: 2023/06/15 15:55:52 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	get_y(t_data *data, char *path)
{
	char	*line;

	initialize(data);
	data->fd = open(path, O_RDONLY);
	while (1)
	{
		line = get_next_line(data->fd);
		if (!line)
			break ;
		data->y++;
		free(line);
	}
	close(data->fd);
	free(line);
}

int	get_x(t_data *data, char *path, int y)
{
	int	len;

	data->fd = open(path, O_RDONLY);
	data->x = (int)ft_strlen(get_next_line(data->fd));
	close(data->fd);
	data->map = malloc((sizeof(char) * data->x) * data->y);
	open(path, O_RDONLY);
	while (y <= data->y)
	{
		data->map[y] = ft_strtrim(get_next_line(data->fd), "\n");
		if (!data->map[y])
			break ;
		len = (int)ft_strlen(data->map[y]);
		if (data->x != len || data->x <= 0)
			return (-1);
		y++;
	}
	ft_print_array(data->map);
	return (close(data->fd));
}

void	initialize(t_data *data)
{
	data->fd = 0;
	data->x = -1;
	data->y = -1;
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
