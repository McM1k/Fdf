/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   reader.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gboudrie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/14 19:39:22 by gboudrie          #+#    #+#             */
/*   Updated: 2016/03/15 19:16:01 by gboudrie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"

static *int		separator(char *str)
{
	int		i;
	int		j;
	int		*line;
	int		*ptr;

	i = 0;
	j = 0;
	ptr = (*int)ft_memalloc(2 * ft_strlen(str));
	while (str[i])
	{
		if (ft_isdigit(str[i]) == 1)
		{
			ptr[j] = ft_atoi(&str[i]);
			j++;
			while (ft_isdigit(str[i]) == 1)
				i++;
		}
		if (str[i])
			i++;
	}
	line = (*int)ft_memalloc(4 * (i = j) + 4);
	while (j-- >= 0)
		line[j + 1] = ptr[j];
	ft_memdel(&ptr);
	return (line[0] = i);
}

int				**reader(int const fd, int **tab)
{
	char	*str;
	int		i;
	int		gnl;

	i = 0;
	while ((gnl = get_next_line(fd, *str)) == 1)
	{
		tab[i] = separator(str);
		i++;
	}
	if (gnl == 0)
	{
		tab[i] = NULL;
		return (tab)
	}
	else
		return (NULL);
}
