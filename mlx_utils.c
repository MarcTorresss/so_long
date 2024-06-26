/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:59:02 by martorre          #+#    #+#             */
/*   Updated: 2023/12/04 15:38:51 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_free_map(t_img *img)
{
	int	y;

	y = 0;
	while (img->map[y] != NULL)
	{
		free(img->map[y]);
		y++;
	}
	free(img->map);
	y = 0;
	while (img->mapcpy[y] != NULL)
	{
		free(img->mapcpy[y]);
		y++;
	}
	free(img->mapcpy);
}

int	close_win_esc(int key, t_img *img)
{
	if (key == 53)
	{
		ft_free_map(img);
		mlx_destroy_window(img->mlx, img->window);
		exit(0);
	}
	return (0);
}

int	close_win(t_img *img)
{
	ft_free_map(img);
	mlx_destroy_window(img->mlx, img->window);
	exit(0);
	return (0);
}

t_chars	init_chars(void)
{
	t_chars	chars;

	chars.coin = 0;
	chars.pos_ini = 0;
	chars.exit = 0;
	return (chars);
}

t_pos	check_letter_pos(t_pos pos, char **tab, int y, int x)
{
	if (tab[y][x] == 'P')
	{
		pos.posp.x = x;
		pos.posp.y = y;
	}
	if (tab[y][x] == 'C')
	{
		pos.posc.x = x;
		pos.posc.y = y;
	}
	if (tab[y][x] == 'E')
	{
		pos.pose.x = x;
		pos.pose.y = y;
	}
	return (pos);
}
