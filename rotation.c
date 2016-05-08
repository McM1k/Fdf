/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/05/08 15:51:37 by gboudrie          #+#    #+#             */
/*   Updated: 2016/05/08 20:08:12 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void		mat_product(double **m1, double **m2)
{
	double	tmp[3][3];
	int		i;
	int		j;
	int		k;

	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			k = 0;
			tmp[i][j] = 0;
			while (k < 3)
			{
				tmp[i][j] += m1[i][k] * m2[k][j];
				k++;
			}
			j++;
		}
		i++;
	}
	i = 0;
	while (i < 3)
	{
		j = 0;
		while (j < 3)
		{
			m1[i][j] = tmp[i][j];
			j++;
		}
		i++;
	}
}
