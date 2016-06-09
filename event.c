/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   event.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/06/07 15:21:20 by gboudrie          #+#    #+#             */
/*   Updated: 2016/06/08 15:40:39 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void		events(int keycode, t_env *env)
{
	if (keycode == 53)
		ft_quit(env, 0);
	if (keycode == 123 || keycode == 124)
		env->x_decal += (keycode == 123 ? -10 : 10);
	if (keycode == 125 || keycode == 126)
		env->y_decal += (keycode == 125 ? 10 : -10);
	if (keycode == 86 || keycode == 88)
		env->y_rot += (keycode == 88 ? 1 : -1);
	if (keycode == 91 || keycode == 87)
		env->x_rot += (keycode == 91 ? 1 : -1);
	if (keycode == 89 || keycode == 92)
		env->z_rot += (keycode == 92 ? 1 : -1);
	if (keycode == 75 || keycode == 67)
		env->height += (keycode == 67 ? 0.1 : -0.1);
	if (keycode == 78 || keycode == 69)
	{
		env->zoom += (keycode == 69 ? 0.2 : -0.2);
		if (env->zoom <= 0.2)
			env->zoom = 0.2;
	}
}

void		ft_quit(t_env *env, int param)
{
	if (param == 0)
		ft_tabdel((void ***)&(env->mat));
	if (param == 1)
	{
		ft_putendl_fd("/!\\ --- Not enough parameters --- /!\\", 2);
		exit(0);
	}
	if (param == 2)
		ft_putendl_fd("/!\\ --- Malloc or initialisation error --- /!\\", 2);
	ft_putendl("Closing program.");
	exit(0);
}
