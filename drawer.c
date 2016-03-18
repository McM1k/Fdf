/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 17:37:25 by gboudrie          #+#    #+#             */
/*   Updated: 2016/03/18 15:54:33 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static double		affine(int x, double div, int dir)
{
	int		y;

	if (dir == 1)
		y = x * div;
	else
		y = x / div;
	return (y);
}

void				segment(void *mlx, void *win, int xa, int ya, int xb, int yb)
{
	int		i;
	double	div;


	i = 0;
	if (xa > xb) //EAST
	{
		ft_swap((void *)&xa, (void *)&xb);
		ft_swap((void *)&ya, (void *)&yb);
	}
	div = (double)((yb - ya) / (xb - xa));
	if (div >= -1 && div <= 1)
	{
		while (xa + i < xb)
		{
			mlx_pixel_put(mlx, win, xa + i, ya + affine(i, div, 1), 0x00FF0000);
			i++;
		}
	}
	else
	{
		while ((ya + i - yb) != 0)
		{
			mlx_pixel_put(mlx, win, ya + i, xa + affine(i, div ,0), 0x00FF0000);
			i++;
		}
	}
}
