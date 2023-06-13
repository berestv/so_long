/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:39:52 by bbento-e          #+#    #+#             */
/*   Updated: 2023/06/13 19:35:29 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	nullevent(void *data)
{
	(void)data;
	return (0);
}

int	keyhandler(int keysym, t_data *mlx)
{
	if (keysym == XK_Escape)
		mlx_destroy_window(mlx->mlx, mlx->win);
	ft_printf("Keypress: %d\n", keysym);
	return (0);
}



int	main(int argc, char *argv[])
{
	t_data	mlx;

	(void) argv;
	if (argc != 2)
		return (int_err_handler(0));
	if (ber(argv[1]) != 0 || verify(&mlx) == -1)
		return (0);
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 500, 500, "so_long");
	mlx_loop_hook(mlx.mlx, &nullevent, &mlx);
	mlx_key_hook(mlx.win, &keyhandler, &mlx);
	mlx_loop(mlx.mlx);
	mlx_destroy_display(mlx.mlx);
	free(mlx.mlx);
	return (0);
}
