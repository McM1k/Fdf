/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 17:37:25 by gboudrie          #+#    #+#             */
/*   Updated: 2016/04/08 18:27:44 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_dot				convert(int x, int y, int z, t_dot dot)
{
	dot.x = ((x + 0.7 * z) * 5) + 40;
	dot.y = ((y + (0.7/2) * z) * 6) + 40;
	dot.color = (z > 9 ? 0x8800FF00: 0x00888800);
	return (dot);
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
	int		x;
	int		y;
	double	div;

	x = 0;
	y = 0;
	(a.x > b.x ? ft_swap(&a.y, &b.y) : (void)0);
	(a.x > b.x ? ft_swap(&a.x, &b.x) : (void)0);
	div = (double)(b.y - a.y) / (double)(b.x - a.x);
	if (div >= -1 && div <= 1)
	{
		while (a.x + x <= b.x)
		{
			ft_memcpy(&env.img[(env.siz * a.y+y) + a.x+x] , &a.color, 4);
			x++;
			y = x * div;
		}
	}
	else
	{
		while (a.y + y != b.y)
		{
			ft_memcpy(&env.img[(env.siz * a.y+y) + a.x+x] , &a.color, 4);
			y = (a.y < b.y ? y + 1 : y - 1);
			x = y / div;
			if (a.y + y == b.y)
				ft_memcpy(&env.img[(env.siz * a.y + y) + a.x + x] , &a.color, 4);
		}
	}
}

/*catheline fleurs, 12 place jean mermoz*/
