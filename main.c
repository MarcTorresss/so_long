/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/09 15:21:24 by martorre          #+#    #+#             */
/*   Updated: 2023/11/13 19:46:03 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include "./libft.h"

int		check_borders_bott_lef(char **new)
{
	int	y;
	int	x;
	int	out;

	y = 0;
	x = 0;
	out = 0;
	while (new[y] != NULL)
		y++;
	y--;		
	while (new[y][x] != '\0' && out == 0)
	{
		if (new[y][x] != '1')
			out = 1;
		x++;
	}
	y = 0;
	x = 0;
	while (new[y][x] != '\n' && new[y][x] != '\0')
		x++;
	x--;
	while (new[y] != NULL && out == 0)
	{
		if (new[y][x] != '1')
			out = 1;
		y++;
	}
	printf("%d", out);
	return (out);
}

int	check_borders_top_ri(char **new)
{
	int	x;
	int	y;
	int	out;

	x = 0;
	y = 0;
	out = 0;
	/*while (new[0][x] != '\n' && out == 0)
	{
		if (new[0][x] != '1')
			out = 1;
		x++;
	}*/
	while (new[y] != NULL && out == 0)
	{
		if (ft_strcmp(new[y], "1") != 0)
			out = 1;
		y++;
	}
	//printf("%d", out);
	check_borders_bott_lef(new);
	return (out);
}
int	check_map(char **new)
{
	check_borders_top_ri(new);
	return (0);
}

int	check_file(char *str)
{
	int		fd;
	int		i;
	char	*new[OPEN_MAX];

	fd = 0;
	i = 0;
    if(ft_strlen(ft_strnstr(str, ".bar", ft_strlen(str))) != ft_strlen(".bar"))
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
int	main(int argc, char **argv)
{
	/*int fd;
	char *new;
	int i;
	int	num;

	i = 0;*/
    //(void) argv;
    if  (argc > 2)
        ft_printf("To many arguments!\n");
    else
	{
        check_file(argv[1]);

	}
	return (0);
}