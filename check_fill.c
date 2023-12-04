/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:37:38 by martorre          #+#    #+#             */
/*   Updated: 2023/12/04 11:56:53 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(char **tab, t_point size, t_point cur)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| (tab[cur.y][cur.x] != PLAYER && tab[cur.y][cur.x] != COIN))
		return ;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y});
	fill(tab, size, (t_point){cur.x + 1, cur.y});
	fill(tab, size, (t_point){cur.x, cur.y - 1});
	fill(tab, size, (t_point){cur.x, cur.y + 1});
}

t_pos	init_pos_char(char **tab)
{
	int		y;
	int		x;
	t_pos	pos;

	y = 0;
	x = -1;
	while (tab[y][++x] != '\0')
	{
		pos = check_letter_pos(pos, tab, y, x);
		if (tab[y][x] == '\n' || tab[y][x] == '\0')
		{
			x = -1;
			y++;
		}
	}
	pos.begin.x = pos.posp.x;
	pos.begin.y = pos.posp.y;
	tab[pos.posp.y][pos.posp.x] = '0';
	return (pos);
}

int	check_coin(t_pos pos, char **tab)
{
	if (tab[pos.posc.y][pos.posc.x + 1] == 'F' || tab[pos.posc.y][pos.posc.x
		- 1] == 'F' || tab[pos.posc.y - 1][pos.posc.x] == 'F' || tab[pos.posc.y
		+ 1][pos.posc.x] == 'F' || tab[pos.posc.y][pos.posc.x + 1] == 'C'
		|| tab[pos.posc.y][pos.posc.x - 1] == 'C' || tab[pos.posc.y
		- 1][pos.posc.x] == 'C' || tab[pos.posc.y + 1][pos.posc.x] == 'C')
		return (0);
	return (1);
}

int	check_door(t_pos pos, char **tab)
{
	if (tab[pos.pose.y][pos.pose.x + 1] == 'F' || tab[pos.pose.y][pos.pose.x
		- 1] == 'F' || tab[pos.pose.y - 1][pos.pose.x] == 'F' || tab[pos.pose.y
		+ 1][pos.pose.x] == 'F' || tab[pos.pose.y][pos.pose.x + 1] == 'C'
		|| tab[pos.pose.y][pos.pose.x - 1] == 'C' || tab[pos.pose.y
		- 1][pos.pose.x] == 'C' || tab[pos.pose.y + 1][pos.pose.x] == 'C')
		return (0);
	return (1);
}

int	flood_fill(t_img *img, t_point size)
{
	int		y;
	int		x;
	t_pos	pos;

	y = 0;
	x = -1;
	pos = init_pos_char(img->mapcpy);
	fill(img->mapcpy, size, pos.begin);
	img->mapcpy[pos.posp.y][pos.posp.x] = 'P';
	while (img->mapcpy[y][++x] != '\0')
	{
		pos = init_pos_char(img->mapcpy);
		if (img->mapcpy[y][x] == 'C')
			if (check_coin(pos, img->mapcpy) == 1)
				return (ft_free_map(img), ft_printf("Coin sin acceso :(\n"), 1);
		if (y == pos.pose.y && x == pos.pose.x)
			if (check_door(pos, img->mapcpy) == 1)
				return (ft_free_map(img), ft_printf("Puerta sin acceso\n"), 1);
		if (img->mapcpy[y][x] == '\n')
		{
			x = -1;
			y++;
		}
	}
	return (0);
}
