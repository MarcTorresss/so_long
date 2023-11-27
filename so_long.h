/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:21:43 by martorre          #+#    #+#             */
/*   Updated: 2023/11/27 18:44:20 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdarg.h>
# include <limits.h>
# include <sys/stat.h>
# include "mlx/mlx.h"
# include "libft/libft.h"

# define KEYDOWN 2
# define KEYUP 3
# define MOUSEDOWN 4
# define MOUSEUP 5
# define MOUSEMOVE 6
# define EXPOSE 12
# define DESTROY 17

typedef struct s_chars
{
	int				pos_ini;
	int				coin;
	int				exit;
}					t_chars;

typedef struct t_chmo
{
	int				x;
	int				y;
	int				m_x;
	int				m_y;
	int				qtt;
	int				ok;
}					t_chmo;

typedef struct s_img
{
	void			*player;
	void			*grass;
	void			*tree;
	void			*coin;
	void			*door;
	void			*window;
	void			*mlx;
	char			**map;
	int				x;
	int				y;
	int				rowsy;
	int				colsx;
	t_chars			chars;
	t_chmo			move;
}					t_img;

typedef struct s_moves
{
	int				w;
	int				a;
	int				s;
	int				d;
}					t_moves;


# define ON_KEYDOWN 1
# define ON_KEYUP 13
# define ON_KEYIZQ 0
# define ON_KEYDER 2


int		check_map(char **new);
t_img	img_init();
t_img	calc_x_y(t_img img);
t_img	init_files(int *width, int *high, t_img img);
int		calc_line(char *str);
void	calc_img(t_img img, int width, int high);
int		close_win_esc(int key, t_img *img);
int		close_win(t_img *img);
int		ft_moves(int key, void *img);
void	put_img(t_img img);
int		check_move(t_img *img);
t_img	inti_checkmove();
char	**check_file(char *str);

#endif