/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 18:54:15 by gboudrie          #+#    #+#             */
/*   Updated: 2016/04/08 18:33:19 by gboudrie         ###   ########.fr       */
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
	int		fd;
	t_env	env;

	if (ac == 2)
	{
		fd = open(av[1], O_RDONLY);
		if ((env.mlx = mlx_init()) == NULL ||
			(env.win = mlx_new_window(env.mlx, SIZE_X, SIZE_Y, "FdF")) == NULL
			|| (env.ig = mlx_new_image(env.mlx, SIZE_X, SIZE_Y)) == NULL ||
			(env.tab = reader(fd, (env.tab = NULL))))
			return (0);
		close(fd);
		env.img = mlx_get_data_addr(env.ig, &(env.bit), &(env.siz), &(env.end));
		drawer(env);
		mlx_put_image_to_window(env.mlx, env.win, env.ig, 0, 0);
	}

	if ((mlx_key_hook(env.win, my_key_func, 0)) == 0)
		return (0);
	mlx_loop(env.mlx);
	return (0);
}
