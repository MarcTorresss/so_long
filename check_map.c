/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/14 11:23:10 by martorre          #+#    #+#             */
/*   Updated: 2023/12/04 11:56:03 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include "so_long.h"

int	check_chars(t_img *img)
{
	int	x;
	int	y;

	img->chars = init_chars();
	x = 0;
	y = 0;
	while (img->map[y][x] != '\0')
	{
		if (img->map[y][x] == 'P')
			img->chars.pos_ini++;
		if (img->map[y][x] == 'E')
			img->chars.exit++;
		if (img->map[y][x] == 'C')
			img->chars.coin++;
		if (img->map[y][x] == '\n')
		{
			y++;
			x = 0;
		}
		x++;
	}
	if (img->chars.pos_ini == 1 && img->chars.exit == 1 && img->chars.coin >= 1)
		return (0);
	return (1);
}

int	check_len(char **new)
{
	int	y;
	int	len;
	int	aux;
	int	out;

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

int	check_bott_lef(char **new)
{
	int	y;
	int	x;

	y = 0;
	x = -1;
	while (new[y] != NULL)
		y++;
	y--;
	while (new[y][++x] != '\0')
	{
		if (new[y][x] != '1')
			return (1);
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

int	check_map(t_img *img)
{
	t_point	size;

	size.x = img->colsx;
	size.y = img->rowsy;
	if (check_top_ri(img->map) == 0 && check_bott_lef(img->map) == 0
		&& check_chars(img) == 0 && check_len(img->map) == 0)
	{
		return (flood_fill(img, size));
	}
	else
	{
		return (ft_free_map(img), ft_printf("Invalid map :|\n"));
	}
	return (0);
}
