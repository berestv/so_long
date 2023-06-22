/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/14 17:23:12 by bbento-e          #+#    #+#             */
/*   Updated: 2023/06/22 18:59:21 by bbento-e         ###   ########.fr       */
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
	int		py;
	int		px;
	int		collected;
	int		moves;
	int		width;
	int		height;
	void	**wall;
	void	*exit;
	void	*floor;
	void	**clct;
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
	int		exitcheck;
	int		wall;
	int		clct;
	int		clctcheck;
	int		trigger;

}			t_types;

// ----------- ERRORS ----------- //
void	err_handler(void);
int		err_picker(char type);
int		int_err_handler(int n);

// ----------- CHECKS ----------- //
int		verify(t_data *mlx, char *str);

// ----------- VERIFS ----------- //
int		count(t_types *types);
int		finder(t_types *types, t_data *data);

// ------------ MAP ------------- //
void	builder(t_data *data);
void	populate(t_data *data);
void	img_init(t_data *data);
void	wall_init(t_data *data);
void	img_picker(t_data *data, int x, int y);

// ----------- UTILS -----------  //
void	type0(t_types *types);
void	initialize(t_data *data);
void	free_2d(char **array, int size);
void	get_y(t_data *data, char *path);
int		get_x(t_data *data, char *path, int y);
int		next_random(unsigned int seed);
int		rand_gen(int min, int max, unsigned int seed);
void	pathcheck(t_types *types, t_data *data, int x, int y);
void	wall_handler(t_types *types, t_data *data, int x, int y);
void	player_handler(t_types *types, t_data *data, int x, int y);

// ----------- TEMP -----------  //
void	ft_print_array(t_data *data, char **array);

// ----------------- MACROS ----------------- //
# define FLOOR "./img/textures/floor.xpm"

// ------------ WALLS ------------ //
# define WALL0 "./img/textures/wall0.xpm"
# define WALL1 "./img/textures/wall1.xpm"
# define WALL2 "./img/textures/wall2.xpm"
# define WALL3 "./img/textures/wall3.xpm"
# define WALL4 "./img/textures/wall4.xpm"
# define WALL5 "./img/textures/wall5.xpm"
# define WALL6 "./img/textures/wall6.xpm"
# define WALL7 "./img/textures/wall7.xpm"
# define WALL8 "./img/textures/wall8.xpm"
# define WALL9 "./img/textures/wall9.xpm"

// ----------- PLAYER ----------- //
# define PLYR0 "./img/sprites/spaceship0.xpm"
# define PLYR1 "./img/sprites/spaceship1.xpm"
# define PLYR2 "./img/sprites/spaceship2.xpm"
# define PLYR3 "./img/sprites/spaceship3.xpm"
# define PLYR4 "./img/sprites/spaceship4.xpm"

// ---------- COLLECT ---------- //
# define CLCT0 "./img/textures/clct.xpm"
# define CLCT1 "./img/textures/clct_flip.xpm"

#endif
