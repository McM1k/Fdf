/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 17:37:25 by gboudrie          #+#    #+#             */
/*   Updated: 2016/05/25 15:16:00 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_dot				convert(int x, int y, int z, t_env env)
{
	t_dot	dot;
	double	tmp_z;

	x = x * env.zoom;
	y = y * env.zoom;
	z = z * env.zoom * env.height;
	dot.x = (double)(env.mat[0][0] * x + env.mat[0][1] * y + env.mat[0][2] * z);
	dot.y = (double)(env.mat[1][0] * x + env.mat[1][1] * y + env.mat[1][2] * z);
	tmp_z = (double)(env.mat[2][0] * x + env.mat[2][1] * y + env.mat[2][2] * z);
	dot.x = dot.x - (double)(0.8 * tmp_z) + SIZE_X / 20;
	dot.y = dot.y - (double)((0.8 / 2) * tmp_z) + SIZE_Y / 10;
	dot.x += env.x_decal;
	dot.y += env.y_decal;
	dot.color = (z > 0 ? 0x0000FF00 : 0x00B0D0);
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
	while (env.tab[i])
	{
		j = 1;
		while (j <= env.tab[i][0])
		{
			if (j != env.tab[i][0])
			{
				a = convert(j, i, env.tab[i][j], env);
				b = convert(j + 1, i, env.tab[i][j + 1], env);
				segment(env, a, b);
			}
			if (env.tab[i + 1] != NULL)
			{
				a = convert(j, i, env.tab[i][j], env);
				b = convert(j, i + 1, env.tab[i + 1][j], env);
				segment(env, a, b);
			}
			j++;
		}
		i++;
	}
}

static int			color(t_dot a, t_dot b, t_dot tmp)
{
	double			diff;
	unsigned char	*pa;
	unsigned char	*pb;
	unsigned char	*ptr;
	int				res;

	if (a.color == b.color)
		return (b.color);
	diff = (ft_abs(b.x - a.x) > ft_abs(b.y - a.y) ?
			(double)(tmp.x) / (double)(b.x - a.x) :
			(double)(tmp.y) / (double)(b.y - a.y));
	ptr = (unsigned char *)&res;
	pa = (unsigned char *)&a.color;
	pb = (unsigned char *)&b.color;
	ptr[0] = (pa[0] < pb[0] ? pa[0] + (pb[0] - pa[0]) * diff :
			  pb[0] + (pa[0] - pb[0]) * (1 - diff));
	ptr[1] = (pa[3] < pb[1] ? pa[1] + (pb[1] - pa[1]) * diff :
			  pb[1] + (pa[1] - pb[1]) * (1 - diff));
	ptr[2] = (pa[2] < pb[2] ? pa[2] + (pb[2] - pa[2]) * diff :
			  pb[2] + (pa[2] - pb[2]) * (1 - diff));
	ptr[3] = (pa[1] < pb[3] ? pa[3] + (pb[3] - pa[3]) * diff :
			  pb[3] + (pa[3] - pb[3]) * (1 - diff));
	return (res);
}

void				segment(t_env env, t_dot a, t_dot b)
{
	t_dot	tmp;
	double	div;

	if ((a.x > SIZE_X && b.x > SIZE_X) || (a.x <= 0 && b.x <= 0) ||
		(a.y > SIZE_Y && b.y > SIZE_Y) || (a.y <= 0 && b.y <= 0))
		return ;
	tmp.x = 0;
	tmp.y = 0;
	(a.x > b.x ? ft_swap(&a.color, &b.color) : (void)0);
	(a.x > b.x ? ft_swap(&a.y, &b.y) : (void)0);
	(a.x > b.x ? ft_swap(&a.x, &b.x) : (void)0);
	div = (double)(b.y - a.y) / (double)(b.x - a.x);
	if (div >= -1 && div <= 1)
		while (a.x + tmp.x <= b.x)
		{
			img_addr(env, a.x + tmp.x, a.y + tmp.y, color(a, b, tmp));
			tmp.x++;
			tmp.y =  tmp.x * div;
		}
	else
		while (a.y + tmp.y != b.y)
		{
			img_addr(env, a.x + tmp.x, a.y + tmp.y, color(a, b, tmp));
			tmp.y = (a.y < b.y ? tmp.y + 1 : tmp.y - 1);
			tmp.x = tmp.y / div;
			if (a.y + tmp.y == b.y)
				img_addr(env, a.x + tmp.x, a.y + tmp.y, b.color);
		}
}
