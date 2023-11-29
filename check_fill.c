/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 13:37:38 by martorre          #+#    #+#             */
/*   Updated: 2023/11/29 18:38:35 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	fill(char **tab, t_point size, t_point cur, char *letters)
{
	if (cur.y < 0 || cur.y >= size.y || cur.x < 0 || cur.x >= size.x
		|| (tab[cur.y][cur.x] != letters[0] && tab[cur.y][cur.x] != letters[1]))
		return ;
	tab[cur.y][cur.x] = 'F';
	fill(tab, size, (t_point){cur.x - 1, cur.y}, letters);
	fill(tab, size, (t_point){cur.x + 1, cur.y}, letters);
	fill(tab, size, (t_point){cur.x, cur.y - 1}, letters);
	fill(tab, size, (t_point){cur.x, cur.y + 1}, letters);
}

t_pos	init_pos_char(char **tab)
{
	int		y;
	int		x;
	t_pos	pos;

	y = 0;
	x = 0;
	while (tab[y][x] != '\0')
	{
		pos = check_letter_pos(pos, tab, y, x);
		if (tab[y][x] == '\n')
		{
			x = -1;
			y++;
		}
		x++;
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

int	flood_fill(char **tab, t_point size)
{
	int		y;
	int		x;
	t_pos	pos;
	char	letters[2];

	y = 0;
	x = -1;
	pos = init_pos_char(tab);
	letters[0] = tab[pos.posp.y][pos.posp.x];
	letters[1] = 'C';
	fill(tab, size, pos.begin, letters);
	while (tab[y][++x] != '\0')
	{
		pos = init_pos_char(tab);
		if (tab[y][x] == 'C')
			if (check_coin(pos, tab) == 1)
				return (ft_printf("Coin sin acceso :(\n"), 1);
		if (y == pos.pose.y && x == pos.pose.x)
			if (check_door(pos, tab) == 1)
				return (ft_printf("Puerta sin acceso :/\n"), 1);
		if (tab[y][x] == '\n')
		{
			x = -1;
			y++;
		}
	}
	return (0);
}
