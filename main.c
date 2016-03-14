/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 18:54:15 by gboudrie          #+#    #+#             */
/*   Updated: 2016/03/14 19:04:45 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"

int		main()
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	
	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "poulet");
	x = 50;
	while (x < 350)
	{
		mlx_pixel_put(mlx, win, x, x, 0x00FF0000);
		x++;
	}
	y = 50;
	while (y < 350)
	{
		mlx_pixel_put(mlx, win, x, y, 0x00FF0000);
		y++;
		x--;
	}
	mlx_loop(mlx);
}
