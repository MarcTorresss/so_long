/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:21:43 by martorre          #+#    #+#             */
/*   Updated: 2023/11/22 19:08:06 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include "mlx/mlx_png.h"
# include "mlx/mlx.h"
# include "libft/libft.h"

typedef struct s_chars
{
	int				p;
	int				c;
	int				e;
}					t_chars;

typedef struct s_img
{
	void			*player;
	void			*grass_one;
	void			*grass_two;
	void			*tree;
	void			*coin;
	void			*door;
	void			*window;
	void			*mlx;
	int				x;
	int				y;
	int				xs;
	int				ys;
}					t_img;

int		check_map(char **new);
t_img	img_init();
t_img	calc_x_y(char **map);

#endif