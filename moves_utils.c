/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:29:47 by martorre          #+#    #+#             */
/*   Updated: 2023/11/29 16:59:57 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_letter_map(t_img *img, char c)
{
	if (c == 'L')
		img->map[img->move.m_y][img->move.m_x] = 'L';
	else if (c == 'R')
		img->map[img->move.m_y][img->move.m_x] = 'R';
	else if (c == 'B')
		img->map[img->move.m_y][img->move.m_x] = 'B';
	else
		img->map[img->move.m_y][img->move.m_x] = 'P';
}

void	check_exit(t_img *img)
{
	if (img->map[img->move.m_y][img->move.m_x] == 'E' && img->chars.coin == 0)
	{
		mlx_destroy_window(img->mlx, img->window);
		img->map = check_file("win.ber");
		*img = calc_x_y(*img);
		img->move.qtt++;
		ft_printf("%d\n", img->move.qtt);
		img->window = mlx_new_window(img->mlx, img->colsx * 50, img->rowsy * 50,
				"./win!");
		put_img(*img);
		mlx_hook(img->window, 17, 0, close_win, img);
		mlx_hook(img->window, KEYUP, 0, close_win_esc, img);
	}
}

void	check_move(t_img *img, char c)
{
	if (img->map[img->move.m_y][img->move.m_x] == '0')
	{
		put_letter_map(img, c);
		img->map[img->move.y][img->move.x] = '0';
		img->move.qtt++;
		ft_printf("%d\n", img->move.qtt);
		put_img(*img);
	}
	if (img->map[img->move.m_y][img->move.m_x] == 'C')
	{
		put_letter_map(img, c);
		img->map[img->move.y][img->move.x] = '0';
		img->chars.coin--;
		img->move.qtt++;
		ft_printf("%d\n", img->move.qtt);
		put_img(*img);
	}
	check_exit(img);
}
