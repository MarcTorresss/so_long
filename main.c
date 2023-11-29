/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:21:24 by martorre          #+#    #+#             */
/*   Updated: 2023/11/29 19:55:08 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_img(t_img img)
{
	img = init_files(img);
	while (img.map[img.y][img.x] != '\0')
	{
		if (img.map[img.y][img.x] != '\n')
			calc_img(img);
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
	char	**new;

	new = NULL;
	fd = 0;
	i = 0;
	if (calc_line(str) == 0)
		return (NULL);
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
	t_img	img;

	if (argc != 2)
		ft_printf("Bad arguments :\\\n");
	else
	{
		img = img_init(argv[1]);
		if (img.map != NULL && img.mapcpy != NULL)
		{
			img = calc_x_y(img);
			if (check_map(&img) == 0)
			{
				img.window = mlx_new_window(img.mlx, img.colsx * 50, img.rowsy
						* 50, "./so_long");
				mlx_hook(img.window, 17, 0, close_win, &img);
				mlx_hook(img.window, KEYUP, 0, close_win_esc, &img);
				mlx_hook(img.window, KEYDOWN, 0, ft_moves, (void *)&img);
				put_img(img);
				mlx_loop(img.mlx);
			}
		}
		/*free(img.map);
		free(img.mapcpy);*/
	}
	return (0);
}
