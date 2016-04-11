/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 17:37:25 by gboudrie          #+#    #+#             */
/*   Updated: 2016/04/11 19:57:36 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_dot				convert(int x, int y, int z, t_dot dot)
{
	dot.x = (x * 4 - 0.3 * z) + SIZE_X / 10 - 0.4 * y;
	dot.y = (y * 3 - (0.3 / 2) * z) + SIZE_Y / 5 - 0.8 * x;
	dot.color = (z > 0 ? 0x0008FF08 : 0x000088F8);
	return (dot);
}

void				img_addr(t_env env, int x, int y, int color)
{
	if (!(x > env.siz || x < 0 || y < 0
		  || x > SIZE_X || y > SIZE_Y))
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
				a = convert(j, i, env.tab[i][j], a);
				b = convert(j + 1, i, env.tab[i][j + 1], b);
				segment(env, a, b);
			}
			if (env.tab[i + 1] != NULL)
			{
				a = convert(j, i, env.tab[i][j], a);
				b = convert(j, i + 1, env.tab[i + 1][j], b);
				segment(env, a, b);
			}
			j++;
		}
		i++;
	}
}

void				segment(t_env env, t_dot a, t_dot b)
{
	t_dot	tmp;
	double	div;

	tmp.x = 0;
	tmp.y = 0;
	(a.x > b.x ? ft_swap(&a.y, &b.y) : (void)0);
	(a.x > b.x ? ft_swap(&a.x, &b.x) : (void)0);
	div = (double)(b.y - a.y) / (double)(b.x - a.x);
	if (div >= -1 && div <= 1)
		while (a.x + tmp.x <= b.x)
		{
			img_addr(env, a.x + tmp.x, a.y + a.color);
			tmp.x++;
			tmp.y =  tmp.x * div;
		}
	else
		while (a.y + tmp.y != b.y)
		{
			img_addr(env, a.x + tmp.x, a.y + tmp.y, a.color);
			tmp.y = (a.y < b.y ? tmp.y + 1 : tmp.y - 1);
			tmp.x = tmp.y / div;
			if (a.y + tmp.y == b.y)
				img_addr(env, a.x + tmp.x, a.y + tmp.y, a.color);
		}
}

