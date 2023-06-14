/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:23:12 by bbento-e          #+#    #+#             */
/*   Updated: 2023/06/14 18:37:25 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "minilibx-linux/mlx.h"
# include "libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <signal.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		fd;
	int		x;
	int		y;
	void	*wall;
	void	*exit;
	void	*floor;
	void	*cotton;
	void	*playerup;
	void	*playerdn;
	char	**map;
	char	**copy;
	int		collected;
	int		moves;
}			t_data;

// ----------- ERRORS ----------- //
void	err_handler(void);
int		err_picker(char type);
int		int_err_handler(int n);

// ----------- CHECKS ----------- //
int		verify(t_data *mlx, char *str);

// ----------- VERIFS ----------- //

// ----------- UTILS -----------  //
int		get_lines(t_data *data, char *path);
void	free_2d(char **array, int size);

#endif
