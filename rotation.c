/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 15:51:37 by gboudrie          #+#    #+#             */
/*   Updated: 2016/06/07 14:21:12 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <math.h>

double			**mat_product(double **m1, double **m2)
{
	double	tmp[3][3];
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i++ < 3)
	{
		j = 0;
		while (j++ < 3)
		{
			k = 0;
			tmp[i - 1][j - 1] = 0;
			while (k++ < 3)
				tmp[i - 1][j - 1] += m1[i - 1][k - 1] * m2[k - 1][j - 1];
		}
	}
	i = 0;
	while (i++ < 3)
	{
		j = 0;
		while (j++ < 3)
			m1[i - 1][j - 1] = tmp[i - 1][j - 1];
	}
	return (m1);
}

static void		rotate_x(t_env *e)
{
	double		**tmp;

	tmp = ft_mat_id(3);
	tmp[1][1] = cos(e->x_rot * 0.0174533);
	tmp[1][2] = sin(e->x_rot * 0.0174533);
	tmp[2][1] = -sin(e->x_rot * 0.0174533);
	tmp[2][2] = cos(e->x_rot * 0.0174533);
	e->mat = mat_product(e->mat, tmp);
	ft_tabdel((void ***)&tmp);
}

static void		rotate_y(t_env *e)
{
	double		**tmp;

	tmp = ft_mat_id(3);
	tmp[0][0] = cos(e->y_rot * 0.0174533);
	tmp[0][2] = sin(e->y_rot * 0.0174533);
	tmp[2][0] = -sin(e->y_rot * 0.0174533);
	tmp[2][2] = cos(e->y_rot * 0.0174533);
	e->mat = mat_product(e->mat, tmp);
	ft_tabdel((void ***)&tmp);
}

static void		rotate_z(t_env *e)
{
	double		**tmp;

	tmp = ft_mat_id(3);
	tmp[0][0] = cos(e->z_rot * 0.0174533);
	tmp[0][1] = -sin(e->z_rot * 0.0174533);
	tmp[1][0] = sin(e->z_rot * 0.0174533);
	tmp[1][1] = cos(e->z_rot * 0.0174533);
	e->mat = mat_product(e->mat, tmp);
	ft_tabdel((void ***)&tmp);
}

void			rotate(t_env *e)
{
	ft_tabdel((void ***)&(e->mat));
	e->mat = ft_mat_id(3);
	rotate_x(e);
	rotate_y(e);
	rotate_z(e);
}
