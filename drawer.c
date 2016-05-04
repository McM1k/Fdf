/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawer.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/15 17:37:25 by gboudrie          #+#    #+#             */
/*   Updated: 2016/05/04 23:44:54 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_dot				convert(int x, int y, int z, t_env env)
{
	t_dot	dot;
	int		wide_x;//
	int		wide_y;//
	double	decal_x;//
	double	decal_y;//
	double	height;//

	wide_x = 4 *20;//
	wide_y = 3 *20;//
	decal_x = 0.4 *20;//
	decal_y = 0.3 *20;//
	height = 0.1 *20;//
	dot.x = ((x * wide_x - height * z) + SIZE_X / 20 - decal_x * y) * env.zoom;
	dot.y = ((y * wide_y - (height / 2) * z) + SIZE_Y / 10 - decal_y * x) * env.zoom;
	dot.x += env.x_decal;
	dot.y += env.y_decal;
	dot.color = (z > 0 ? 0x0000FF00 : 0x00FF00FF);
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

	diff = (b.x - a.x > b.y - a.y ?
			(double)(tmp.x) / (double)(b.x - a.x) :
			(double)(tmp.y) / (double)(b.y - a.y));
	if (a.color == b.color || diff == 0)
		return (b.color);
	ptr = (unsigned char *)&res;
	pa = (unsigned char *)&b.color;
	pb = (unsigned char *)&a.color;
	ptr[0] = (pa[0] < pb[0] ? (pb[0] - pa[0]) * diff : (pa[0] - pb[0]) * diff);
	ptr[1] = (pa[3] < pb[1] ? (pb[1] - pa[1]) * diff : (pa[1] - pb[1]) * diff);
	ptr[2] = (pa[2] < pb[2] ? (pb[2] - pa[2]) * diff : (pa[2] - pb[2]) * diff);
	ptr[3] = (pa[1] < pb[3] ? (pb[3] - pa[3]) * diff : (pa[3] - pb[3]) * diff);

	//ptr[0] = ((pb[0] - pa[0]) * diff) + (pa[0] < pb[0] ? pb[0] : pa[0]);
	//ptr[1] = ((pb[1] - pa[1]) * diff) + (pa[1] < pb[1] ? pb[1] : pa[1]);
	//ptr[2] = ((pb[2] - pa[2]) * diff) + (pa[2] < pb[2] ? pb[2] : pa[2]);
	//ptr[3] = ((pb[3] - pa[3]) * diff) + (pa[3] < pb[3] ? pb[3] : pa[3]);
/*	ft_putnbr(pb[0]);
	ft_putchar('|');
	ft_putnbr(pb[1]);
	ft_putchar('|');
	ft_putnbr(pb[2]);
	ft_putchar('|');
	ft_putnbr(pb[3]);
	ft_putchar('-');
	ft_putnbr(pa[0]);
	ft_putchar('|');
	ft_putnbr(pa[1]);
	ft_putchar('|');
	ft_putnbr(pa[2]);
	ft_putchar('|');
	ft_putnbr(pa[3]);
	ft_putchar('*');
	ft_putnbr(diff*100);
	ft_putchar('=');
	ft_putnbr(ptr[0]);
	ft_putchar('|');
	ft_putnbr(ptr[1]);
	ft_putchar('|');
	ft_putnbr(ptr[2]);
	ft_putchar('|');
	ft_putnbr(ptr[3]);
	ft_putchar('\n');
*/	return (res);
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
				img_addr(env, a.x + tmp.x, a.y + tmp.y, b.color);
		}
}

