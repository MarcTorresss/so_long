/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:20:28 by martorre          #+#    #+#             */
/*   Updated: 2023/11/22 19:08:15 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	img_init()
{
	t_img	img;

	img.coin = 0;
	img.grass_one = 0;
	img.grass_two = 0;
	img.mlx = 0;
	img.player = 0;
	img.tree = 0;
	img.window = 0;
    img.door = 0;
	img.x = 0;
	img.y = 0;
	img.xs = 0;
	img.ys = 0;

	return (img);
}

t_img	calc_x_y(char **map)
{
	t_img img;
	int	x;
	int	y;

	x = 0;
	y = 0;
	img = img_init();
	while (map[y] != NULL)
		y++;
    y--;
	while (map[0][x] != '\n' && map[0][x] != '\0')
		x++;
    x--;
	img.ys = y;
	img.xs = x;
	return (img);
}
