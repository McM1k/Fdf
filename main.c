/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 18:54:15 by gboudrie          #+#    #+#             */
/*   Updated: 2016/03/17 17:21:20 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "mlx.h"
#include "fdf.h"

int		main(int ac, char **av)
{
	int		i;
	int		j;
	int		fd;
	int		**tab;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		tab = reader(fd, tab);
		j = 0;
		while (tab[j])
		{
			i = 0;
			while (i++ <= *tab[j])
			{
				ft_putnbr(tab[j][i]);
				if (tab[j][i] < 10)
					ft_putchar(' ');
				ft_putchar(' ');
			}
			ft_putendl("");
			j++;
		}
	}

/* 	void	*mlx; */
/* 	void	*win; */
/* 	int		x; */
/* 	int		y; */
	
/* 	mlx = mlx_init(); */
/* 	win = mlx_new_window(mlx, 400, 400, "poulet"); */
/* 	x = 50; */
/* 	while (x < 350) */
/* 	{ */
/* 		mlx_pixel_put(mlx, win, x, x, 0x00FF0000); */
/* 		x++; */
/* 	} */
/* 	y = 50; */
/* 	while (y < 350) */
/* 	{ */
/* 		mlx_pixel_put(mlx, win, x, y, 0x00FF0000); */
/* 		y++; */
/* 		x--; */
/* 	} */
/* 	mlx_loop(mlx); */
	return (0);
}
