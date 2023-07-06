/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   asteroid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 17:19:50 by bbento-e          #+#    #+#             */
/*   Updated: 2023/07/06 19:40:54 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	asteroid(t_data *data)
{
	static int	i;

	srand(time((0)));
	if (i == data->r)
	{
		data->fd = 1;
		i = 0;
		data->r = (rand() % (750000 + 1 - 0) + 0);
		return (1);
	}
	i++;
	return (0);
}

void	execute_order66(t_data *data)
{
	static int	i;

	srand(time((0)));
	if (i == 0)
		mlx_put_image_to_window(data->mlx, data->win,
			data->astr[0], (data->ax * 64), (data->ay * 64));
	else if (i == 1500)
		mlx_put_image_to_window(data->mlx, data->win,
			data->astr[1], (data->ax * 64), (data->ay * 64));
	else if (i == 3000)
		mlx_put_image_to_window(data->mlx, data->win,
			data->astr[2], (data->ax * 64), (data->ay * 64));
	continue_order66(data, i);
	if (i == 6000)
		i = 0;
	i++;
}

void	continue_order66(t_data *data, int i)
{
	srand(time((0)));
	if (i == 4500)
		mlx_put_image_to_window(data->mlx, data->win,
			data->astr[3], (data->ax * 64), (data->ay * 64));
	else if (i == 6000)
	{
		mlx_put_image_to_window(data->mlx, data->win,
			data->astr[4], (data->ax * 64), (data->ay * 64));
		img_picker(data, data->ax, data->ay);
		data->ax--;
		mlx_put_image_to_window(data->mlx, data->win,
			data->astr[0], (data->ax * 64), (data->ay * 64));
	}
	if (data->ax == 0 || (data->map[data->ay][data->ax] != '0'
		&& data->map[data->ay][data->ax] != 'C'
		&& data->map[data->ay][data->ax] != 'P'))
	{
		explode(data);
		data->ax = data->x - 2;
		data->ay = (rand() % ((data->y - 2) + 1 - 0) + 1);
		data->fd = 0;
		img_picker(data, data->ax, data->ay);
	}
}

void	explode(t_data *data)
{
	clock_t start_time = clock();
	clock_t current_time;

	// Display the first image
	mlx_put_image_to_window(data->mlx, data->win,
							data->astr[5], (data->ax * 64), (data->ay * 64));

	// Wait for 500 milliseconds (0.5 seconds)
	while (((double)(current_time = clock() - start_time) / CLOCKS_PER_SEC) < 0.5);

	// Display the second image
	mlx_put_image_to_window(data->mlx, data->win,
							data->astr[6], (data->ax * 64), (data->ay * 64));

	// Wait for 500 milliseconds (0.5 seconds)
	start_time = clock();
	while (((double)(current_time = clock() - start_time) / CLOCKS_PER_SEC) < 0.5);

	// Repeat the same process for the remaining images...

	// Display the third image
	mlx_put_image_to_window(data->mlx, data->win,
							data->astr[7], (data->ax * 64), (data->ay * 64));

	// Wait for 500 milliseconds (0.5 seconds)
	start_time = clock();
	while (((double)(current_time = clock() - start_time) / CLOCKS_PER_SEC) < 0.5);

	// Display the fourth image
	mlx_put_image_to_window(data->mlx, data->win,
							data->astr[8], (data->ax * 64), (data->ay * 64));

	// Wait for 500 milliseconds (0.5 seconds)
	start_time = clock();
	while (((double)(current_time = clock() - start_time) / CLOCKS_PER_SEC) < 0.5);

	// Display the fifth image
	mlx_put_image_to_window(data->mlx, data->win,
							data->astr[9], (data->ax * 64), (data->ay * 64));

	// Call the img_picker function
	img_picker(data, data->ax, data->ay);
}
