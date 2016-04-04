/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 17:37:25 by gboudrie          #+#    #+#             */
/*   Updated: 2016/04/04 21:50:16 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"



void				segment(t_env env, t_dot a, t_dot b)
{
	int		x;
	int		y;
	double	div;


	x = 0;
	y = 0;
	(a.x > b.x ? ft_swap(&a.y, &b.y) : (void)0);
	(a.x > b.x ? ft_swap(&a.x, &b.x) : (void)0);
	div = (double)(b.y - a.y) / (double)(b.x - a.x);
	if (div >= -1 && div <= 1)
	{
		while (a.x + x <= b.x)
		{
			mlx_pixel_put(mlx, win, a.x + x, a.y + y, 0x00FF0000);
			x++;
			y = x * div;
		}
	}
	else
	{
		while (a.y + y != b.y)
		{
			mlx_pixel_put(mlx, win, a.x + x , a.y + y, 0x00FF0000);
			y = (a.y < b.y ? y + 1 : y - 1);
			x = y / div;
			if (a.y + y == b.y)
				mlx_pixel_put(mlx, win, a.x + x , a.y + y, 0x00FF0000);
		}
	}
}

