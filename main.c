/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 18:54:15 by gboudrie          #+#    #+#             */
/*   Updated: 2016/04/04 17:43:35 by gboudrie         ###   ########.fr       */
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
			while (i < tab[j][0])
			{
				ft_putnbr(tab[j][i + 1]);
				if (tab[j][i + 1] < 10)
					ft_putchar(' ');
				ft_putchar(' ');
				i++;
			}
			ft_putendl("");
			j++;
		}
	}

/* 	void	*mlx; */
/* 	void	*win; */
/* 	if ((mlx_key_hook(win, my_key_func, 0)) == 0) */
/* 		return (0); */
/* 	mlx_loop(mlx); */
/* 	return (0); */
}
