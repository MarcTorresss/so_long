/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:01:00 by martorre          #+#    #+#             */
/*   Updated: 2023/11/28 14:59:52 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img   ft_move_up(t_img *img)
{
    img->move.y = 0;
    img->move.x = 0;
    while (img->map[img->move.y][img->move.x] != 'P' && img->map[img->move.y][img->move.x] != 'B'
        && img->map[img->move.y][img->move.x] != 'R' && img->map[img->move.y][img->move.x] != 'L')
    {
        if (img->map[img->move.y][img->move.x] == '\n')
        {
            img->move.y++;
            img->move.x = 0;
        }
        img->move.x++;
    }
    img->move.m_y = img->move.y - 1;
    img->move.m_x = img->move.x;
    check_move(img, 'B');
    return (*img);
}

t_img   ft_move_down(t_img *img)
{
    img->move.y = 0;
    img->move.x = 0;
    while (img->map[img->move.y][img->move.x] != 'P' && img->map[img->move.y][img->move.x] != 'B'
        && img->map[img->move.y][img->move.x] != 'R' && img->map[img->move.y][img->move.x] != 'L')
    {
        if (img->map[img->move.y][img->move.x] == '\n')
        {
            img->move.y++;
            img->move.x = 0;
        }
        img->move.x++;
    }
    img->move.m_y = img->move.y + 1;
    img->move.m_x = img->move.x;
    check_move(img, '0');
    return (*img);
}

t_img   ft_move_izq(t_img *img)
{
    img->move.y = 0;
    img->move.x = 0;
    while (img->map[img->move.y][img->move.x] != 'P' && img->map[img->move.y][img->move.x] != 'B'
        && img->map[img->move.y][img->move.x] != 'R' && img->map[img->move.y][img->move.x] != 'L')
    {
        if (img->map[img->move.y][img->move.x] == '\n')
        {
            img->move.y++;
            img->move.x = 0;
        }
        img->move.x++;
    }
    img->move.m_y = img->move.y;
    img->move.m_x = img->move.x - 1;
    check_move(img, 'L');
    return (*img);
}

t_img   ft_move_der(t_img *img)
{
    img->move.y = 0;
    img->move.x = 0;
    while (img->map[img->move.y][img->move.x] != 'P' && img->map[img->move.y][img->move.x] != 'B'
        && img->map[img->move.y][img->move.x] != 'R' && img->map[img->move.y][img->move.x] != 'L')
    {
        if (img->map[img->move.y][img->move.x] == '\n')
        {
            img->move.y++;
            img->move.x = 0;
        }
        img->move.x++;
    }
    img->move.m_y = img->move.y;
    img->move.m_x = img->move.x + 1;
    check_move(img, 'R');
    return (*img);
}

int    ft_moves(int key, void *img)
{    
    t_img   *aux;
    
    aux = (t_img *) img;
    if (key == ON_KEYUP)
    {
        ft_move_up(aux);
    }
    else if (key == ON_KEYDOWN)
    {
        ft_move_down(aux);
    }
    else if (key == ON_KEYDER)
    {
        ft_move_der(aux);
    }
    else if (key == ON_KEYIZQ)
    {
        ft_move_izq(aux);
    }
    return (0);
}