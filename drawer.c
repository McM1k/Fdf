/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 17:37:25 by gboudrie          #+#    #+#             */
/*   Updated: 2016/04/26 20:59:12 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_dot				convert(int x, int y, int z, t_dot dot)
{
	int		wide_x;
	int		wide_y;
	double	decal_x;
	double	decal_y;
	double	height;

	wide_x = 4 ;
	wide_y = 3 ;
	decal_x = 0.4 ;
	decal_y = 0.3 ;
	height = 0.3 ;
	dot.x = (x * wide_x - height * z) + SIZE_X / 20 - decal_x * y;
	dot.y = (y * wide_y - (height / 2) * z) + SIZE_Y / 15 - decal_y * x;
	dot.color = (z > 0 ? 0x0000FF00 : 0xD0888888);
	return (dot);
}

void				img_addr(t_env env, int x, int y, int color)
{
	if (!(x > env.siz - 1 || x < 0 || y < 0
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

static int			color(t_dot a, t_dot b, t_dot tmp)
{
	double			diff;
	unsigned char	*ptra;
	unsigned char	*ptrb;
	unsigned char	*ptr;
	int				res;

	diff = (b.x - a.x > b.y - a.y ?
			(double)(b.x - a.x) / (double)(b.x - a.x + tmp.x) + 1 :
			(double)(b.y - a.y) / (double)(b.y - a.y + tmp.y) + 1);
	if (a.color == b.color || diff == 0)
		return (a.color);
	ptr = (unsigned char *)&res;
	ptra = (unsigned char *)&b.color;
	ptrb = (unsigned char *)&a.color;
	ptr[0] = (ptrb[0] - ptra[0]) * diff;
	ptr[1] = (ptrb[1] - ptra[1]) * diff;
	ptr[2] = (ptrb[2] - ptra[2]) * diff;
	ptr[3] = (ptrb[3] - ptra[3]) * diff;
	return (res);
}

void				segment(t_env env, t_dot a, t_dot b)
{
	t_dot	tmp;
	double	div;

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
				img_addr(env, a.x + tmp.x, a.y + tmp.y, color(a, b, tmp));
		}
}

