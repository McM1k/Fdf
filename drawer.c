/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 17:37:25 by gboudrie          #+#    #+#             */
/*   Updated: 2016/03/22 17:23:19 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void				segment(void *mlx, void *win, int xa, int ya, int xb, int yb)
{
	int		x;
	int		y;
	double	div;


	x = 0;
	y = 0;
	(xa > xb ? ft_swap(&ya, &yb) : (void)0);
	(xa > xb ? ft_swap(&xa, &xb) : (void)0);
	div = (double)(yb - ya) / (double)(xb - xa);
	if (div >= -1 && div <= 1)
	{
		while (xa + x <= xb)
		{
			mlx_pixel_put(mlx, win, xa + x, ya + y, 0x00FF0000);
			x++;
			y = x * div;
		}
	}
	else
	{
		while (ya + y != yb)
		{
			mlx_pixel_put(mlx, win, xa + x , ya + y, 0x00FF0000);
			y = (ya < yb ? y + 1 : y - 1);
			x = y / div;
			if (ya + y == yb)
				mlx_pixel_put(mlx, win, xa + x , ya + y, 0x00FF0000);
		}
	}
}
