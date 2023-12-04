/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:21:43 by martorre          #+#    #+#             */
/*   Updated: 2023/12/04 17:46:27 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "libft/libft.h"
# include "mlx/mlx.h"
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <unistd.h>

# define KEYDOWN 2
# define KEYUP 3
# define MOUSEDOWN 4
# define MOUSEUP 5
# define MOUSEMOVE 6
# define EXPOSE 12
# define DESTROY 17
# define PLAYER '0'
# define COIN 'C'
# define ERR_FD "Invalid fd :(\n"
# define ERR_EX "Invalid extension :(\n"

typedef struct s_chars
{
	int		pos_ini;
	int		coin;
	int		exit;
}			t_chars;

typedef struct t_chmo
{
	int		x;
	int		y;
	int		m_x;
	int		m_y;
	int		qtt;
}			t_chmo;

typedef struct s_img
{
	void	*player;
	void	*playerle;
	void	*playerbo;
	void	*playerri;
	void	*grass;
	void	*tree;
	void	*coin;
	void	*door;
	void	*window;
	void	*mlx;
	char	**map;
	char	**mapcpy;
	int		x;
	int		y;
	int		rowsy;
	int		colsx;
	int		width;
	int		high;
	t_chars	chars;
	t_chmo	move;
}			t_img;

typedef struct s_moves
{
	int		w;
	int		a;
	int		s;
	int		d;
}			t_moves;

typedef struct s_point
{
	int		x;
	int		y;
}			t_point;

typedef struct s_pos
{
	t_point	posp;
	t_point	posc;
	t_point	pose;
	t_point	begin;
}			t_pos;

# define ON_KEYDOWN 1
# define ON_KEYUP 13
# define ON_KEYIZQ 0
# define ON_KEYDER 2

int			check_map(t_img *img);
t_img		img_init(char *str, t_img *img);
t_img		calc_x_y(t_img img);
t_img		init_files(t_img img);
t_chars		init_chars(void);
t_img		inti_checkmove(void);
int			calc_line(char *str);
void		calc_img(t_img img);
int			close_win_esc(int key, t_img *img);
int			close_win(t_img *img);
int			ft_moves(int key, void *img);
void		put_img(t_img img);
void		check_move(t_img *img, char c);
char		**check_file(char *str, t_img *img);
int			flood_fill(t_img *img, t_point size);
t_pos		check_letter_pos(t_pos pos, char **tab, int y, int x);
void		ft_free_map(t_img *img);
t_pos		pos_final(t_img img);

#endif