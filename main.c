/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 18:54:15 by gboudrie          #+#    #+#             */
/*   Updated: 2016/05/18 17:49:22 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

int		my_key_func(int keycode, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	if (keycode == 53)
		ft_quit(env);
	if (keycode == 123 || keycode == 124) //gauche-droite
		env->x_decal += (keycode == 123 ? -10 : 10);
	if (keycode == 125 || keycode == 126) //haut-bas
		env->y_decal += (keycode == 125 ? 10 : -10);
	if (keycode == 86 || keycode == 88) // X-axis
		env->x_rot += (keycode == 88 ? 1 : -1);
	if (keycode == 91 || keycode == 87) // Y-axis
		env->y_rot += (keycode == 91 ? 1 : -1);
	if (keycode == 89 || keycode == 92) // Z-axis
		env->z_rot += (keycode == 92 ? 1 : -1);
	if (keycode == 75 || keycode == 67) // height
		env->height += (keycode == 67 ? 0.1 : -0.1);
	if (keycode == 78 || keycode == 69) //zoom
	{
		env->zoom += (keycode == 69 ? 0.2 : -0.2);
		if (env->zoom <= 0.2)
			env->zoom = 0.2;
	}
	ft_bzero(env->img, SIZE_X * SIZE_Y * 4);
	drawer(*env);
	mlx_put_image_to_window(env->mlx, env->win, env->ig, 0, 0);
	return (1);
}

void	ft_quit(t_env *env)
{
	if (env->mat)
		ft_tabdel((void ***)&(env->mat));
	ft_putendl("Fermeture du programme.");
	exit(0);
}

void	init(t_env *env)
{
	env->x_decal = 0;
	env->y_decal = 0;
	env->zoom = 3;
	env->x_rot = 0;
	env->y_rot = 0;
	env->z_rot = 0;
	env->height = 0.1;
	env->mat = ft_mat_id(3);
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
		init(&env);
		drawer(env);
		mlx_put_image_to_window(env.mlx, env.win, env.ig, 0, 0);
	}
	mlx_hook(env.win, 2, 0, my_key_func, &env);
	mlx_loop(env.mlx);
	return (0);
}
