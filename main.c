/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 18:54:15 by gboudrie          #+#    #+#             */
/*   Updated: 2016/03/18 13:53:22 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

int		my_key_func(int keycode, void *param)
{
	int		tmp;

	tmp = (int)param;
	if (keycode == 53)
	{
		ft_putendl("<ESC>");
		exit(0);
	}
	return (1);
}

int		main(/*int ac, char **av*/)
{
/* 	int		i; */
/* 	int		j; */
/* 	int		fd; */
/* 	int		**tab; */

/* 	if (ac == 2) */
/* 	{ */
/* 		fd = open(av[1], O_RDONLY); */
/* 		tab = reader(fd, tab); */
/* 		j = 0; */
/* 		while (tab[j]) */
/* 		{ */
/* 			i = 0; */
/* 			while (i <= tab[j][0]) */
/* 			{ */
/* 				ft_putnbr(tab[j][i + 1]); */
/* 				if (tab[j][i + 1] < 10) */
/* 					ft_putchar(' '); */
/* 				ft_putchar(' '); */
/* 				i++; */
/* 			} */
/* 			ft_putendl(""); */
/* 			j++; */
/* 		} */
/* 	} */

	void	*mlx;
	void	*win;
/* 	int		x; */
/* 	int		y; */
/* 	int		a; */

	mlx = mlx_init();
	win = mlx_new_window(mlx, 400, 400, "poulet");
	segment(mlx, win, 200, 200, 400, 100);
	segment(mlx, win, 200, 200, 400, 300);
	segment(mlx, win, 200, 200, 000, 100);
	segment(mlx, win, 200, 200, 000, 300);
	segment(mlx, win, 200, 200, 100, 000);
	segment(mlx, win, 200, 200, 300, 000);
	segment(mlx, win, 200, 200, 100, 400);
	segment(mlx, win, 200, 200, 300, 400);


/* 	x = 50; */
/* 	y = 50; */
/* 	a = 50; */
/* 	while ((x > 205 || x < 195) && (y > 205 || y < 195)) */
/* 	{ */
/* 		while (x < 400 - a) */
/* 		{ */
/* 			mlx_pixel_put(mlx, win, x, y, 0x00FF0000); */
/* 			x++; */
/* 		} */
/* 		a++; */
/* 		while (y < 400 - a) */
/* 		{ */
/* 			mlx_pixel_put(mlx, win, x, y, 0x00FFFF00); */
/* 			y++; */
/* 		} */
/* 		a++; */
/* 		while (x > a) */
/* 		{ */
/* 			mlx_pixel_put(mlx, win, x, y, 0x0000FF00); */
/* 			x--; */
/* 		} */
/* 		a++; */
/* 		while (y > a) */
/* 		{ */
/* 			mlx_pixel_put(mlx, win, x, y, 0x0000FFFF); */
/* 			y--; */
/* 		} */
/* 		a++; */
/* 	} */
	if ((mlx_key_hook(win, my_key_func, 0)) == 0)
		return (0);
	mlx_loop(mlx);
	return (0);
}
