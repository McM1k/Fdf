/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 17:37:25 by gboudrie          #+#    #+#             */
/*   Updated: 2016/03/17 21:37:58 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void		ft_swap(void *a, void *b)
{
	void	*ptr;

	ptr = a;
	a = b;
	b = ptr;
}

void		segment(void *mlx, void *win, int xa, int ya, int xb, int yb)
{
	int		i;
	int		j;
	int		div;

	if (xa > xb)
	{
		ft_swap((void *)&xa, (void *)&xb);
		ft_swap((void *)&ya, (void *)&yb); // EAST
	}
	i = xa;
	j = ya;
	while (i != xb && j != yb)
	{
		if (j <= yb) // SOUTH EAST
		{
			
		}
		else // NORTH EAST
		{
			
		}
	}
	mlx_pixel_put(mlx, win, i, j, 0x00FF0000);
}
