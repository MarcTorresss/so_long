/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/22 15:20:28 by martorre          #+#    #+#             */
/*   Updated: 2023/12/04 13:25:31 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	img_init(char *str, t_img *img)
{
	img->coin = 0;
	img->grass = 0;
	img->mlx = 0;
	img->player = 0;
	img->tree = 0;
	img->window = 0;
	img->door = 0;
	img->x = 0;
	img->y = 0;
	img->colsx = 0;
	img->rowsy = 0;
	img->width = 0;
	img->high = 0;
	img->move.m_x = 0;
	img->move.m_y = 0;
	img->move.x = 0;
	img->move.y = 0;
	img->move.qtt = 0;
	img->map = check_file(str, img);
	if (img->map != NULL)
		img->mapcpy = check_file(str, img);
	return (*img);
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

t_img	init_files(t_img img)
{
	img.tree = mlx_xpm_file_to_image(img.mlx, "./img/tree.xpm", &img.width,
			&img.high);
	img.grass = mlx_xpm_file_to_image(img.mlx, "./img/grass.xpm", &img.width,
			&img.high);
	img.coin = mlx_xpm_file_to_image(img.mlx, "./img/coin.xpm", &img.width,
			&img.high);
	img.player = mlx_xpm_file_to_image(img.mlx, "./img/player.xpm", &img.width,
			&img.high);
	img.playerle = mlx_xpm_file_to_image(img.mlx, "./img/playerS.xpm",
			&img.width, &img.high);
	img.playerri = mlx_xpm_file_to_image(img.mlx, "./img/playerSE.xpm",
			&img.width, &img.high);
	img.playerbo = mlx_xpm_file_to_image(img.mlx, "./img/playerB.xpm",
			&img.width, &img.high);
	img.door = mlx_xpm_file_to_image(img.mlx, "./img/door.xpm", &img.width,
			&img.high);
	return (img);
}

int	calc_line(char *str)
{
	char	*new;
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
		free(new);
		new = get_next_line(fd);
	}
	free(new);
	close(fd);
	return (i);
}

void	calc_img(t_img img)
{
	if (img.map[img.y][img.x] == '1')
		mlx_put_image_to_window(img.mlx, img.window, img.tree, img.width
			* img.x, img.high * img.y);
	else if (img.map[img.y][img.x] == '0')
		mlx_put_image_to_window(img.mlx, img.window, img.grass, img.width
			* img.x, img.high * img.y);
	else if (img.map[img.y][img.x] == 'C')
		mlx_put_image_to_window(img.mlx, img.window, img.coin, img.width
			* img.x, img.high * img.y);
	else if (img.map[img.y][img.x] == 'P')
		mlx_put_image_to_window(img.mlx, img.window, img.player, img.width
			* img.x, img.high * img.y);
	else if (img.map[img.y][img.x] == 'R')
		mlx_put_image_to_window(img.mlx, img.window, img.playerle, img.width
			* img.x, img.high * img.y);
	else if (img.map[img.y][img.x] == 'L')
		mlx_put_image_to_window(img.mlx, img.window, img.playerri, img.width
			* img.x, img.high * img.y);
	else if (img.map[img.y][img.x] == 'B')
		mlx_put_image_to_window(img.mlx, img.window, img.playerbo, img.width
			* img.x, img.high * img.y);
	else if (img.map[img.y][img.x] == 'E')
		mlx_put_image_to_window(img.mlx, img.window, img.door, img.width
			* img.x, img.high * img.y);
}
