/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 19:39:22 by gboudrie          #+#    #+#             */
/*   Updated: 2016/04/01 22:23:13 by gboudrie         ###   ########.fr       */
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
		ft_putnbr(j);
		j++;
	}
	tab[0] = i;
	ft_putendl("soi1");
	ft_tabdel((void ***)&tmp);
	ft_putendl("soi2");
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
		ft_putendl("lel1");
		ft_tabdel((void ***)&tab);
		ft_putendl("lel2");
		tab = ptr;
		tab[i] = separator(str, tab[i]);
		i++;
	}
	if (gnl == 0)
		return (tab);
	else
		return (NULL);
}
