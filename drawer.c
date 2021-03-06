/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 17:37:25 by gboudrie          #+#    #+#             */
/*   Updated: 2016/06/08 16:40:58 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_dot				convert(int x, int y, int z, t_env env)
{
	t_dot	dot;
	double	tmp_z;

	dot.color = (z > 0 ? 0x00D0FF88 : 0x00006090);
	if (z > 1)
		dot.color = 0x0000E000;
	if (z > 10)
		dot.color = 0x00229920;
	if (z > 45)
		dot.color = 0x00803008;
	if (z > 70)
		dot.color = 0x00EEEEEE;
	x = x * env.zoom;
	y = y * env.zoom;
	z = z * env.zoom * env.height;
	dot.x = (double)(env.mat[0][0] * x + env.mat[0][1] * y + env.mat[0][2] * z);
	dot.y = (double)(env.mat[1][0] * x + env.mat[1][1] * y + env.mat[1][2] * z);
	tmp_z = (double)(env.mat[2][0] * x + env.mat[2][1] * y + env.mat[2][2] * z);
	dot.x = dot.x - (double)(0.75 * tmp_z) + SIZE_X / 20;
	dot.y = dot.y - (double)((0.75 / 2) * tmp_z) + SIZE_Y / 10;
	dot.x += env.x_decal;
	dot.y += env.y_decal;
	return (dot);
}

void				img_addr(t_env env, int x, int y, int color)
{
	if (!(x > env.siz - 1 || x <= 0 || y <= 0
		|| x > SIZE_X - 1 || y > SIZE_Y - 1))
		ft_memcpy(&env.img[(x - 1) * 4 + (y - 1) * env.siz], &color, 4);
}

void				drawer(t_env env)
{
	int		i;
	int		j;
	t_dot	a;
	t_dot	b;

	i = 0;
	while (env.tab[i++])
	{
		j = 0;
		while (++j <= env.tab[i - 1][0])
		{
			if (j != env.tab[i - 1][0])
			{
				a = convert(j, i - 1, env.tab[i - 1][j], env);
				b = convert(j + 1, i - 1, env.tab[i - 1][j + 1], env);
				segment(env, a, b);
			}
			if (env.tab[i] != NULL)
			{
				a = convert(j, i - 1, env.tab[i - 1][j], env);
				b = convert(j, i, env.tab[i][j], env);
				segment(env, a, b);
			}
		}
	}
}
