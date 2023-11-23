/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:23:10 by martorre          #+#    #+#             */
/*   Updated: 2023/11/23 15:36:57 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "libft/libft.h"

t_chars	init_chars()
{
	t_chars	chars;

	chars.coin = 0;
	chars.pos_ini = 0;
	chars.exit = 0;

	return (chars);
}

int	check_chars(char **new)
{
	t_chars	chars;
	int		x;
	int		y;

	chars = init_chars();
	x = 0;
	y = 0;
	while (new[y][x] != '\0')
	{
		if (new[y][x] == 'P')
			chars.pos_ini++;
		if (new[y][x] == 'E')
			chars.exit++;
		if (new[y][x] == 'C')
			chars.coin++;
		if (new[y][x] == '\n')
		{
			y++;
			x = 0;
		}
		x++;
	}
	if (chars.pos_ini == 1 && chars.exit == 1 && chars.coin >= 1)
		return (0);
	return (1);
}

int check_len(char **new)
{
    int y;
    int len;
    int aux;
    int out;

    y = 0;
    len = ft_strlen(new[y]);
    aux = 0;
    out = 0;
    if (new[y][len - 1] == '\n')
        len--;
    if (new[y][len - 1] == '\0')
        return (0);
    y++;
    while (new[y] != NULL && out == 0)
    {
        aux = ft_strlen(new[y]);
        if (new[y][aux - 1] == '\n')
            aux--;
        if (aux != len)
            out = 1;
        y++;
    }
    return (out);
}

int		check_bott_lef(char **new)
{
	int	y;
	int	x;

	y = 0;
	x = 0;
	while (new[y] != NULL)
		y++;
	y--;		
	while (new[y][x] != '\0')
	{
		if (new[y][x] != '1')
			return (1);
		x++;
	}
	y = 0;
	x = 0;
	while (new[y][x] != '\n' && new[y][x] != '\0')
		x++;
	x--;
	while (new[y] != NULL)
	{
		if (new[y][x] != '1')
			return (1);
		y++;
	}
	return (0);
}

int	check_top_ri(char **new)
{
	int	x;
	int	y;
	int	out;

	x = 0;
	y = 0;
	out = 0;
	while (new[y][x] != '\n' && out == 0 && new[y][x] != '\0')
	{
		if (new[y][x] != '1')
			out = 1;
		x++;
	} 
	y = 0;
	x = 0;
	while (new[y] != NULL && out == 0)
	{
		if (new[y][0] != '1')
			out = 1;
		y++;
	}
	return (out);
}

int	check_map(char **new)
{
	if (check_top_ri(new) == 0 && check_bott_lef(new) == 0
		&& check_chars(new) == 0 && check_len(new) == 0)
	{
		return (0);
	}
	else
		return (ft_printf("Invalid map :|\n"));
	return (0);
}
