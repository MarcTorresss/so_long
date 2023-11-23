/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: martorre <martorre@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 13:59:02 by martorre          #+#    #+#             */
/*   Updated: 2023/11/23 15:23:59 by martorre         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	close_win_esc(int key, t_img *img)
{
	if (key == 53)
	{
		//ft_free_all(img);
		mlx_destroy_window(img->mlx, img->window);
		exit (0);
	}
	return (0);
}
int	close_win(t_img *img)
{
	//ft_free_all(img);
	mlx_destroy_window(img->mlx, img->window);
	exit(0);
	return (0);
}