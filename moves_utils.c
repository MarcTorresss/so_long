/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 16:29:47 by martorre          #+#    #+#             */
/*   Updated: 2023/11/27 19:47:55 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int check_move(t_img *img)
{
    ft_printf("y = %d, x = %d", img->move.m_y, img->move.m_x);
    if (img->map[img->move.m_y][img->move.m_x] == '0')
    {
        img->map[img->move.m_y][img->move.m_x] = 'P';
        img->map[img->move.y][img->move.x] = '0';
        img->move.qtt++;
        //printf("%d\n", img->move.qtt);
        put_img(*img);
    }
    if (img->map[img->move.m_y][img->move.m_x] == 'C')
    {
        img->map[img->move.m_y][img->move.m_x] = 'P';
        img->map[img->move.y][img->move.x] = '0';
        img->chars.coin--;
        img->move.qtt++;
        //printf("%d\n", img->move.qtt);
        put_img(*img);
    }
    if (img->map[img->move.m_y][img->move.m_x] == 'E' && img->chars.coin == 0)
    {
        mlx_destroy_window(img->mlx, img->window);
	    img->map = check_file("win.ber");
        *img = calc_x_y(*img);
        img->window = mlx_new_window(img->mlx, img->colsx * 50, img->rowsy * 50, "./win!");
        put_img(*img);
    }
    return (0);
}