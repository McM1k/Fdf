/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 18:54:15 by gboudrie          #+#    #+#             */
/*   Updated: 2016/05/04 23:53:46 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

int		my_key_func(int keycode, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	if (keycode == 53)
		ft_quit();
	if (keycode == 123 || keycode == 124) //gauche-droite
		env->x_decal += (keycode == 123 ? -10 : 10);
	if (keycode == 125 || keycode == 126) //haut-bas
		env->y_decal += (keycode == 125 ? 10 : -10);
	if (keycode == 86 || keycode == 88) // X-axis
		ft_quit();
	if (keycode == 91 || keycode == 87) // Y-axis
		ft_quit();
	if (keycode == 89 || keycode == 92) // Z-axis
		ft_quit();
	if (keycode == 78 || keycode == 69) //zoom
	{
		env->zoom += (keycode == 69 ? 0.02 : -0.02);
		if (env->zoom <= 0.02)
			env->zoom = 0.02;
	}
	ft_bzero(env->img, SIZE_X * SIZE_Y * 4);
	drawer(*env);
	mlx_put_image_to_window(env->mlx, env->win, env->ig, 0, 0);
	return (1);
}

void	ft_quit()
{
	ft_putendl("Fermeture du programme.");
	exit(0);
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
			(env.tab = reader(fd, (env.tab = NULL))) == NULL)
			return (0);
		close(fd);
		env.img = mlx_get_data_addr(env.ig, &(env.bit), &(env.siz), &(env.end));
		env.x_decal = 0;
		env.y_decal = 0;
		env.zoom = 1;
		drawer(env);
		mlx_put_image_to_window(env.mlx, env.win, env.ig, 0, 0);
	}
	mlx_hook(env.win, 2, 0, my_key_func, &env);
	mlx_loop(env.mlx);
	return (0);
}
