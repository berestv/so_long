/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   verif.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/13 17:28:32 by bbento-e          #+#    #+#             */
/*   Updated: 2023/06/13 19:38:32 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	verify(t_data *mlx)
{
	int	i;
	char **str;

	i = (int)ft_strlen(str) - 4;
	if (ft_strncmp(str + i, ".ber", 4) != 0)
	{
		ft_putstr_fd("Wrong map format. Use [mapname].ber\n", 2);
		return (-1);
	}

	return (0);
}
