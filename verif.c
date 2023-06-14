/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:23:05 by bbento-e          #+#    #+#             */
/*   Updated: 2023/06/14 17:23:09 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "so_long.h"

int	verify(t_data *mlx, char *str)
{
	int	i;

	i = (int)ft_strlen(str) - 4;
	if (ft_strncmp(str + i, ".ber", 4) != 0 || !str)
		return (err_picker('f'));
	mlx->fd = open(str, O_RDONLY);
	if (mlx->fd < 0)
		return (err_picker('/'));
	return (0);
}
