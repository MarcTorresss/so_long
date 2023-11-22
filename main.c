/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:21:24 by martorre          #+#    #+#             */
/*   Updated: 2023/11/22 19:47:23 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	calc_img(t_img img, char **map, int width, int high)
{
	if (map[img.y][img.x] == '1')
	{
		img.tree = mlx_xpm_file_to_image(img.mlx, "./img/tree1.xpm", &width, &high);
		mlx_put_image_to_window (img.mlx, img.window, img.tree, width * img.x,  high * img.y);
	}
	else if (map[img.y][img.x] == '0')
	{
		img.grass_one = mlx_xpm_file_to_image(img.mlx, "./img/Grass1.xpm", &width, &high);
		mlx_put_image_to_window (img.mlx, img.window, img.grass_one, width * img.x,  high * img.y);
	}
	else if (map[img.y][img.x] == 'C')
	{
		img.coin = mlx_xpm_file_to_image(img.mlx, "./img/coin1.xpm", &width, &high);
		mlx_put_image_to_window (img.mlx, img.window, img.coin, width * img.x,  high * img.y);
	}
	else if (map[img.y][img.x] == 'P')
	{
		img.player = mlx_xpm_file_to_image(img.mlx, "./img/player1.xpm", &width, &high);
		mlx_put_image_to_window (img.mlx, img.window, img.player, width * img.x,  high * img.y);
	}
	else if (map[img.y][img.x] == 'E')
	{
		img.door = mlx_xpm_file_to_image(img.mlx, "./img/door1.xpm", &width, &high);
		mlx_put_image_to_window (img.mlx, img.window, img.door, width * img.x,  high * img.y);
	}
}

void	put_img(t_img img, char **map)
{
	int	width;
	int	high;

	width = 0;
	high = 0;
	while (map[img.y][img.x] != '\0')
	{
		if (map[img.y][img.x] != '\n')
			calc_img(img, map, width, high);
		else
		{
			img.y++;
			img.x = -1;
		}
		img.x++;
	}
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

char	**check_file(char *str)
{
	int		i;
	int		fd;
	char	**new = NULL;

	fd = 0;
	i = 0;
	new = malloc(sizeof(char *) * (calc_line(str) + 1));
    if (ft_strlen(ft_strnstr(str, ".ber", ft_strlen(str))) != ft_strlen(".ber"))
    	return (free(new), ft_printf("Invalid extension!\n"), NULL);
    else
	{
		fd = open(str, O_RDONLY);
		if (fd == -1)
			return (free(new), ft_printf("Invalid fd!\n"), NULL);
		new[i] = get_next_line(fd);
		while (new[i] != NULL)
		{
			printf("%s" , new[i]);
			i++;
			new[i] = get_next_line(fd);
		}
	}
	return (new);
}


int	main(int argc, char **argv)
{
	char	**map;
	t_img	img;

    if  (argc != 2)
		ft_printf("Bad arguments!\n");
    else
	{
    	map = check_file(argv[1]);
		if (check_map(map) == 0)
		{
			img = img_init();
			img = calc_x_y(map);
			img.mlx = mlx_init();
			img.window = mlx_new_window(img.mlx, img.xs * 50, img.ys * 50, "./so_long");
			put_img(img, map);
			mlx_loop(img.mlx);
			free(map);
		}
	}
	return (0);
}
