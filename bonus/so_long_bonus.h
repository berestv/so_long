/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/07/04 16:58:43 by bbento-e          #+#    #+#             */
/*   Updated: 2023/07/06 19:28:10 by bbento-e         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H

# include "../minilibx-linux/mlx.h"
# include "../libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <stdlib.h>
# include <signal.h>
# include <time.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		fd;
	int		r;
	int		x;
	int		y;
	int		py;
	int		px;
	int		ex;
	int		ey;
	int		ax;
	int		ay;
	int		picked;
	int		topick;
	int		moves;
	int		width;
	int		height;
	int		explode;
	void	**wall;
	void	**exit;
	void	**astr;
	void	*floor;
	void	**clct;
	void	**playeru;
	void	**playerd;
	void	**playerl;
	void	**playerr;
	char	dir;
	char	**map;
}			t_data;

typedef struct s_types
{
	int		player;
	int		exit;
	int		exitcheck;
	int		exit_trigg;
	int		wall;
	int		clct;
	int		clctcheck;
	int		trigger;
	int		unknown;
}			t_types;

// ----------- ERRORS ----------- //
int		err_picker(char type);
int		int_err_handler(int n);
int		err_pick(char type, int i);

// ----------- CHECKS ----------- //
int		count(t_types *types, t_data *data);
int		finder(t_types *types, t_data *data);
void	unknown_handler(t_types *types, char c);
int		verify(t_data *data, t_types *types, char *str);

// ------------ MAP ------------- //
int		updates(t_data *data);
void	populate(t_data *data);
void	img_init(t_data *data);
void	wall_init(t_data *data);
void	exit_init(t_data *data);
void	player_init_ud(t_data *data);
void	player_init_lr(t_data *data);
int		key_handler(int key, t_data *data);
void	img_picker(t_data *data, int x, int y);

// ------------ END ------------- //
int		end(t_data *data);
void	free_dp(t_data *data);
void	destroy_img_array(t_data *data);

// ---------- SPRITES ----------- //
void	exit_sprite(t_data *data);
void	mvmnt(t_data *data, int key);
void	player_sprite_u(t_data *data);
void	player_sprite_d(t_data *data);
void	player_sprite_l(t_data *data);
void	player_sprite_r(t_data *data);
void	mvmnt2(t_data *data, int key);
void	smoothen(t_data *data, int x, int y);
int		valid_mvmnt(t_data *data, int x, int y);

// ------------ ASTRO ----------- //
void	explode(t_data *data);
int		asteroid(t_data *data);
void	astroy_destroy(t_data *data);
void	execute_order66(t_data *data);
void	continue_order66(t_data *data, int i);

// ----------- UTILS -----------  //
int		contradict(void);
void	type0(t_types *types);
void	initialize(t_data *data);
int		next_random(unsigned int seed);
int		free_2d(char **array, int size);
void	get_y(t_data *data, char *path);
int		get_x(t_data *data, char *path, int y);
int		rand_gen(int min, int max, unsigned int seed);
void	pathcheck(t_types *types, t_data *data, int x, int y);
void	coll_check(t_types *types, t_data *data, int x, int y);
void	wall_handler(t_types *types, t_data *data, int x, int y);
void	player_handler(t_types *types, t_data *data, int x, int y);

// ----------- TEMP -----------  //
void	ft_print_array(t_data *data, char **array);

// ------------ FLOOR ------------ //
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
// UP
# define PLRU0 "./img/sprites/spaceship0U.xpm"
# define PLRU1 "./img/sprites/spaceship1U.xpm"
# define PLRU2 "./img/sprites/spaceship2U.xpm"
# define PLRU3 "./img/sprites/spaceship3U.xpm"
# define PLRU4 "./img/sprites/spaceship4U.xpm"
// DOWN
# define PLRD0 "./img/sprites/spaceship0D.xpm"
# define PLRD1 "./img/sprites/spaceship1D.xpm"
# define PLRD2 "./img/sprites/spaceship2D.xpm"
# define PLRD3 "./img/sprites/spaceship3D.xpm"
# define PLRD4 "./img/sprites/spaceship4D.xpm"
// LEFT
# define PLRL0 "./img/sprites/spaceship0L.xpm"
# define PLRL1 "./img/sprites/spaceship1L.xpm"
# define PLRL2 "./img/sprites/spaceship2L.xpm"
# define PLRL3 "./img/sprites/spaceship3L.xpm"
# define PLRL4 "./img/sprites/spaceship4L.xpm"
// RIGHT
# define PLRR0 "./img/sprites/spaceship0R.xpm"
# define PLRR1 "./img/sprites/spaceship1R.xpm"
# define PLRR2 "./img/sprites/spaceship2R.xpm"
# define PLRR3 "./img/sprites/spaceship3R.xpm"
# define PLRR4 "./img/sprites/spaceship4R.xpm"

// ----------- EXIT ------------ //
# define EXIT0 "./img/sprites/exit0.xpm"
# define EXIT1 "./img/sprites/exit1.xpm"
# define EXIT2 "./img/sprites/exit2.xpm"
# define EXIT3 "./img/sprites/exit3.xpm"
# define EXIT4 "./img/sprites/exit4.xpm"

// ----------- ASTRO ----------- //
# define ASTR0 "./img/sprites/asteroid0.xpm"
# define ASTR1 "./img/sprites/asteroid1.xpm"
# define ASTR2 "./img/sprites/asteroid2.xpm"
# define ASTR3 "./img/sprites/asteroid3.xpm"
# define ASTR4 "./img/sprites/asteroid4.xpm"

// ----------- BOOM ----------- //
# define BOOM0 "./img/sprites/boom0.xpm"
# define BOOM1 "./img/sprites/boom1.xpm"
# define BOOM2 "./img/sprites/boom2.xpm"
# define BOOM3 "./img/sprites/boom3.xpm"
# define BOOM4 "./img/sprites/boom4.xpm"

// ---------- COLLECT ---------- //
# define COLL0 "./img/textures/coll0.xpm"
# define COLL1 "./img/textures/coll1.xpm"

#endif
