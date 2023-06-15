/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:23:12 by bbento-e          #+#    #+#             */
/*   Updated: 2023/06/15 15:37:37 by bbento-e         ###   ########.fr       */
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
	int		collected;
	int		moves;
	void	*wall;
	void	*exit;
	void	*floor;
	void	*cotton;
	void	*playerup;
	void	*playerdn;
	char	**map;
	char	**copy;
}			t_data;

typedef struct s_types
{
	int		player;
	int		enemy;
	int		floor;
	int		exit;
	int		wall;
	int		clct;

}			t_types;

// ----------- ERRORS ----------- //
void	err_handler(void);
int		err_picker(char type);
int		int_err_handler(int n);

// ----------- CHECKS ----------- //
int		verify(t_data *mlx, char *str);

// ----------- VERIFS ----------- //
int		finder(t_data *data);
int		count(t_data *data, t_types *types);

// ----------- UTILS -----------  //
void	initialize(t_data *data);
void	free_2d(char **array, int size);
void	get_y(t_data *data, char *path);
int		get_x(t_data *data, char *path, int y);

// ----------- TEMP -----------  //
void	ft_print_array(char **array);

#endif
