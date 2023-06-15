/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/15 15:34:20 by bbento-e          #+#    #+#             */
/*   Updated: 2023/06/15 15:37:24 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_print_array(char **array)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (array[i][j] != '\0')
	{
		while (array[i][j] != '\0')
		{
			ft_printf("%c ", array[i][j]);
			j++;
		}
		i++;
		j = 0;
		ft_printf("\n");
	}
}
