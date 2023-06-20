/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:34:20 by bbento-e          #+#    #+#             */
/*   Updated: 2023/06/19 15:16:43 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_array(t_data *data, char **array)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i <= data->y)
	{
		while (array && array[i][j] != '\0')
		{
			ft_printf("%c", array[i][j]);
			j++;
		}
		i++;
		j = 0;
		ft_printf("\n");
	}
}
