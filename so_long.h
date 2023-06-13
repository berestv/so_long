/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bbento-e <bbento-e@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/30 15:39:16 by bbento-e          #+#    #+#             */
/*   Updated: 2023/06/13 19:28:15 by bbento-e         ###   ########.fr       */
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
int		int_err_handler(int n);

// ----------- CHECKS ----------- //
int		ber(char *str);

// ----------- VERIFS ----------- //

#endif
