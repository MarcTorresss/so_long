/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:21:24 by martorre          #+#    #+#             */
/*   Updated: 2023/11/23 15:20:33 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(t_img img, char **map)
{
	int	width;
	int	high;

	width = 0;
	high = 0;
	img = init_files(&width, &high, img);
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

char	**check_file(char *str)
{
	int		i;
	int		fd;
	char	**new = NULL;

	fd = 0;
	i = 0;
	new = malloc(sizeof(char *) * (calc_line(str) + 1));
    if (ft_strlen(ft_strnstr(str, ".ber", ft_strlen(str))) != ft_strlen(".ber"))
    	return (free(new), ft_printf("Invalid extension :(\n"), NULL);
    else
	{
		fd = open(str, O_RDONLY);
		if (fd == -1)
			return (free(new), ft_printf("Invalid fd :/\n"), NULL);
		new[i] = get_next_line(fd);
		while (new[i] != NULL)
		{
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
		ft_printf("Bad arguments :\\\n");
    else
	{
    	map = check_file(argv[1]);
		if (check_map(map) == 0)
		{
			img = img_init();
			img = calc_x_y(map);
			img.mlx = mlx_init();
			img.window = mlx_new_window(img.mlx, img.colsx * 50, img.rowsy * 50, "./so_long");
			mlx_hook(img.window, 17, 0, close_win, &img);
			mlx_hook(img.window, KEYUP, 1L << 0, close_win_esc, &img);
			//mlx_hook(img.window, KEYDOWN, 1L << 0, ft_moves, &img);
			put_img(img, map);
			mlx_loop(img.mlx);
			free(map);
		}
	}
	return (0);
}
