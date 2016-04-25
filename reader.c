/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 19:39:22 by gboudrie          #+#    #+#             */
/*   Updated: 2016/04/13 18:04:33 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

static int		*separator(char *str, int *tab)
{
	int		i;
	int		j;
	char	**tmp;

	tmp = ft_strsplit(str, ' ');
	i = 0;
	while (tmp[i])
		i++;
	tab = ft_memalloc((i + 1) * 4);
	j = 0;
	while (j < i)
	{
		tab[j + 1] = ft_atoi(tmp[j]);
		j++;
	}
	tab[0] = i;
	ft_tabdel((void ***)&tmp);
	return (tab);
}

int				**reader(int const fd, int **tab)
{
	char	*str;
	int		i;
	int		gnl;
	int		**ptr;
	int		j;

	i = 0;
	tab = NULL;
	while ((gnl = get_next_line(fd, &str)) == 1)
	{
		ptr = (int **)ft_memalloc(sizeof(int *) * (i + 2));
		ptr[i + 1] = NULL;
		j = 0;
		while (tab && tab[j])
		{
			ptr[j] = tab[j];
			j++;
		}
		ft_memdel((void **)&tab);
		tab = ptr;
		tab[i] = separator(str, tab[i]);
		i++;
	}
	return (gnl == 0 ? tab : NULL);
}
