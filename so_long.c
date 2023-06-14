/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:23:27 by bbento-e          #+#    #+#             */
/*   Updated: 2023/06/14 18:43:39 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	nullevent(void *data)
{
	(void)data;
	return (0);
}

int	keyhandler(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(data->mlx, data->win);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	data;

	if (argc == 2)
	{
		if (verify(&data, argv[1]) == -1)
			return (0);
		data.mlx = mlx_init();
		data.win = mlx_new_window(data.mlx, 500, 500, "so_long");
		mlx_loop_hook(data.mlx, &nullevent, &data);
		mlx_key_hook(data.win, &keyhandler, &data);
		mlx_loop(data.mlx);
		mlx_destroy_display(data.mlx);
		free(data.mlx);
		// free_2d(data.map, data.y);
	}
	else
		return (int_err_handler(0));
	return (0);
}
