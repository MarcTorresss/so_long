/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:21:24 by martorre          #+#    #+#             */
/*   Updated: 2023/11/14 15:10:28 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./libft.h"
#include <mlx.h>

int	check_file(char *str)
{
	int		i;
	int		fd;
	char	*new[OPEN_MAX];

	fd = 0;
	i = 0;
    if(ft_strlen(ft_strnstr(str, ".ber", ft_strlen(str))) != ft_strlen(".ber"))
    	return (ft_printf("Invalid file!\n"), 1);
    else
	{
		fd = open(str, O_RDONLY);
		if (fd == -1)
			return (ft_printf("Invalid fd!\n"), 1);
		new[i] = get_next_line(fd);
		while (new[i] != NULL)
		{
			i++;
			new[i] = get_next_line(fd);
		}
		check_map(new);
	}
	return (0);
}

void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

int	main(int argc, char **argv)
{
	void	*mlx;
	void	*img;
	char	*relative_path = "./player.png";
	int		img_width;
	int		img_height;
	
	mlx = NULL;
	img = NULL;
	img_width = 0;
	img_height = 0;
    if  (argc > 2)
        ft_printf("To many arguments!\n");
    else
	{
        check_file(argv[1]);
		/*mlx = mlx_init();
		mlx_win = mlx_new_window(mlx, 1920, 1080, "./so_long");
		img.img = mlx_new_image(mlx, 1920, 1080);
		img.addr = mlx_get_data_addr(img.img, &img.bits_per_pixel, &img.line_length,
									&img.endian);
		my_mlx_pixel_put(&img, 5, 5, 0x00FF0000);
		mlx_put_image_to_window(mlx, mlx_win, img.img, 0, 0);
		mlx_loop(mlx);*/
		mlx = mlx_init();
		img = mlx_png_file_to_image(mlx, relative_path, &img_width, &img_height);
	}
	return (0);
}