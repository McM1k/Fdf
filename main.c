/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 18:54:15 by gboudrie          #+#    #+#             */
/*   Updated: 2016/06/07 23:17:34 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		my_key_func(int keycode, void *param)
{
	t_env	*env;

	env = (t_env *)param;
	events(keycode, env);
	ft_bzero(env->img, SIZE_X * SIZE_Y * 4);
	if (keycode >= 86 && keycode <= 92 && keycode != 90)
		rotate(env);
	drawer(*env);
	mlx_put_image_to_window(env->mlx, env->win, env->ig, 0, 0);
	return (1);
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
	drawer(*env);
	mlx_put_image_to_window(env->mlx, env->win, env->ig, 0, 0);
}

int		main(int ac, char **av)
{
	int		fd;
	t_env	env;

	if (ac >= 2)
	{
		if (strstr(av[1], "/dev/") != NULL)
		{
			ft_putendl("Fdf was scared by /dev and ran away.");
			return (0);
		}
		fd = open(av[1], O_RDONLY);
		env.tab = NULL;
		if ((env.mlx = mlx_init()) == NULL ||
			(env.win = mlx_new_window(env.mlx, SIZE_X, SIZE_Y, "FdF")) == NULL
			|| (env.ig = mlx_new_image(env.mlx, SIZE_X, SIZE_Y)) == NULL ||
			(env.tab = reader(fd, av[1], env.tab)) == NULL)
			ft_quit(&env, 2);
		env.img = mlx_get_data_addr(env.ig, &(env.bit), &(env.siz), &(env.end));
		init(&env);
	}
	else
		ft_quit(&env, 1);
	mlx_hook(env.win, 2, 0, my_key_func, &env);
	mlx_loop(env.mlx);
	return (0);
}
