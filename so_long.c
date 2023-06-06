/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:39:52 by bbento-e          #+#    #+#             */
/*   Updated: 2023/06/06 20:11:39 by bbento-e         ###   ########.fr       */
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
	{
		mlx_destroy_window(mlx->mlx, mlx->win);
		mlx_destroy_display(mlx->mlx);
	}

	ft_printf("Keypress: %d\n", keysym);
	return (0);
}

int	handle_keyrelease(int keysym, void *mlx)
{
	(void)mlx;
	ft_printf("Keyrelease: %d\n", keysym);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_data	mlx;

	(void) argv;
	if (argc != 2)
		return (int_err_handler(0));
	mlx.mlx = mlx_init();
	mlx.win = mlx_new_window(mlx.mlx, 500, 500, "so_long");
	mlx_loop_hook(mlx.mlx, &nullevent, &mlx);
	mlx_key_hook(mlx.mlx, &keyhandler, &mlx);
	mlx_loop(mlx.mlx);
	/*mlx_clear_window(mlx.mlx, mlx.win);
	mlx_destroy_display(mlx.mlx);
	free(mlx.mlx);*/
	return (0);
}
