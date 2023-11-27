/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:20:28 by martorre          #+#    #+#             */
/*   Updated: 2023/11/27 19:44:36 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	img_init()
{
	t_img	img;

	img.coin = 0;
	img.grass = 0;
	img.mlx = 0;
	img.player = 0;
	img.tree = 0;
	img.window = 0;
    img.door = 0;
	img.x = 0;
	img.y = 0;
	img.colsx = 0;
	img.rowsy = 0;
	img.move.m_x = 0;
    img.move.m_y = 0;
    img.move.x = 0;
    img.move.y = 0;
    img.move.ok = 0;
	img.move.qtt = 0;

	return (img);
}

t_img	calc_x_y(t_img img)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	while (img.map[y] != NULL)
		y++;
    y--;
	while (img.map[0][x] != '\n' && img.map[0][x] != '\0')
		x++;
    x--;
	img.rowsy = y + 1;
	img.colsx = x + 1;
	return (img);
}

t_img	init_files(int *width, int *high, t_img img)
{
	img.tree = mlx_xpm_file_to_image(img.mlx, "./img/tree.xpm", width, high);
	img.grass = mlx_xpm_file_to_image(img.mlx, "./img/grass.xpm", width, high);
	img.coin = mlx_xpm_file_to_image(img.mlx, "./img/coin.xpm", width, high);
	img.player = mlx_xpm_file_to_image(img.mlx, "./img/player.xpm", width, high);
	img.door = mlx_xpm_file_to_image(img.mlx, "./img/door.xpm", width, high);
	return (img);
}

int	calc_line(char *str)
{
	char	*new = NULL;
	int		i;
	int		fd;
	
	i = 0;
	fd = open(str, O_RDONLY);
	if (fd == -1)
		return (ft_printf("Invalid fd!\n"), 0);
	new = get_next_line(fd);
	while (new != NULL)
	{
		i++;
		new = get_next_line(fd);
	}
	return (i);
}

void	calc_img(t_img img, int width, int high)
{
	if (img.map[img.y][img.x] == '1')
		mlx_put_image_to_window (img.mlx, img.window, img.tree, width * img.x,  high * img.y);
	else if (img.map[img.y][img.x] == '0')
		mlx_put_image_to_window (img.mlx, img.window, img.grass, width * img.x,  high * img.y);
	else if (img.map[img.y][img.x] == 'C')
		mlx_put_image_to_window (img.mlx, img.window, img.coin, width * img.x,  high * img.y);
	else if (img.map[img.y][img.x] == 'P')
		mlx_put_image_to_window (img.mlx, img.window, img.player, width * img.x,  high * img.y);
	else if (img.map[img.y][img.x] == 'E')
		mlx_put_image_to_window (img.mlx, img.window, img.door, width * img.x,  high * img.y);
}
